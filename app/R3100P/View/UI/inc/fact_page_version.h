#ifndef _FACT_PAGE_VERSION_H_
#define _FACT_PAGE_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
typedef struct{
    lv_obj_t *content_lcd_boot_version ;
    lv_obj_t *content_lcd_version  ;
    lv_obj_t *content_t_boot_version ;
    lv_obj_t *content_t_update_version ;
    lv_obj_t *content_t_app_version ;
    lv_obj_t *content_t_back_mcu_version ;
    lv_obj_t *content_rf_version ;
    lv_obj_t *content_dev_addr ;
}fact_page_version_t;

lv_obj_t* fact_page_version_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif // _FACT_PAGE_VERSION_H_W
