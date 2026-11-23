#include "smartwatch.h"

#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <atomic>
#include <cstring>

namespace smartwatch {

namespace {
constexpr gpio_num_t IMU_SCL = GPIO_NUM_43;
constexpr gpio_num_t IMU_SDA = GPIO_NUM_44;
constexpr gpio_num_t IMU_INT = GPIO_NUM_42;
constexpr gpio_num_t ENCODER_A = GPIO_NUM_2;
constexpr gpio_num_t ENCODER_B = GPIO_NUM_3;
constexpr gpio_num_t ENCODER_SW = GPIO_NUM_45;
constexpr gpio_num_t MOTOR = GPIO_NUM_46;
constexpr gpio_num_t BATTERY = GPIO_NUM_1;

i2c_master_bus_handle_t i2c_bus = nullptr;
i2c_master_dev_handle_t imu = nullptr;
i2c_master_dev_handle_t touch = nullptr;
adc_oneshot_unit_handle_t adc = nullptr;
std::atomic<int32_t> encoder_delta{0};
State state{};

constexpr uint8_t REG_BANK_SEL = 0x7F;
constexpr uint8_t WHO_AM_I = 0x00;
constexpr uint8_t PWR_MGMT_1 = 0x06;
constexpr uint8_t PWR_MGMT_2 = 0x07;
constexpr uint8_t ACCEL_XOUT_H = 0x2D;
constexpr uint8_t GYRO_XOUT_H = 0x33;

bool imu_write(uint8_t reg, uint8_t value) {
    uint8_t data[2] = {reg, value};
    return imu && i2c_master_transmit(imu, data, sizeof(data), 100) == ESP_OK;
}

bool imu_read(uint8_t reg, uint8_t *data, size_t length) {
    return imu && i2c_master_transmit_receive(imu, &reg, 1, data, length, 100) == ESP_OK;
}

void IRAM_ATTR encoder_isr(void *) {
    static uint8_t previous = 0;
    uint8_t a = gpio_get_level(ENCODER_A);
    uint8_t b = gpio_get_level(ENCODER_B);
    uint8_t current = (a << 1) | b;
    if (current == ((previous + 1) & 3)) {
        encoder_delta.fetch_add(1);
    } else if (current == ((previous - 1) & 3)) {
        encoder_delta.fetch_sub(1);
    }
    previous = current;
}

bool init_imu() {
    i2c_device_config_t config{};
    config.dev_addr_length = I2C_ADDR_BIT_LEN_7;
    config.device_address = 0x68;
    config.scl_speed_hz = 100000;
    if (i2c_master_bus_add_device(i2c_bus, &config, &imu) != ESP_OK) {
        return false;
    }

    imu_write(REG_BANK_SEL, 0);
    uint8_t who = 0;
    if (!imu_read(WHO_AM_I, &who, 1) || who != 0xEA) {
        return false;
    }
    imu_write(PWR_MGMT_1, 0x01);
    imu_write(PWR_MGMT_2, 0x00);
    return true;
}

void read_imu() {
    imu_write(REG_BANK_SEL, 0);
    uint8_t values[12] = {};
    if (!imu_read(ACCEL_XOUT_H, values, sizeof(values))) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        int16_t raw = static_cast<int16_t>((values[i * 2] << 8) | values[i * 2 + 1]);
        state.accel_mg[i] = raw * 2000 / 32768;
    }
    for (int i = 0; i < 3; ++i) {
        int16_t raw = static_cast<int16_t>((values[6 + i * 2] << 8) | values[7 + i * 2]);
        state.gyro_mdps[i] = raw * 250000 / 32768;
    }
}

bool read_touch(uint16_t &x, uint16_t &y) {
    if (!touch) return false;
    uint8_t count = 0;
    uint8_t reg = 0x02;
    if (i2c_master_transmit_receive(touch, &reg, 1, &count, 1, 50) != ESP_OK) return false;
    count &= 0x0F;
    if (count == 0) return false;

    uint8_t point[4] = {};
    reg = 0x03;
    if (i2c_master_transmit_receive(touch, &reg, 1, point, sizeof(point), 50) != ESP_OK) return false;
    x = ((point[0] & 0x0F) << 8) | point[1];
    y = ((point[2] & 0x0F) << 8) | point[3];
    return true;
}

} // namespace

bool init() {
    i2c_master_bus_config_t bus_config{};
    bus_config.i2c_port = I2C_NUM_0;
    bus_config.sda_io_num = IMU_SDA;
    bus_config.scl_io_num = IMU_SCL;
    bus_config.clk_source = I2C_CLK_SRC_DEFAULT;
    bus_config.glitch_ignore_cnt = 7;
    bus_config.flags.enable_internal_pullup = false;
    if (i2c_new_master_bus(&bus_config, &i2c_bus) != ESP_OK) {
        return false;
    }

    init_imu();

    i2c_device_config_t touch_config{};
    touch_config.dev_addr_length = I2C_ADDR_BIT_LEN_7;
    touch_config.device_address = 0x38;
    touch_config.scl_speed_hz = 100000;
    i2c_master_bus_add_device(i2c_bus, &touch_config, &touch);

    gpio_config_t encoder_config{};
    encoder_config.pin_bit_mask = (1ULL << ENCODER_A) | (1ULL << ENCODER_B) | (1ULL << ENCODER_SW);
    encoder_config.mode = GPIO_MODE_INPUT;
    encoder_config.pull_up_en = GPIO_PULLUP_ENABLE;
    encoder_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    encoder_config.intr_type = GPIO_INTR_ANYEDGE;
    gpio_config(&encoder_config);

    gpio_config_t motor_config{};
    motor_config.pin_bit_mask = (1ULL << MOTOR);
    motor_config.mode = GPIO_MODE_OUTPUT;
    motor_config.pull_up_en = GPIO_PULLUP_DISABLE;
    motor_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    motor_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&motor_config);
    gpio_set_level(MOTOR, 0);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(ENCODER_A, encoder_isr, nullptr);
    gpio_isr_handler_add(ENCODER_B, encoder_isr, nullptr);

    adc_oneshot_unit_init_cfg_t adc_config{};
    adc_config.unit_id = ADC_UNIT_1;
    if (adc_oneshot_new_unit(&adc_config, &adc) == ESP_OK) {
        adc_oneshot_chan_cfg_t channel{};
        channel.bitwidth = ADC_BITWIDTH_12;
        channel.atten = ADC_ATTEN_DB_12;
        adc_oneshot_config_channel(adc, ADC_CHANNEL_0, &channel);
    }
    return true;
}

void get_state(State &out) {
    read_imu();
    state.encoder_delta = encoder_delta.exchange(0);
    if (adc) {
        int raw = 0;
        if (adc_oneshot_read(adc, ADC_CHANNEL_0, &raw) == ESP_OK) {
            state.battery_mv = raw * 3300 * 2 / 4095;
        }
    }
    out = state;
}

void haptic(bool enabled) {
    gpio_set_level(MOTOR, enabled ? 1 : 0);
}

void haptic_pulse(uint32_t ms) {
    haptic(true);
    vTaskDelay(pdMS_TO_TICKS(ms));
    haptic(false);
}

bool touch_read(uint16_t &x, uint16_t &y) {
    return read_touch(x, y);
}

} // namespace smartwatch
