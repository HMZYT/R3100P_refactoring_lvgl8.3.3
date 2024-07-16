#ifndef _FACT_PAGE_TOUCH_H_
#define _FACT_PAGE_TOUCH_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "lvgl/lvgl.h"
//#include "utlist.h"

#define FACT_PAGE_TOUCH_MAX_LINES 32

typedef struct{
    lv_obj_t *parent;
    lv_obj_t *tips;
    lv_obj_t *lines[ FACT_PAGE_TOUCH_MAX_LINES ];
    uint8_t cur_line;
    lv_point_t *pnts[ FACT_PAGE_TOUCH_MAX_LINES ];
}fact_page_touch_t;

lv_obj_t* fact_page_touch_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
