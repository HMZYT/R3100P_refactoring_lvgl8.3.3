#include "../inc/fact_page_full_color.h"
#include <stdlib.h>
#include "../inc/working_page_home.h"

static uint32_t _colors[] = {
    0, 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF, 0x000000};

static lv_style_t color_bg_style;

static void _set_bg_color(uint8_t idx)
{
    if (idx >= sizeof(_colors) / sizeof(uint32_t))
    {
        idx = sizeof(_colors) / sizeof(uint32_t);
    }
    if ( idx == 0 )
    {

    }
    else
    {
        lv_color_t c = lv_color_hex(_colors[idx]);
        lv_style_set_bg_color(&color_bg_style, c);
        lv_obj_report_style_change(&color_bg_style);
    }
}

static void _touch(lv_event_t *event)
{
    if (LV_EVENT_CLICKED == lv_event_get_code(event))
    {
        fact_page_full_color_t *page = lv_event_get_user_data(event);
        if (page->tips)
        {
            lv_obj_add_flag(page->tips, LV_OBJ_FLAG_HIDDEN);
        }
        uint8_t c = (page->color + 1) % (sizeof(_colors) / sizeof(uint32_t));
        page->color = c;
        if ( c == 0 )
        {
            page->color = 0;
            lv_obj_clear_flag(page->tips, LV_OBJ_FLAG_HIDDEN);
            lv_style_set_bg_color(&color_bg_style, lv_color_make(17, 17, 17));
            lv_obj_report_style_change(&color_bg_style);
        }
        else
        {
            _set_bg_color(c);
        }
        
    }
}


//extern lv_group_t *default_group;
lv_obj_t* fact_page_full_color_init(lv_obj_t *page)
{
    fact_page_full_color_t *p = lv_mem_alloc(sizeof (fact_page_full_color_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style, lv_color_white());
    lv_style_set_text_font( &bg_style, &working_mode_28px);

    lv_style_init(&color_bg_style);
    lv_style_set_bg_color(&color_bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&color_bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&color_bg_style, lv_color_white());

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height);
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_add_style(obj, &color_bg_style, 0);

    //lv_group_add_obj(default_group, obj);
    lv_obj_add_event_cb(obj, _touch, LV_EVENT_CLICKED, page);

    p->tips = lv_label_create(obj);
    lv_label_set_text(p->tips, "检测坏点: 触摸屏幕检测坏点。");
    lv_obj_center(p->tips);
    lv_obj_add_style(p->tips, &bg_style, 0);
#if 0 // for testing

    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create(obj);
    lv_label_set_text(test_label, "FACT-FULL-COLOR");
    lv_obj_set_pos(test_label, 0, 0);
    lv_obj_add_style(test_label, &style_test, 0);
#endif
    return obj;
}

//static void _refresh(irc_lcd_page_t *ipage, void *data)
//{
//    fact_page_full_color_t *page = (fact_page_full_color_t *)ipage;
//
//    uint8_t *d = (uint8_t *)data;
//    uint8_t color = d[ 0 ];
//    if ( color > 5 )
//    {
//        color = 5;
//    }
//    p->color = color;
//
//    if ( color == 0 )
//    {//提示页面
//        p->color = 0;
//        lv_obj_clear_flag(p->tips, LV_OBJ_FLAG_HIDDEN);
//        lv_style_set_bg_color(&color_bg_style, lv_color_make(17, 17, 17));
//        lv_obj_report_style_change(&color_bg_style);
//    }
//    else{
//        if (p->tips)
//        {
//            lv_obj_add_flag(p->tips, LV_OBJ_FLAG_HIDDEN);
//        }
//        _set_bg_color(color);
//    }
//
//}

//extern bool key_factory;
//static void _show(irc_lcd_page_t *ipage, bool v)
//{
//    if (!key_factory)
//    {//命令进入的工厂模式
//        return;
//    }
//
//    fact_page_full_color_t *page = (fact_page_full_color_t *)ipage;
//    if ( v )
//    {
//        p->color = 0;
//        lv_obj_clear_flag(p->tips, LV_OBJ_FLAG_HIDDEN);
//        lv_style_set_bg_color(&color_bg_style, lv_color_make(17, 17, 17));
//        lv_obj_report_style_change(&color_bg_style);
//    }
//
//}