#include "../inc/off_charging_page_charging.h"
#include <stdlib.h>


lv_obj_t* off_charging_page_charging_init(lv_obj_t *page)
{
    off_charging_page_charging_t *p = lv_mem_alloc(sizeof (off_charging_page_charging_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style, lv_color_white());

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height);
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_add_style(obj, &bg_style, 0);

    p->bat = xlv_battery_create(obj);
    lv_obj_set_size(p->bat, 347, 140);
    lv_obj_center(p->bat);
    xlv_battery_set_default_style(p->bat, 0);
    lv_obj_update_layout(p->bat);

    xlv_battery_set_value(p->bat, 0);
#if 0 // for testing

    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create(obj);
    lv_label_set_text(test_label, "OFF_CHARGING-CHARGING");
    lv_obj_set_pos(test_label, 0, 0);
    lv_obj_add_style(test_label, &style_test, 0);
#endif
    return obj;
}

//static void _refresh(irc_lcd_page_t *page, void *data)
//{
//    rc_lcd_off_charging_data_t *d = (rc_lcd_off_charging_data_t*)data;
//    off_charging_page_charging_t *p = (off_charging_page_charging_t*)page;
//
//    xlv_battery_set_value(p->bat, d->power_level);
//}
