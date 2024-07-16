#ifndef __WORKING_HEADER_H__
#define __WORKING_HEADER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "irc_lcd_header.h"

typedef struct{
    lv_obj_t *battery;
    lv_obj_t *charging;
    lv_obj_t *rect;
}rc_lcd_header_battery_t;

typedef struct{
    lv_obj_t *wireless;
    lv_obj_t *r[5];
    lv_obj_t *wirefull;
}rc_lcd_header_connection_t;


typedef struct
{
    irc_lcd_header_t base;
    lv_obj_t *whistle;
    rc_lcd_header_connection_t *connecter;
    lv_obj_t *battery;
    lv_obj_t *ready;
    lv_obj_t *channel;
    lv_obj_t *rssi_trans;
    lv_obj_t *rssi_recev;
} working_header_t;

extern irc_lcd_header_t *working_header_create(lv_obj_t *parent);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif