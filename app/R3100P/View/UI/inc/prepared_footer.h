#ifndef __PREPARED_FOOTER_H__
#define __PREPARED_FOOTER_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "irc_lcd_footer.h"

typedef struct
{
    irc_lcd_footer_t base;
}prepared_footer_t;

extern irc_lcd_footer_t *prepared_footer_create(lv_obj_t *parent);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif

