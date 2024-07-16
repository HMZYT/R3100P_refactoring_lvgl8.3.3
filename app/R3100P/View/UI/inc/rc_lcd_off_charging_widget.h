#ifndef __RC_LCD_PAGES_OFF_CHARGING_H__
#define __RC_LCD_PAGES_OFF_CHARGING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef enum{
    e_off_charging_page_charging,
    e_off_charging_page_end,
}rc_lcd_off_charging_pages_t;

lv_obj_t * rc_lcd_off_charging_widget_init();

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif // __RC_LCD_PAGES_OFF_CHARGING_H__
