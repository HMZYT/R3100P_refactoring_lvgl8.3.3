#ifndef __RC_LCD_PAGES_FACTORY_H__
#define __RC_LCD_PAGES_FACTORY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef enum{
    e_fact_page_version,
    e_fact_page_align_arms,
    e_fact_page_align_displacement,
    e_fact_page_full_color,
    e_fact_page_touch,
    e_fact_page_end,
}rc_lcd_factory_pages_t;

lv_obj_t* rc_lcd_factory_widget_init();

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif // __RC_LCD_PAGES_FACTORY_H__
