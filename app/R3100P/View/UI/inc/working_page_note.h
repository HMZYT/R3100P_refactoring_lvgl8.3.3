#ifndef __WORKING_PAGE_NOTE_H__
#define __WORKING_PAGE_NOTE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *language_label;
}working_page_note_t;

lv_obj_t* working_page_note_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
