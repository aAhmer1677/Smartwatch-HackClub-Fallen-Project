#include "ble_uart.h"
#include "smartwatch.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

bool init_display();

namespace {
constexpr char TAG[] = "smartwatch";

void sensor_task(void *) {
    for (;;) {
        smartwatch::State state;
        smartwatch::get_state(state);

        if (ble_uart::connected()) {
            ble_uart::txf(
                "STATUS batt=%lu mv acc=%ld,%ld,%ld enc=%ld",
                static_cast<unsigned long>(state.battery_mv),
                static_cast<long>(state.accel_mg[0]),
                static_cast<long>(state.accel_mg[1]),
                static_cast<long>(state.accel_mg[2]),
                static_cast<long>(state.encoder_delta));
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
}

extern "C" void app_main(void) {
    ESP_LOGI(TAG, "Starting minimal smartwatch firmware");

    if (!smartwatch::init()) {
        ESP_LOGE(TAG, "Hardware base initialization failed");
    }
    if (!init_display()) {
        ESP_LOGE(TAG, "RGB/HDMI display initialization failed");
    }

    ble_uart::init();
    xTaskCreatePinnedToCore(sensor_task, "sensors", 4096, nullptr, 3, nullptr, 0);
}
