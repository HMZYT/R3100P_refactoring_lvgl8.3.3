#ifndef __XLV_BATTRERY_H__
#define __XLV_BATTRERY_H__

#include <stdbool.h>
#include "lvgl.h"


enum _xlv_battery_direction_t{
    BATTERY_COLUMN,
    BATTERY_ROW
};
typedef uint8_t xlv_battery_direction_t;

enum _xlv_battery_charging_pos_t{
    BATTERY_CHARGING_UP,
    BATTERY_CHARGING_DOWN,
    BATTERY_CHARGING_LEFT,
    BATTERY_CHARGING_RIGHT,
};
typedef uint8_t xlv_battery_charging_pos_t;

enum _xlv_battery_style_t{
    BATTERY_STYLE_1,
    BATTERY_STYLE_2,
};
typedef uint8_t xlv_battery_style_t;

typedef struct{
    lv_obj_t base;
    lv_obj_t *rect;
    lv_obj_t *bar;
    lv_obj_t *bat_header;
    lv_obj_t *charging;
    xlv_battery_direction_t dir; 
    xlv_battery_charging_pos_t charging_pos;
    bool charging_state;
}xlv_battery_t;



extern lv_obj_t *xlv_battery_create( lv_obj_t *parent );


extern lv_obj_t *xlv_battery_get_rect( lv_obj_t *bat );
extern lv_obj_t *xlv_battery_get_bar( lv_obj_t *bat );
extern lv_obj_t *xlv_battery_get_header( lv_obj_t *bat );
extern lv_obj_t *xlv_battery_get_charging( lv_obj_t *bat );
extern bool xlv_battery_get_charging_state( lv_obj_t *bat );

extern uint8_t xlv_battery_get_direction( lv_obj_t *bat );
extern void xlv_battery_set_direction( lv_obj_t *bat, uint8_t direction );

extern void xlv_battery_set_charging_pos( lv_obj_t *bat, uint8_t pos);

extern void xlv_battery_set_value( lv_obj_t *bat, uint8_t value );

extern void xlv_battery_set_charging( lv_obj_t *bat, bool charging );

extern void xlv_battery_set_default_style( lv_obj_t *bat, uint8_t style_type );
extern void xlv_battery_set_little_style(lv_obj_t *bat);


#endif
