#ifndef _OFF_CHARGING_PAGE_CHARGING_H_
#define _OFF_CHARGING_PAGE_CHARGING_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
#include "../api/inc/xlv_battery.h"

typedef struct{
    lv_obj_t *bat;
}off_charging_page_charging_t;

lv_obj_t* off_charging_page_charging_init(lv_obj_t *page);


#endif // _OFF_CHARGING_PAGE_CHARGING_H_
