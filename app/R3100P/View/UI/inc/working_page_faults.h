#ifndef __WORKING_PAGE_FAULTS_H__
#define __WORKING_PAGE_FAULTS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *label_1[8];
    lv_obj_t *label_2[8];
    lv_obj_t *label_3[8];
}working_page_faults_t;

lv_obj_t* working_page_faults_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
