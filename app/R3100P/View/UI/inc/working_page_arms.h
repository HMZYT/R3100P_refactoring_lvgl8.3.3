#ifndef __WORKING_PAGE_ARMS_H__
#define __WORKING_PAGE_ARMS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
typedef struct{
    lv_obj_t *mode_bg[7];
    lv_obj_t *label_show[10];
    lv_obj_t *arm_ground;
    lv_obj_t *arm_01;
    lv_obj_t *arm_02;
    lv_obj_t *arm_03;
    lv_obj_t *arm_04;
    lv_obj_t *arm_05;
    lv_obj_t *arm_06;
    lv_obj_t *arm_07;
    lv_obj_t *arm_p01;
    lv_obj_t *arm_p02;
    lv_obj_t *arm_p03;
    lv_obj_t *arm_p04;
    lv_obj_t *arm_p05;
    lv_obj_t *arm_p06;
    lv_obj_t *arm_p07;
}working_page_arms_t;

lv_obj_t* working_page_arms_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
