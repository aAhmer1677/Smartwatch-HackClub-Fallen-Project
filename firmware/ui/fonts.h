#ifndef EEZ_LVGL_UI_FONTS_H
#define EEZ_LVGL_UI_FONTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_font_t ui_font_montserrat_extra_light_128;
extern const lv_font_t ui_font_montserrat_black_64;
extern const lv_font_t ui_font_montserrat_black_48;
extern const lv_font_t ui_font_montserrat_black_32;
extern const lv_font_t ui_font_montserrat_light_16;
extern const lv_font_t ui_font_montserrat_regular_20;

#ifndef EXT_FONT_DESC_T
#define EXT_FONT_DESC_T
typedef struct _ext_font_desc_t {
    const char *name;
    const void *font_ptr;
} ext_font_desc_t;
#endif

extern ext_font_desc_t fonts[];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_FONTS_H*/