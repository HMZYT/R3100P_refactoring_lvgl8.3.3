#ifndef __PREPARED_HEADER_H__
#define __PREPARED_HEADER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "irc_lcd_header.h"

typedef struct
{
    irc_lcd_header_t base;
}prepared_header_t;

extern irc_lcd_header_t *prepared_header_create(lv_obj_t *parent);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif // __PREPARED_HEADER_H__