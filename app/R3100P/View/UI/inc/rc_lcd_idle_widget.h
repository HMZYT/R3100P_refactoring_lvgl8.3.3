#ifndef __RC_LCD_IDLE_WIDGET_H__
#define __RC_LCD_IDLE_WIDGET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef enum {
    e_idle_page_black,
    e_idle_page_end,
}rc_lcd_idle_pages_t;

lv_obj_t * idle_widget_init();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* __RC_LCD_IDLE_WIDGET_H__ */

