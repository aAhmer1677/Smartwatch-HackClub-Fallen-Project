#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_WATCH_FACE_LOCKED = 1,
    SCREEN_ID_LOADING_PAGE = 2,
    _SCREEN_ID_LAST = 2
};

typedef struct _objects_t {
    lv_obj_t *watch_face_locked;
    lv_obj_t *loading_page;
    lv_obj_t *ui_seconds_complication;
    lv_obj_t *tick_1;
    lv_obj_t *tick_2;
    lv_obj_t *tick_3;
    lv_obj_t *tick_4;
    lv_obj_t *tick_5;
    lv_obj_t *tick_6;
    lv_obj_t *tick_7;
    lv_obj_t *tick_8;
    lv_obj_t *tick_9;
    lv_obj_t *tick_10;
    lv_obj_t *tick_11;
    lv_obj_t *tick_12;
    lv_obj_t *tick_13;
    lv_obj_t *tick_14;
    lv_obj_t *tick_15;
    lv_obj_t *tick_16;
    lv_obj_t *tick_17;
    lv_obj_t *tick_18;
    lv_obj_t *tick_19;
    lv_obj_t *tick_20;
    lv_obj_t *tick_21;
    lv_obj_t *tick_22;
    lv_obj_t *tick_23;
    lv_obj_t *tick_24;
    lv_obj_t *tick_25;
    lv_obj_t *tick_26;
    lv_obj_t *tick_27;
    lv_obj_t *tick_28;
    lv_obj_t *tick_29;
    lv_obj_t *tick_30;
    lv_obj_t *tick_31;
    lv_obj_t *tick_32;
    lv_obj_t *tick_33;
    lv_obj_t *tick_34;
    lv_obj_t *tick_35;
    lv_obj_t *tick_36;
    lv_obj_t *tick_37;
    lv_obj_t *tick_38;
    lv_obj_t *tick_39;
    lv_obj_t *tick_40;
    lv_obj_t *tick_41;
    lv_obj_t *tick_42;
    lv_obj_t *tick_43;
    lv_obj_t *tick_44;
    lv_obj_t *tick_45;
    lv_obj_t *tick_46;
    lv_obj_t *tick_47;
    lv_obj_t *tick_48;
    lv_obj_t *tick_49;
    lv_obj_t *tick_50;
    lv_obj_t *tick_51;
    lv_obj_t *tick_52;
    lv_obj_t *tick_53;
    lv_obj_t *tick_54;
    lv_obj_t *tick_55;
    lv_obj_t *tick_56;
    lv_obj_t *tick_57;
    lv_obj_t *tick_58;
    lv_obj_t *tick_59;
    lv_obj_t *tick_61;
    lv_obj_t *tick_62;
    lv_obj_t *tick_63;
    lv_obj_t *tick_64;
    lv_obj_t *tick_65;
    lv_obj_t *tick_66;
    lv_obj_t *tick_67;
    lv_obj_t *tick_68;
    lv_obj_t *tick_69;
    lv_obj_t *tick_70;
    lv_obj_t *tick_71;
    lv_obj_t *tick_72;
    lv_obj_t *tick_73;
    lv_obj_t *tick_74;
    lv_obj_t *tick_75;
    lv_obj_t *tick_76;
    lv_obj_t *tick_77;
    lv_obj_t *tick_78;
    lv_obj_t *tick_79;
    lv_obj_t *tick_80;
    lv_obj_t *tick_81;
    lv_obj_t *tick_82;
    lv_obj_t *tick_83;
    lv_obj_t *tick_84;
    lv_obj_t *tick_85;
    lv_obj_t *tick_86;
    lv_obj_t *tick_87;
    lv_obj_t *tick_88;
    lv_obj_t *tick_89;
    lv_obj_t *tick_90;
    lv_obj_t *tick_91;
    lv_obj_t *tick_92;
    lv_obj_t *tick_93;
    lv_obj_t *tick_94;
    lv_obj_t *tick_95;
    lv_obj_t *tick_96;
    lv_obj_t *tick_97;
    lv_obj_t *tick_98;
    lv_obj_t *tick_99;
    lv_obj_t *tick_100;
    lv_obj_t *tick_101;
    lv_obj_t *tick_102;
    lv_obj_t *tick_103;
    lv_obj_t *tick_104;
    lv_obj_t *tick_105;
    lv_obj_t *tick_106;
    lv_obj_t *tick_107;
    lv_obj_t *tick_108;
    lv_obj_t *tick_109;
    lv_obj_t *tick_110;
    lv_obj_t *tick_111;
    lv_obj_t *tick_112;
    lv_obj_t *tick_113;
    lv_obj_t *tick_114;
    lv_obj_t *tick_115;
    lv_obj_t *tick_116;
    lv_obj_t *tick_117;
    lv_obj_t *tick_118;
    lv_obj_t *tick_119;
    lv_obj_t *ui_time_label;
    lv_obj_t *obj0;
    lv_obj_t *status_bar_time;
    lv_obj_t *logo;
} objects_t;

extern objects_t objects;

void create_screen_watch_face_locked();
void delete_screen_watch_face_locked();
void tick_screen_watch_face_locked();

void create_screen_loading_page();
void delete_screen_loading_page();
void tick_screen_loading_page();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/