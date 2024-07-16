#ifndef _FACT_PAGE_FULL_COLOR_H_
#define _FACT_PAGE_FULL_COLOR_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"

typedef struct{
    uint8_t color;
    lv_obj_t *tips;
}fact_page_full_color_t;

lv_obj_t* fact_page_full_color_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
