#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

static const char *screen_names[] = { "watch_face_locked", "loading_page" };
static const char *object_names[] = { "watch_face_locked", "loading_page", "ui_seconds_complication", "tick_1", "tick_2", "tick_3", "tick_4", "tick_5", "tick_6", "tick_7", "tick_8", "tick_9", "tick_10", "tick_11", "tick_12", "tick_13", "tick_14", "tick_15", "tick_16", "tick_17", "tick_18", "tick_19", "tick_20", "tick_21", "tick_22", "tick_23", "tick_24", "tick_25", "tick_26", "tick_27", "tick_28", "tick_29", "tick_30", "tick_31", "tick_32", "tick_33", "tick_34", "tick_35", "tick_36", "tick_37", "tick_38", "tick_39", "tick_40", "tick_41", "tick_42", "tick_43", "tick_44", "tick_45", "tick_46", "tick_47", "tick_48", "tick_49", "tick_50", "tick_51", "tick_52", "tick_53", "tick_54", "tick_55", "tick_56", "tick_57", "tick_58", "tick_59", "tick_61", "tick_62", "tick_63", "tick_64", "tick_65", "tick_66", "tick_67", "tick_68", "tick_69", "tick_70", "tick_71", "tick_72", "tick_73", "tick_74", "tick_75", "tick_76", "tick_77", "tick_78", "tick_79", "tick_80", "tick_81", "tick_82", "tick_83", "tick_84", "tick_85", "tick_86", "tick_87", "tick_88", "tick_89", "tick_90", "tick_91", "tick_92", "tick_93", "tick_94", "tick_95", "tick_96", "tick_97", "tick_98", "tick_99", "tick_100", "tick_101", "tick_102", "tick_103", "tick_104", "tick_105", "tick_106", "tick_107", "tick_108", "tick_109", "tick_110", "tick_111", "tick_112", "tick_113", "tick_114", "tick_115", "tick_116", "tick_117", "tick_118", "tick_119", "ui_time_label", "obj0", "status_bar_time", "logo" };

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_watch_face_locked_watch_face_locked(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 2, e);
    }
}

static void event_handler_cb_loading_page_loading_page(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 2, e);
    }
}

//
// Screens
//

void create_screen_watch_face_locked() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.watch_face_locked = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1280, 400);
    lv_obj_add_event_cb(obj, event_handler_cb_watch_face_locked_watch_face_locked, LV_EVENT_ALL, flowState);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0x212121), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ui_seconds_complication
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_seconds_complication = obj;
            lv_obj_set_pos(obj, -11, -19);
            lv_obj_set_size(obj, 1291, 419);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // tick_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_1 = obj;
                    lv_obj_set_pos(obj, 845, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_outline_color(obj, lv_color_hex(0x282b30), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_2 = obj;
                    lv_obj_set_pos(obj, 864, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_3 = obj;
                    lv_obj_set_pos(obj, 884, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_4 = obj;
                    lv_obj_set_pos(obj, 903, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_5
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_5 = obj;
                    lv_obj_set_pos(obj, 923, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_6
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_6 = obj;
                    lv_obj_set_pos(obj, 942, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_7
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_7 = obj;
                    lv_obj_set_pos(obj, 961, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_8
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_8 = obj;
                    lv_obj_set_pos(obj, 981, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_9
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_9 = obj;
                    lv_obj_set_pos(obj, 1000, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_10
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_10 = obj;
                    lv_obj_set_pos(obj, 1020, 26);
                    lv_obj_set_size(obj, 32, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_11
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_11 = obj;
                    lv_obj_set_pos(obj, 1039, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_12
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_12 = obj;
                    lv_obj_set_pos(obj, 1058, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_13
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_13 = obj;
                    lv_obj_set_pos(obj, 1078, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_14
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_14 = obj;
                    lv_obj_set_pos(obj, 1097, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_15
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_15 = obj;
                    lv_obj_set_pos(obj, 1117, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_16
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_16 = obj;
                    lv_obj_set_pos(obj, 1136, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_17
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_17 = obj;
                    lv_obj_set_pos(obj, 1156, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_18
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_18 = obj;
                    lv_obj_set_pos(obj, 1175, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_19
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_19 = obj;
                    lv_obj_set_pos(obj, 1193, 26);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -821, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_20
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_20 = obj;
                    lv_obj_set_pos(obj, 1208, 33);
                    lv_obj_set_size(obj, 32, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -657.5, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_21
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_21 = obj;
                    lv_obj_set_pos(obj, 1222, 39);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -494, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_22
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_22 = obj;
                    lv_obj_set_pos(obj, 1233, 51);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -331, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_23
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_23 = obj;
                    lv_obj_set_pos(obj, 1240, 66);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -167, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_24
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_24 = obj;
                    lv_obj_set_pos(obj, 1242, 82);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_25
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_25 = obj;
                    lv_obj_set_pos(obj, 1242, 101);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_26
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_26 = obj;
                    lv_obj_set_pos(obj, 1242, 120);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_27
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_27 = obj;
                    lv_obj_set_pos(obj, 1242, 140);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_28
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_28 = obj;
                    lv_obj_set_pos(obj, 1242, 159);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_29
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_29 = obj;
                    lv_obj_set_pos(obj, 1242, 179);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_30
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_30 = obj;
                    lv_obj_set_pos(obj, 1216, 198);
                    lv_obj_set_size(obj, 48, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_31
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_31 = obj;
                    lv_obj_set_pos(obj, 1242, 217);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_32
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_32 = obj;
                    lv_obj_set_pos(obj, 1242, 237);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_33
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_33 = obj;
                    lv_obj_set_pos(obj, 1242, 256);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_34
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_34 = obj;
                    lv_obj_set_pos(obj, 1242, 276);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_35
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_35 = obj;
                    lv_obj_set_pos(obj, 1242, 295);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_36
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_36 = obj;
                    lv_obj_set_pos(obj, 1242, 314);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_37
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_37 = obj;
                    lv_obj_set_pos(obj, 1240, 330);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 167, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_38
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_38 = obj;
                    lv_obj_set_pos(obj, 1233, 345);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 331, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_39
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_39 = obj;
                    lv_obj_set_pos(obj, 1222, 357);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 494, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_40
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_40 = obj;
                    lv_obj_set_pos(obj, 1208, 364);
                    lv_obj_set_size(obj, 36, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 657.5, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_41
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_41 = obj;
                    lv_obj_set_pos(obj, 1193, 370);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 821, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_42
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_42 = obj;
                    lv_obj_set_pos(obj, 1175, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_43
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_43 = obj;
                    lv_obj_set_pos(obj, 1156, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_44
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_44 = obj;
                    lv_obj_set_pos(obj, 1136, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_45
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_45 = obj;
                    lv_obj_set_pos(obj, 1117, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_46
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_46 = obj;
                    lv_obj_set_pos(obj, 1097, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_47
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_47 = obj;
                    lv_obj_set_pos(obj, 1078, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_48
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_48 = obj;
                    lv_obj_set_pos(obj, 1058, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_49
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_49 = obj;
                    lv_obj_set_pos(obj, 1039, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_50
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_50 = obj;
                    lv_obj_set_pos(obj, 1020, 364);
                    lv_obj_set_size(obj, 36, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_51
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_51 = obj;
                    lv_obj_set_pos(obj, 1000, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_52
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_52 = obj;
                    lv_obj_set_pos(obj, 981, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_53
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_53 = obj;
                    lv_obj_set_pos(obj, 961, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_54
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_54 = obj;
                    lv_obj_set_pos(obj, 942, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_55
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_55 = obj;
                    lv_obj_set_pos(obj, 923, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_56
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_56 = obj;
                    lv_obj_set_pos(obj, 903, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_57
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_57 = obj;
                    lv_obj_set_pos(obj, 884, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_58
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_58 = obj;
                    lv_obj_set_pos(obj, 864, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_59
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_59 = obj;
                    lv_obj_set_pos(obj, 845, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_61
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_61 = obj;
                    lv_obj_set_pos(obj, 413, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_62
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_62 = obj;
                    lv_obj_set_pos(obj, 394, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_63
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_63 = obj;
                    lv_obj_set_pos(obj, 374, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_64
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_64 = obj;
                    lv_obj_set_pos(obj, 355, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_65
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_65 = obj;
                    lv_obj_set_pos(obj, 335, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_66
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_66 = obj;
                    lv_obj_set_pos(obj, 316, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_67
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_67 = obj;
                    lv_obj_set_pos(obj, 297, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_68
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_68 = obj;
                    lv_obj_set_pos(obj, 277, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_69
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_69 = obj;
                    lv_obj_set_pos(obj, 258, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_70
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_70 = obj;
                    lv_obj_set_pos(obj, 239, 364);
                    lv_obj_set_size(obj, 36, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_71
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_71 = obj;
                    lv_obj_set_pos(obj, 219, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_72
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_72 = obj;
                    lv_obj_set_pos(obj, 200, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_73
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_73 = obj;
                    lv_obj_set_pos(obj, 180, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_74
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_74 = obj;
                    lv_obj_set_pos(obj, 161, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_75
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_75 = obj;
                    lv_obj_set_pos(obj, 141, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_76
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_76 = obj;
                    lv_obj_set_pos(obj, 122, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_77
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_77 = obj;
                    lv_obj_set_pos(obj, 102, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_78
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_78 = obj;
                    lv_obj_set_pos(obj, 83, 371);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_79
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_79 = obj;
                    lv_obj_set_pos(obj, 65, 370);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 979, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_80
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_80 = obj;
                    lv_obj_set_pos(obj, 51, 364);
                    lv_obj_set_size(obj, 36, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1142.5, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_81
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_81 = obj;
                    lv_obj_set_pos(obj, 36, 357);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1306, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_82
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_82 = obj;
                    lv_obj_set_pos(obj, 25, 345);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1469, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_83
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_83 = obj;
                    lv_obj_set_pos(obj, 18, 330);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1633, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_84
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_84 = obj;
                    lv_obj_set_pos(obj, 16, 314);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1796, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_85
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_85 = obj;
                    lv_obj_set_pos(obj, 16, 295);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_86
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_86 = obj;
                    lv_obj_set_pos(obj, 16, 276);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_87
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_87 = obj;
                    lv_obj_set_pos(obj, 16, 256);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_88
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_88 = obj;
                    lv_obj_set_pos(obj, 16, 237);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_89
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_89 = obj;
                    lv_obj_set_pos(obj, 16, 217);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_90
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_90 = obj;
                    lv_obj_set_pos(obj, 42, 198);
                    lv_obj_set_size(obj, 48, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_91
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_91 = obj;
                    lv_obj_set_pos(obj, 16, 179);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_92
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_92 = obj;
                    lv_obj_set_pos(obj, 16, 159);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_93
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_93 = obj;
                    lv_obj_set_pos(obj, 16, 140);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_94
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_94 = obj;
                    lv_obj_set_pos(obj, 16, 120);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_95
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_95 = obj;
                    lv_obj_set_pos(obj, 16, 101);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_96
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_96 = obj;
                    lv_obj_set_pos(obj, 16, 82);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -1796, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_97
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_97 = obj;
                    lv_obj_set_pos(obj, 18, 66);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -1633, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_98
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_98 = obj;
                    lv_obj_set_pos(obj, 25, 51);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -1469, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_99
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_99 = obj;
                    lv_obj_set_pos(obj, 36, 39);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -1306, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_100
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_100 = obj;
                    lv_obj_set_pos(obj, 51, 33);
                    lv_obj_set_size(obj, 36, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -1142.5, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_101
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_101 = obj;
                    lv_obj_set_pos(obj, 65, 26);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -979, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_102
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_102 = obj;
                    lv_obj_set_pos(obj, 83, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_103
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_103 = obj;
                    lv_obj_set_pos(obj, 102, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_104
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_104 = obj;
                    lv_obj_set_pos(obj, 122, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_105
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_105 = obj;
                    lv_obj_set_pos(obj, 141, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_106
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_106 = obj;
                    lv_obj_set_pos(obj, 161, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_107
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_107 = obj;
                    lv_obj_set_pos(obj, 180, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_108
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_108 = obj;
                    lv_obj_set_pos(obj, 200, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_109
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_109 = obj;
                    lv_obj_set_pos(obj, 219, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_110
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_110 = obj;
                    lv_obj_set_pos(obj, 239, 26);
                    lv_obj_set_size(obj, 32, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_111
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_111 = obj;
                    lv_obj_set_pos(obj, 258, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_112
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_112 = obj;
                    lv_obj_set_pos(obj, 277, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_113
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_113 = obj;
                    lv_obj_set_pos(obj, 297, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_114
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_114 = obj;
                    lv_obj_set_pos(obj, 316, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_115
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_115 = obj;
                    lv_obj_set_pos(obj, 335, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_116
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_116 = obj;
                    lv_obj_set_pos(obj, 355, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_117
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_117 = obj;
                    lv_obj_set_pos(obj, 374, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_118
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_118 = obj;
                    lv_obj_set_pos(obj, 394, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // tick_119
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.tick_119 = obj;
                    lv_obj_set_pos(obj, 413, 25);
                    lv_obj_set_size(obj, 22, 4);
                    add_style_tick(obj);
                    lv_obj_set_style_transform_angle(obj, -900, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ui_time_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ui_time_label = obj;
            lv_obj_set_pos(obj, 381, 67);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_extra_light_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 607, 18);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_dynamic_island);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 461, 362);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_black_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x212121), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "ABDULLAH AHMER");
        }
        {
            // status_bar_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.status_bar_time = obj;
            lv_obj_set_pos(obj, 526, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_regular_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_watch_face_locked();
}

void delete_screen_watch_face_locked() {
    lv_obj_del(objects.watch_face_locked);
    objects.watch_face_locked = 0;
    objects.ui_seconds_complication = 0;
    objects.tick_1 = 0;
    objects.tick_2 = 0;
    objects.tick_3 = 0;
    objects.tick_4 = 0;
    objects.tick_5 = 0;
    objects.tick_6 = 0;
    objects.tick_7 = 0;
    objects.tick_8 = 0;
    objects.tick_9 = 0;
    objects.tick_10 = 0;
    objects.tick_11 = 0;
    objects.tick_12 = 0;
    objects.tick_13 = 0;
    objects.tick_14 = 0;
    objects.tick_15 = 0;
    objects.tick_16 = 0;
    objects.tick_17 = 0;
    objects.tick_18 = 0;
    objects.tick_19 = 0;
    objects.tick_20 = 0;
    objects.tick_21 = 0;
    objects.tick_22 = 0;
    objects.tick_23 = 0;
    objects.tick_24 = 0;
    objects.tick_25 = 0;
    objects.tick_26 = 0;
    objects.tick_27 = 0;
    objects.tick_28 = 0;
    objects.tick_29 = 0;
    objects.tick_30 = 0;
    objects.tick_31 = 0;
    objects.tick_32 = 0;
    objects.tick_33 = 0;
    objects.tick_34 = 0;
    objects.tick_35 = 0;
    objects.tick_36 = 0;
    objects.tick_37 = 0;
    objects.tick_38 = 0;
    objects.tick_39 = 0;
    objects.tick_40 = 0;
    objects.tick_41 = 0;
    objects.tick_42 = 0;
    objects.tick_43 = 0;
    objects.tick_44 = 0;
    objects.tick_45 = 0;
    objects.tick_46 = 0;
    objects.tick_47 = 0;
    objects.tick_48 = 0;
    objects.tick_49 = 0;
    objects.tick_50 = 0;
    objects.tick_51 = 0;
    objects.tick_52 = 0;
    objects.tick_53 = 0;
    objects.tick_54 = 0;
    objects.tick_55 = 0;
    objects.tick_56 = 0;
    objects.tick_57 = 0;
    objects.tick_58 = 0;
    objects.tick_59 = 0;
    objects.tick_61 = 0;
    objects.tick_62 = 0;
    objects.tick_63 = 0;
    objects.tick_64 = 0;
    objects.tick_65 = 0;
    objects.tick_66 = 0;
    objects.tick_67 = 0;
    objects.tick_68 = 0;
    objects.tick_69 = 0;
    objects.tick_70 = 0;
    objects.tick_71 = 0;
    objects.tick_72 = 0;
    objects.tick_73 = 0;
    objects.tick_74 = 0;
    objects.tick_75 = 0;
    objects.tick_76 = 0;
    objects.tick_77 = 0;
    objects.tick_78 = 0;
    objects.tick_79 = 0;
    objects.tick_80 = 0;
    objects.tick_81 = 0;
    objects.tick_82 = 0;
    objects.tick_83 = 0;
    objects.tick_84 = 0;
    objects.tick_85 = 0;
    objects.tick_86 = 0;
    objects.tick_87 = 0;
    objects.tick_88 = 0;
    objects.tick_89 = 0;
    objects.tick_90 = 0;
    objects.tick_91 = 0;
    objects.tick_92 = 0;
    objects.tick_93 = 0;
    objects.tick_94 = 0;
    objects.tick_95 = 0;
    objects.tick_96 = 0;
    objects.tick_97 = 0;
    objects.tick_98 = 0;
    objects.tick_99 = 0;
    objects.tick_100 = 0;
    objects.tick_101 = 0;
    objects.tick_102 = 0;
    objects.tick_103 = 0;
    objects.tick_104 = 0;
    objects.tick_105 = 0;
    objects.tick_106 = 0;
    objects.tick_107 = 0;
    objects.tick_108 = 0;
    objects.tick_109 = 0;
    objects.tick_110 = 0;
    objects.tick_111 = 0;
    objects.tick_112 = 0;
    objects.tick_113 = 0;
    objects.tick_114 = 0;
    objects.tick_115 = 0;
    objects.tick_116 = 0;
    objects.tick_117 = 0;
    objects.tick_118 = 0;
    objects.tick_119 = 0;
    objects.ui_time_label = 0;
    objects.obj0 = 0;
    objects.status_bar_time = 0;
    deletePageFlowState(0);
}

void tick_screen_watch_face_locked() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 120, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.ui_time_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.ui_time_label;
            lv_label_set_text(objects.ui_time_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 123, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.status_bar_time);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.status_bar_time;
            lv_label_set_text(objects.status_bar_time, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_loading_page() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1280, 400);
    lv_obj_add_event_cb(obj, event_handler_cb_loading_page_loading_page, LV_EVENT_ALL, flowState);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x040204), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // logo
            lv_obj_t *obj = lv_animimg_create(parent_obj);
            objects.logo = obj;
            lv_obj_set_pos(obj, 448, 14);
            lv_obj_set_size(obj, 384, 373);
        }
    }
    
    tick_screen_loading_page();
}

void delete_screen_loading_page() {
    lv_obj_del(objects.loading_page);
    objects.loading_page = 0;
    objects.logo = 0;
    deletePageFlowState(1);
}

void tick_screen_loading_page() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_watch_face_locked,
    create_screen_loading_page,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_watch_face_locked,
    delete_screen_loading_page,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_watch_face_locked,
    tick_screen_loading_page,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 2) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Styles
//

static const char *style_names[] = { "tick" };

extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

//
// Fonts
//

ext_font_desc_t fonts[] = {
    { "montserrat_extra_light_128", &ui_font_montserrat_extra_light_128 },
    { "montserrat_black_64", &ui_font_montserrat_black_64 },
    { "montserrat_black_48", &ui_font_montserrat_black_48 },
    { "montserrat_black_32", &ui_font_montserrat_black_32 },
    { "montserrat_light_16", &ui_font_montserrat_light_16 },
    { "montserrat_regular_20", &ui_font_montserrat_regular_20 },
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
//
//

void create_screens() {
    // Initialize styles
    eez_flow_init_styles(add_style, remove_style);
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));

eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);
    
    // Create screens
    create_screen_watch_face_locked();
    create_screen_loading_page();
}