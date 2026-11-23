#include "smartwatch.h"

#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_log.h"
#include "lvgl.h"
#include "ui.h"

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace {
constexpr int LCD_WIDTH = 1280;
constexpr int LCD_HEIGHT = 400;

lv_disp_t *display;
esp_lcd_panel_handle_t panel;

void flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *pixels) {
    esp_lcd_panel_draw_bitmap(panel, area->x1, area->y1, area->x2 + 1, area->y2 + 1, pixels);
    lv_disp_flush_ready(disp);
}

void touch_read(lv_indev_drv_t *, lv_indev_data_t *data) {
    uint16_t x = 0;
    uint16_t y = 0;
    if (smartwatch::touch_read(x, y)) {
        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = x;
        data->point.y = y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void ui_task(void *) {
    for (;;) {
        lv_tick_inc(5);
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

} // namespace

bool init_display() {
    esp_lcd_rgb_panel_config_t config{};
    config.clk_src = LCD_CLK_SRC_DEFAULT;
    config.timings.pclk_hz = 35000000;
    config.timings.h_res = LCD_WIDTH;
    config.timings.v_res = LCD_HEIGHT;
    config.timings.hsync_pulse_width = 40;
    config.timings.hsync_back_porch = 40;
    config.timings.hsync_front_porch = 40;
    config.timings.vsync_pulse_width = 3;
    config.timings.vsync_back_porch = 10;
    config.timings.vsync_front_porch = 10;
    config.timings.flags.hsync_idle_low = true;
    config.timings.flags.vsync_idle_low = true;
    config.data_width = 16;
    config.num_fbs = 1;
    config.in_color_format = LCD_COLOR_FMT_RGB565;
    config.out_color_format = LCD_COLOR_FMT_RGB565;
    config.flags.fb_in_psram = 1;
    config.bounce_buffer_size_px = 0;
    config.hsync_gpio_num = GPIO_NUM_39;
    config.vsync_gpio_num = GPIO_NUM_40;
    config.pclk_gpio_num = GPIO_NUM_38;
    config.de_gpio_num = GPIO_NUM_41;
    config.disp_gpio_num = GPIO_NUM_NC;
    config.data_gpio_nums[0] = GPIO_NUM_16;
    config.data_gpio_nums[1] = GPIO_NUM_17;
    config.data_gpio_nums[2] = GPIO_NUM_18;
    config.data_gpio_nums[3] = GPIO_NUM_8;
    config.data_gpio_nums[4] = GPIO_NUM_9;
    config.data_gpio_nums[5] = GPIO_NUM_10;
    config.data_gpio_nums[6] = GPIO_NUM_11;
    config.data_gpio_nums[7] = GPIO_NUM_12;
    config.data_gpio_nums[8] = GPIO_NUM_13;
    config.data_gpio_nums[9] = GPIO_NUM_14;
    config.data_gpio_nums[10] = GPIO_NUM_21;
    config.data_gpio_nums[11] = GPIO_NUM_4;
    config.data_gpio_nums[12] = GPIO_NUM_5;
    config.data_gpio_nums[13] = GPIO_NUM_6;
    config.data_gpio_nums[14] = GPIO_NUM_7;
    config.data_gpio_nums[15] = GPIO_NUM_15;

    if (esp_lcd_new_rgb_panel(&config, &panel) != ESP_OK) return false;
    if (esp_lcd_panel_reset(panel) != ESP_OK) return false;
    if (esp_lcd_panel_init(panel) != ESP_OK) return false;

    lv_init();
    static lv_color_t buffer1[LCD_WIDTH * 40];
    lv_disp_draw_buf_t *draw_buf = static_cast<lv_disp_draw_buf_t *>(
        lv_mem_alloc(sizeof(lv_disp_draw_buf_t)));
    lv_disp_draw_buf_init(draw_buf, buffer1, nullptr, LCD_WIDTH * 40);

    lv_disp_drv_t *driver = static_cast<lv_disp_drv_t *>(lv_mem_alloc(sizeof(lv_disp_drv_t)));
    lv_disp_drv_init(driver);
    driver->hor_res = LCD_WIDTH;
    driver->ver_res = LCD_HEIGHT;
    driver->flush_cb = flush;
    driver->draw_buf = draw_buf;
    display = lv_disp_drv_register(driver);

    lv_indev_drv_t touch_driver{};
    lv_indev_drv_init(&touch_driver);
    touch_driver.type = LV_INDEV_TYPE_POINTER;
    touch_driver.read_cb = touch_read;
    lv_indev_drv_register(&touch_driver);

    ui_init();
    xTaskCreatePinnedToCore(ui_task, "lvgl_ui", 8192, nullptr, 5, nullptr, 1);
    return true;
}
