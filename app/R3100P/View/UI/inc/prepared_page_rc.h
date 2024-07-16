#ifndef __PREPARED_PAGE_RC_H__
#define __PREPARED_PAGE_RC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "working_page_rc.h"

typedef struct{
    lv_obj_t *up[6];
    lv_obj_t *down[6];
    rocker_t *rockers[6];
    rc_lcd_button_t *btns[ 5 ];
    lv_obj_t *btn_lock_arms;
    lv_obj_t *btn_replacement;
    lv_obj_t *btn_off;
    lv_obj_t *btn_whistle;
    lv_obj_t *btn_stop; //?????
    lv_obj_t *btn_start; //?????
    lv_obj_t *btn_emergency;
    lv_obj_t *label_emergency;
    lv_obj_t *label_lock;
    lv_obj_t *label_displacement;
    lv_obj_t *arms06a;
    lv_obj_t *arms06b;
    lv_obj_t *arms06c;
    lv_obj_t *label_rig;
    lv_obj_t *label_dow;
    lv_obj_t *backlight_bar;
    lv_obj_t *alert_bg;
    lv_obj_t *alert_icon[16];
    lv_obj_t *arrow_lef;
    lv_obj_t *arrow_rig;
    lv_obj_t *arrow_up;
    lv_obj_t *arrow_dow;
}prepared_page_rc_t;

lv_obj_t* prepared_page_rc_create(lv_obj_t *page);
extern char string_show[80];

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif