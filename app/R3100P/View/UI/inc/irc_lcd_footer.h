#ifndef __IRC_LCD_FOOTER_H__
#define __IRC_LCD_FOOTER_H__
#include "lvgl.h"

struct _irc_lcd_footer_t;
typedef struct _irc_lcd_footer_t irc_lcd_footer_t;

typedef void (*irc_lcd_footer_refresh_t)( irc_lcd_footer_t* h, void *data );

struct _irc_lcd_footer_t{
    lv_obj_t *obj;
		lv_obj_t *title;
    irc_lcd_footer_refresh_t refresh;
};


extern void irc_lcd_footer_init( irc_lcd_footer_t *ih, lv_obj_t *parent );

extern void irc_lcd_footer_refresh( irc_lcd_footer_t* h, void *data );


#endif  // __IRC_LCD_FOOTER_H__

