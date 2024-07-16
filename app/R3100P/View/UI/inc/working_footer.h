#ifndef __WORKING_FOOTER_H__
#define __WORKING_FOOTER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "irc_lcd_footer.h"

typedef struct
{
    irc_lcd_footer_t base;
    lv_obj_t *id;
    lv_obj_t *total;
    lv_obj_t *detail;
    lv_obj_t *content;
} working_footer_t;


extern irc_lcd_footer_t *working_footer_create(lv_obj_t *parent);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif