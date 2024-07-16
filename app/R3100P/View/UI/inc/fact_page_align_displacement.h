#ifndef __FACT_PAGE_ALIGN_DISPLACEMENT_H__
#define __FACT_PAGE_ALIGN_DISPLACEMENT_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *label_v0;
    lv_obj_t *label_v10;
    lv_obj_t *label_v5;
    lv_obj_t *btn_0;
    lv_obj_t *btn_10;
    lv_obj_t *btn_5;
    lv_obj_t *btnm;
}fact_page_align_displacement_t;

lv_obj_t* fact_page_algin_displacement_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif//__FACT_PAGE_ALIGN_DISPLACEMENT_