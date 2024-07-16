#include "../inc/xlv_battery.h"
#include "../inc/xlv_battery.h"

#define MY_CLASS &xlv_battery_class

static void xlv_battery_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void xlv_battery_destructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void xlv_battery_value_changed_event_cb(lv_event_t *e);
static void lv_bat_event(const lv_obj_class_t *class_p, lv_event_t *e);

static lv_style_t style_indic;
static lv_style_t bar_style;
static lv_style_t style_indic_little;
static lv_style_t bar_style_little;

const lv_obj_class_t xlv_battery_class = {
    .constructor_cb = xlv_battery_constructor,
    .destructor_cb = xlv_battery_destructor,
    .event_cb = lv_bat_event,
    .base_class = &lv_obj_class,
    .width_def = LV_PCT(100),
    .height_def = LV_SIZE_CONTENT,
    .instance_size = sizeof(xlv_battery_t)};

lv_obj_t *xlv_battery_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

lv_obj_t *xlv_battery_get_rect(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->rect;
}

lv_obj_t *xlv_battery_get_bar(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->bar;
}

lv_obj_t *xlv_battery_get_header(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->bat_header;
}

lv_obj_t *xlv_battery_get_charging(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->charging;
}
bool xlv_battery_get_charging_state(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->charging_state;
}

void xlv_battery_set_direction(lv_obj_t *bat, uint8_t direction)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    b->dir = direction;
    //更新以后重新画图
}

uint8_t xlv_battery_get_direction(lv_obj_t *bat)
{
    xlv_battery_t *b = (xlv_battery_t *)bat;
    return b->dir;
}

void xlv_battery_set_charging_pos(lv_obj_t *bat, uint8_t pos)
{
}

void xlv_battery_set_value(lv_obj_t *bat, uint8_t value)
{
    lv_obj_t *bar = xlv_battery_get_bar(bat);
    static const uint32_t colors[] = {
        0xFF0000,
        0xFFFF00,
        0xB5E61D,
        0x00FF00};
    uint8_t idx = 0;

    if (xlv_battery_get_charging_state(bat))
    {
        idx = 3;
    }
    else
    {
        if (value < 20)
        {
            idx = 0;
        }
        else if (value < 50)
        {
            idx = 1;
        }
        else if (value < 90)
        {
            idx = 2;
        }
        else
        {
            idx = 3;
        }
    }

    lv_style_set_bg_color(&style_indic, lv_color_hex(colors[idx]));
    lv_style_set_bg_color(&style_indic_little, lv_color_hex(colors[idx]));

    lv_bar_set_value(bar, value, LV_ANIM_OFF);
}

void xlv_battery_set_charging(lv_obj_t *bat, bool charging)
{
    lv_obj_t *charging_img = xlv_battery_get_charging(bat);
    xlv_battery_t *b = (xlv_battery_t *)bat;
    b->charging_state = charging;
    if (charging)
    {
        lv_obj_clear_flag(charging_img, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(charging_img, LV_OBJ_FLAG_HIDDEN);
    }
}

void xlv_battery_set_little_style(lv_obj_t *bat)
{

    lv_style_init(&bar_style_little);
    lv_style_set_border_color(&bar_style_little, lv_color_black());
    lv_style_set_radius(&bar_style_little, 8);
    lv_style_set_bg_opa(&bar_style_little, LV_OPA_TRANSP);
    // lv_style_set_bg_color(&bar_style, lv_color_white());
    lv_style_set_border_width(&bar_style_little, 4);
    // lv_style_set_border_post_color(&bar_style, lv_color_white());
    lv_style_set_pad_all(&bar_style_little, 0);

    lv_obj_t *bar = xlv_battery_get_bar(bat);
    lv_obj_add_style(bar, &bar_style_little, 0);

    lv_style_init(&style_indic_little);
    lv_style_set_bg_opa(&style_indic_little, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic_little, lv_color_make(255, 0, 0));
    lv_style_set_radius(&style_indic_little, 0);
    lv_style_set_clip_corner(&style_indic_little, false);
    // lv_style_set_

    lv_obj_add_style(bar, &style_indic_little, LV_PART_INDICATOR);

    static lv_style_t style_header;
    lv_style_init(&style_header);
    lv_style_set_bg_color(&style_header, lv_color_white());
    lv_style_set_bg_opa(&style_header, LV_OPA_COVER);
    lv_style_set_border_width(&style_header, 0);
    lv_style_set_pad_all(&style_header, 0);
    lv_style_set_radius(&style_header, 0);

    lv_obj_t *header = xlv_battery_get_header(bat);
    lv_obj_add_style(header, &style_header, 0);

    lv_obj_t *rect = xlv_battery_get_rect(bat);
    lv_obj_add_style(rect, &bar_style_little, 0);

    static lv_style_t style_charging;
    lv_style_init(&style_charging);
    lv_style_set_bg_opa(&style_charging, LV_OPA_TRANSP);
    lv_style_set_border_width(&style_charging, 0);


    lv_obj_t *charging = xlv_battery_get_charging(bat);
    lv_img_set_src(charging, &charging);
    lv_obj_add_style(charging, &style_charging, 0);
}

void xlv_battery_set_default_style(lv_obj_t *bat, uint8_t style_type)
{

    lv_style_init(&bar_style);
    lv_style_set_border_color(&bar_style, lv_color_black());
    lv_style_set_radius(&bar_style, 10);
    lv_style_set_bg_opa(&bar_style, LV_OPA_TRANSP);
    // lv_style_set_bg_color(&bar_style, lv_color_white());
    lv_style_set_border_width(&bar_style, 6);
    // lv_style_set_border_post_color(&bar_style, lv_color_white());
    lv_style_set_pad_all(&bar_style, 4);

    lv_obj_t *bar = xlv_battery_get_bar(bat);
    lv_obj_add_style(bar, &bar_style, 0);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_color_make(255, 0, 0));
    lv_style_set_radius(&style_indic, 0);
    lv_style_set_clip_corner(&style_indic, false);
    // lv_style_set_

    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

    static lv_style_t style_header;
    lv_style_init(&style_header);
    lv_style_set_bg_color(&style_header, lv_color_white());
    lv_style_set_bg_opa(&style_header, LV_OPA_COVER);
    lv_style_set_border_width(&style_header, 0);
    lv_style_set_pad_all(&style_header, 0);
    lv_style_set_radius(&style_header, 0);

    lv_obj_t *header = xlv_battery_get_header(bat);
    lv_obj_add_style(header, &style_header, 0);

    lv_obj_t *rect = xlv_battery_get_rect(bat);
    lv_obj_add_style(rect, &bar_style, 0);


    static lv_style_t style_charging;
    lv_style_init(&style_charging);
    lv_style_set_bg_opa(&style_charging, LV_OPA_TRANSP);
    lv_style_set_border_width(&style_charging, 0);

    lv_obj_t *charging = xlv_battery_get_charging(bat);
    lv_img_set_src(charging, &charging);
    lv_obj_add_style(charging, &style_charging, 0);
#if 0 
    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_opa(&bg_style, LV_OPA_TRANSP);

    static lv_style_t style;
    lv_style_init( &style );
    lv_style_set_border_color( &style, lv_color_make(255,0,0) );
    lv_style_set_border_width( &style, 3 );
    lv_style_set_border_opa( &style, LV_OPA_COVER );
    lv_style_set_border_side( &style, LV_BORDER_SIDE_FULL );
    lv_style_set_pad_all( &style, 0 );

    static lv_style_t header_style;
    lv_style_init(&header_style);
    lv_style_set_bg_color( &header_style, lv_color_make(0,0,255));
    lv_style_set_bg_opa( &header_style, LV_OPA_COVER );
    lv_style_set_border_side( &header_style, LV_BORDER_SIDE_NONE );
    lv_style_set_border_width( &header_style, 0 );
    lv_style_set_radius( &header_style, 0 );

    xlv_battery_t * obj = (xlv_battery_t *)bat;
    lv_obj_add_style( bat, &bg_style, 0 );
    // lv_obj_set_size( bat, 257, 144 );
    lv_obj_set_scrollbar_mode( bat, LV_SCROLLBAR_MODE_OFF );

    lv_obj_t *bat_header = xlv_battery_get_header( bat );
    lv_obj_add_style( bat_header, &header_style, 0 );
    lv_obj_set_size( bat_header, 10, 144 / 5 );
    lv_obj_set_pos( bat_header, 257, 144 / 2 - 144 /5 + 8 );
    lv_obj_set_scrollbar_mode( bat_header, LV_SCROLLBAR_MODE_OFF );
        
    static lv_style_t charging_style;
    lv_style_init(&charging_style);
    lv_style_set_bg_color( &charging_style, lv_color_make(0, 0, 255) );
    lv_style_set_bg_opa( &charging_style, LV_OPA_COVER );

    lv_obj_t *charging = xlv_battery_get_charging( bat );
    lv_obj_set_pos( charging, 258, 0 );
    lv_obj_add_style( charging, &charging_style, 0 );
    lv_obj_set_scrollbar_mode( charging, LV_SCROLLBAR_MODE_OFF );
    lv_obj_add_flag( charging, LV_OBJ_FLAG_HIDDEN);
#endif
}

static void xlv_battery_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");
    // lv_obj_set_layout(obj, LV_LAYOUT_FLEX);
    // lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);

    xlv_battery_t *bat = (xlv_battery_t *)obj;
    bat->dir = BATTERY_ROW;
    bat->charging_pos = BATTERY_CHARGING_UP;

    bat->bar = lv_bar_create(obj);
    bat->rect = lv_obj_create(obj);
    bat->bat_header = lv_obj_create(obj);
    bat->charging = lv_img_create(obj);
    
    bat->charging_state = false;
    lv_bar_set_range(bat->bar, 0, 100);

    lv_obj_add_event_cb(obj, xlv_battery_value_changed_event_cb, LV_EVENT_VALUE_CHANGED, bat);

    LV_TRACE_OBJ_CREATE("finished");
}
static void xlv_battery_destructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    LV_TRACE_OBJ_CREATE("finished");
}

static void xlv_battery_value_changed_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_user_data(e);
    xlv_battery_t *menu = (xlv_battery_t *)obj;
#if 0
    xlv_battery_t *b = (xlv_battery_t *)bat;
    if (value > 100)
    {
        value = 100;
    }
    if ( b->dir == BATTERY_ROW )
    {
        lv_coord_t w = lv_obj_get_width( xlv_battery_get_rect( bat ) );
        lv_coord_t lw = lv_obj_get_style_border_width( b->bat, 0 );
        lv_coord_t delta_w = w - lw*2;
        lv_coord_t cw = delta_w / 100.0 * value;
        if (cw > delta_w)
        {
            cw = delta_w;
        }
        lv_coord_t h = lv_obj_get_height( xlv_battery_get_rect( bat ) );
        lv_coord_t ch = (h - lw*2);
        lv_obj_set_width( b->bat_content, cw );
        lv_obj_set_height( b->bat_content, ch );
    }
    else{

    }
#endif
}

static void lv_bat_event(const lv_obj_class_t *class_p, lv_event_t *e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if (res != LV_RES_OK)
        return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    xlv_battery_t *bat = (xlv_battery_t *)obj;
    if (code == LV_EVENT_SIZE_CHANGED)
    {
        lv_coord_t w = lv_obj_get_style_width(obj, LV_PART_MAIN);
        lv_coord_t h = lv_obj_get_style_height(obj, LV_PART_MAIN);

        // bar占90%的位置
        lv_obj_t *bar = xlv_battery_get_bar(obj);
        lv_obj_t *rect = xlv_battery_get_rect(obj);
        // header是bar的1/5
        lv_obj_t *header = xlv_battery_get_header(obj);
        // charging占10%的位置
        lv_obj_t *charging = xlv_battery_get_charging(obj);
        xlv_battery_direction_t dir = xlv_battery_get_direction(obj);
        if (dir == BATTERY_COLUMN)
        {
        }
        else
        {
            lv_coord_t bar_w = LV_PCT(85);
            lv_coord_t header_w = LV_PCT(3);
            lv_coord_t charging_w = LV_PCT(10);
            lv_coord_t header_h = LV_PCT(25);
            lv_coord_t charging_h = LV_PCT(10);
            lv_obj_set_size(bar, bar_w, h);
            lv_obj_set_size(rect, bar_w, h);
            lv_obj_set_size(header, header_w, header_h);
            lv_obj_set_size(charging, 10, 18);
            lv_obj_set_pos(bar, 0, 0);
            lv_obj_set_pos(header, bar_w, LV_PCT(40));
            lv_obj_set_pos(charging, LV_PCT(85), 0);            
        }
    }
}