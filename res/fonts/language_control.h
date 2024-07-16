#ifndef __LANGUAGE_CONTROL__
#define __LANGUAGE_CONTROL__

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

enum {
    Chinese,
    English,
    End_Flag
};

void language_set_current_lang(int32_t num);
void language_lv_label_set_text(lv_obj_t* obj_label, char* info_label);
void language_lv_label_set_text_static(lv_obj_t* obj_label,const char* info_label);
void language_change_callback();
void language_clear_label_list();
extern uint8_t selected_language;
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif
