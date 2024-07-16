#ifndef _FACT_PAGE_ALIGN_H_
#define _FACT_PAGE_ALIGN_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *label_arm_top;
    lv_obj_t *label_arm_btm;
    lv_obj_t *label_arm_mid;
    lv_obj_t *btnm_arm;
    lv_obj_t *align_btnm;
    lv_obj_t *rocker_up ;
    lv_obj_t *rocker_mid ;
    lv_obj_t *rocker_btm ;
    lv_obj_t *rocker_left ;
    lv_obj_t *rocker_right ;
}fact_page_align_t;

lv_obj_t* fact_page_algin_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif // _FACT_PAGE_ALIGN_H_
