#ifndef __IRC_LCD_HEADER_H__
#define __IRC_LCD_HEADER_H__

#include "lvgl.h"

struct _irc_lcd_header_t;
typedef struct _irc_lcd_header_t irc_lcd_header_t;

typedef irc_lcd_header_t * (*irc_lcd_header_create_t)( lv_obj_t *parent );
typedef void (*irc_lcd_header_refresh_t)( irc_lcd_header_t* h, void *data );

struct _irc_lcd_header_t{
    lv_obj_t *obj;
    lv_obj_t *logo;
    lv_obj_t *title;
    lv_obj_t *bg;
    irc_lcd_header_refresh_t refresh;   //由子类实现
};

extern void irc_lcd_header_init( irc_lcd_header_t *h, lv_obj_t *parent );

extern void irc_lcd_header_refresh( irc_lcd_header_t* h, void *data );

#endif
