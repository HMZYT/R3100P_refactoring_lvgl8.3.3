#ifndef __WORKING_PAGE_RC_H__
#define __WORKING_PAGE_RC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *ibase;
    lv_obj_t *rocker;
    lv_obj_t *v;

}rocker_t;

typedef struct{
    lv_obj_t *ibase;
    lv_obj_t *v;
}rc_lcd_button_t;


typedef struct{
    lv_obj_t *up[7];
    lv_obj_t *down[7];
    rocker_t *rockers[7];
    rc_lcd_button_t *btns[ 7 ];
    lv_obj_t *btn_lock_arms;
    lv_obj_t *btn_replacement;
    lv_obj_t *btn_whistle_and_off;
    lv_obj_t *btn_stop; //发动机急停
    lv_obj_t *btn_start; //发动机启动
    lv_obj_t *btn_emergency;
    lv_obj_t *btn_swing_left;
    lv_obj_t *btn_swing_right;
    lv_obj_t *label_emergency;
    lv_obj_t *label_lock;
    lv_obj_t *label_displacement;
    lv_obj_t *arms06a;
    lv_obj_t *arms06b;
    lv_obj_t *arms06c;
    lv_obj_t *label_rig;
    lv_obj_t *label_dow;
    lv_obj_t *backlight_bar;
}working_page_rc_t;

lv_obj_t* working_page_rc_init(lv_obj_t *page);
extern int bg_light_level;
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif