#ifndef __WORKING_PAGE_LIGHT_H__
#define __WORKING_PAGE_LIGHT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *ibase;
    lv_obj_t *v;
}lights_lcd_button_t;

typedef struct{
    lights_lcd_button_t *btns[ 3 ];
}working_page_light_t;

lv_obj_t* working_page_light_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
