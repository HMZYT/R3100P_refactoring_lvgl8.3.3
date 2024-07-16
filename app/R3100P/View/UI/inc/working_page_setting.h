#ifndef __WORKING_PAGE_SETTING_H__
#define __WORKING_PAGE_SETTING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *ibase;
    lv_obj_t *v;
}setting_lcd_button_t;

typedef struct{
    setting_lcd_button_t *btns[ 2 ];
    lv_obj_t *backlight_bar;
    lv_obj_t *backlight_value;
}working_page_setting_t;

lv_obj_t* working_page_setting_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
