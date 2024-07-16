#include "../inc/working_header.h"
#include "../inc/working_page_home.h"

static lv_style_t style[5];

static rc_lcd_header_connection_t *rc_lcd_header_connection_create(lv_obj_t *parent)
{
    rc_lcd_header_connection_t *conn = (rc_lcd_header_connection_t *)malloc(sizeof(rc_lcd_header_connection_t));
    if (!conn)
    {
        return NULL;
    }

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_opa(&bg_style, LV_OPA_0);
    // lv_style_set_bg_color( &bg_style, lv_color_white() );

    // lv_style_set_border_color( &bg_style, lv_color_white() );
    // lv_style_set_border_side(&bg_style, LV_BORDER_SIDE_FULL);
    // lv_style_set_border_width( &bg_style, 2 );
    // lv_style_set_border_opa( &bg_style, LV_OPA_TRANSP );

    for (int i = 0; i < 5; ++i)
    {
        lv_style_init(&style[i]);
        lv_style_set_bg_color(&style[i], lv_color_black());
        lv_style_set_bg_opa(&style[i], LV_OPA_COVER);

    }

    conn->wireless = lv_obj_create(parent);
    lv_obj_set_pos(conn->wireless, 1051 - 30, 8);
    lv_obj_set_size(conn->wireless, 55, 25);
    lv_obj_add_style(conn->wireless, &bg_style, 0);

    conn->r[0] = lv_obj_create(conn->wireless);
    lv_obj_set_size(conn->r[0], 4, 7);
    lv_obj_set_pos(conn->r[0], 10, 20);
    lv_obj_add_style(conn->r[0], &style[0], 0);
    lv_obj_clear_flag(conn->r[0], LV_OBJ_FLAG_SCROLLABLE);

    conn->r[1] = lv_obj_create(conn->wireless);
    lv_obj_set_size(conn->r[1], 4, 11);
    lv_obj_set_pos(conn->r[1], 17, 20 - 4);
    lv_obj_add_style(conn->r[1], &style[1], 0);
    lv_obj_clear_flag(conn->r[1], LV_OBJ_FLAG_SCROLLABLE);

    conn->r[2] = lv_obj_create(conn->wireless);
    lv_obj_set_size(conn->r[2], 4, 16);
    lv_obj_set_pos(conn->r[2], 24, 20 - 9);
    lv_obj_add_style(conn->r[2], &style[2], 0);
    lv_obj_clear_flag(conn->r[2], LV_OBJ_FLAG_SCROLLABLE);

    conn->r[3] = lv_obj_create(conn->wireless);
    lv_obj_set_size(conn->r[3], 4, 20);
    lv_obj_set_pos(conn->r[3], 31, 20 - 13);
    lv_obj_add_style(conn->r[3], &style[3], 0);
    lv_obj_clear_flag(conn->r[3], LV_OBJ_FLAG_SCROLLABLE);

    conn->r[4] = lv_obj_create(conn->wireless);
    lv_obj_set_size(conn->r[4], 4, 25);
    lv_obj_set_pos(conn->r[4], 38, 20 - 18);
    lv_obj_add_style(conn->r[4], &style[4], 0);
    lv_obj_clear_flag(conn->r[4], LV_OBJ_FLAG_SCROLLABLE);

    conn->wirefull = lv_img_create(parent);
    lv_img_set_src(conn->wirefull, &wirefull);
    lv_obj_set_pos(conn->wirefull, 1051, 7);

    lv_obj_add_flag(conn->wireless, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(conn->wirefull, LV_OBJ_FLAG_HIDDEN);


    return conn;
}

static void _set_rf_channel(lv_obj_t *label, uint8_t v) //信道设置
{
    char temp[10];
        sprintf(temp, "%d", v+1);
    lv_label_set_text(label, temp);
}

static void _set_rssi_trans(lv_obj_t *label, uint8_t v)
{
    char temp[10];
		sprintf(temp, "T:%x", v);
		lv_label_set_text(label, temp);
}

static void _set_rssi_recev(lv_obj_t *label, uint8_t v)
{
    char temp[10];
		sprintf(temp, "R:%x", v);
    lv_label_set_text(label, temp);
}

irc_lcd_header_t *working_header_create(lv_obj_t *parent)
{
    working_header_t *h = (working_header_t *)malloc(sizeof(working_header_t));
    if (!h)
    {
        return NULL;
    }
    irc_lcd_header_t *ih = (irc_lcd_header_t *)h;
    irc_lcd_header_init(&h->base, parent);

    static lv_style_t whistle_style;
    lv_style_init(&whistle_style);
    lv_style_set_bg_opa(&whistle_style, LV_OPA_COVER);

    static lv_style_t title_style;
    lv_style_init(&title_style);
    lv_style_set_bg_opa(&title_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&title_style, lv_color_black());
    lv_style_set_text_font(&title_style, &working_mode_36px);

    //创建连接符号
    h->connecter = rc_lcd_header_connection_create(h->base.obj);
    lv_obj_set_size(h->connecter->wireless, 55, 25);
    lv_obj_set_pos(h->connecter->wireless, 1051, 8);

    //创建充电符号
    h->battery = xlv_battery_create(h->base.obj);
    lv_obj_set_size(h->battery, 60, 28);
    lv_obj_set_pos(h->battery, 1152, 10);
    xlv_battery_set_little_style(h->battery);
    xlv_battery_set_charging(h->battery, false);

    //创建电笛
    h->whistle = lv_img_create(h->base.obj);
    lv_img_set_src(h->whistle, &horn_rc_header); //设置图片源
    lv_obj_set_pos(h->whistle, 950, 12);
    lv_img_set_zoom( h->whistle, 180 );
    lv_obj_add_flag(h->whistle, LV_OBJ_FLAG_HIDDEN);

    //创建信号通道显示
    h->channel = lv_label_create(h->base.obj);
    lv_obj_set_size(h->channel, 37, 25);
    lv_obj_set_pos(h->channel, 981, 8);
    lv_obj_add_style(h->channel, &title_style, 0);
    lv_label_set_text(h->channel, "");
    lv_obj_add_flag(h->channel, LV_OBJ_FLAG_HIDDEN);

    h->rssi_trans = lv_label_create(h->base.obj);
    lv_obj_set_size(h->rssi_trans, 100, 25);
    lv_obj_set_pos(h->rssi_trans, 880, 8);
    lv_obj_add_style(h->rssi_trans, &title_style, 0);
    lv_label_set_text(h->rssi_trans, "T");
    lv_obj_add_flag(h->rssi_trans, LV_OBJ_FLAG_HIDDEN);

    h->rssi_recev = lv_label_create(h->base.obj);
    lv_obj_set_size(h->rssi_recev, 100, 25);
    lv_obj_set_pos(h->rssi_recev, 380, 8);
    lv_obj_add_style(h->rssi_recev, &title_style, 0);
    lv_label_set_text(h->rssi_recev, "R");
    lv_obj_add_flag(h->rssi_recev, LV_OBJ_FLAG_HIDDEN);

    static lv_style_t style_ready;
    lv_style_init(&style_ready);
    lv_style_set_bg_color(&style_ready, lv_color_make(0x00, 0xFF, 0x00));
    lv_style_set_bg_opa(&style_ready, LV_OPA_COVER);
    lv_style_set_border_side( &style_ready, 1 );
    lv_style_set_border_color( &style_ready, lv_color_make(0x00, 0xFF, 0x00));
    lv_style_set_border_side( &style_ready, LV_BORDER_SIDE_FULL );
    lv_style_set_border_width( &style_ready, 1);
    lv_style_set_radius( &style_ready, 4) ;

    h->ready = lv_label_create( ih->obj );
    lv_obj_set_pos( h->ready, 250, 10 );
    lv_obj_set_size( h->ready, 78, 26 );
    lv_obj_add_style(h->ready, &style_ready, 0);
    lv_label_set_text( h->ready, "READY" );
    lv_obj_add_flag(h->ready, LV_OBJ_FLAG_HIDDEN);

    return ih;
}

//static void header_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject)
//{
//    working_header_t *h = (working_header_t *) observer->user_data;
//    irc_lcd_header_t *ih = (irc_lcd_header_t *)h;
//    lv_subject_t* header_whistle = lv_subject_get_group_element(subject,0);
//    lv_subject_t* header_wireless_level = lv_subject_get_group_element(subject,1);
//    lv_subject_t* header_wireless = lv_subject_get_group_element(subject,2);
//    lv_subject_t* rc_connected = lv_subject_get_group_element(subject,3);
//    lv_subject_t* fault_total = lv_subject_get_group_element(subject,4);
//    lv_subject_t* title_type = lv_subject_get_group_element(subject,5);
//    lv_subject_t* bat_level = lv_subject_get_group_element(subject,6);
//    lv_subject_t* bat_charging = lv_subject_get_group_element(subject,7);
//    lv_subject_t* rf_channel = lv_subject_get_group_element(subject,8);
//
//    static char *_titles[] = {
//            "label_00",
//            "label_37",
//            "label_20",
//            "label_07",
//            "label_38"};
//
//    if (lv_subject_get_previous_int(header_whistle) != lv_subject_get_int(header_whistle))
//    {
//        if (lv_subject_get_int(header_whistle))
//        { //显示电笛图标
//            lv_obj_clear_flag(h->whistle, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_add_flag(h->whistle, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//
//    if (lv_subject_get_previous_int(header_wireless) != lv_subject_get_int(header_wireless) ||
//        lv_subject_get_previous_int(header_wireless_level) != lv_subject_get_int(header_wireless_level))
//    {
//        if (lv_subject_get_int(header_wireless))
//        { //设置信号
//            if (lv_subject_get_int(header_wireless_level) == 0)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[1], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[2], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[3], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            else if (lv_subject_get_int(header_wireless_level) == 1)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_black());
//                lv_style_set_bg_color(&style[1], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[2], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[3], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            else if (lv_subject_get_int(header_wireless_level) == 2)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_black());
//                lv_style_set_bg_color(&style[1], lv_color_black());
//                lv_style_set_bg_color(&style[2], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[3], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            else if (lv_subject_get_int(header_wireless_level) == 3)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_black());
//                lv_style_set_bg_color(&style[1], lv_color_black());
//                lv_style_set_bg_color(&style[2], lv_color_black());
//                lv_style_set_bg_color(&style[3], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            else if (lv_subject_get_int(header_wireless_level) == 4)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_black());
//                lv_style_set_bg_color(&style[1], lv_color_black());
//                lv_style_set_bg_color(&style[2], lv_color_black());
//                lv_style_set_bg_color(&style[3], lv_color_black());
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            else if (lv_subject_get_int(header_wireless_level) == 5)
//            {
//                lv_style_set_bg_color(&style[0], lv_color_black());
//                lv_style_set_bg_color(&style[1], lv_color_black());
//                lv_style_set_bg_color(&style[2], lv_color_black());
//                lv_style_set_bg_color(&style[3], lv_color_black());
//                lv_style_set_bg_color(&style[4], lv_color_black());
//            }
//            else
//            {
//                lv_style_set_bg_color(&style[0], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[1], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[2], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[3], lv_color_make(177, 177, 177));
//                lv_style_set_bg_color(&style[4], lv_color_make(177, 177, 177));
//            }
//            lv_obj_clear_flag(h->connecter->wireless, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag(h->connecter->wirefull, LV_OBJ_FLAG_HIDDEN);
//
//            //刷新5个框
//        }
//        else
//        {
//            lv_obj_add_flag(h->connecter->wireless, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag(h->connecter->wirefull, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//
//    lv_obj_set_pos(h->connecter->wireless, 657 - 30, 8);
//    if (!lv_subject_get_int(rc_connected))
//    {
//        lv_label_set_text(h->channel, "0");
//    }
//    else
//    {
//        _set_rf_channel(h->channel, lv_subject_get_int(rf_channel));
//    }
//
//    if (!lv_subject_get_int(header_wireless))
//    {
//        lv_obj_add_flag(h->channel, LV_OBJ_FLAG_HIDDEN);
//    }
//    else
//    {
//        lv_obj_clear_flag(h->channel, LV_OBJ_FLAG_HIDDEN);
//    }
//
//    bool fault_page_show = (lv_subject_get_int(fault_total) > 0) ;
//
//    if ( fault_page_show && lv_subject_get_int(title_type) == 4)
//    {//显示错误页面
//        lv_obj_clear_flag(ih->title, LV_OBJ_FLAG_HIDDEN);
//    }
//    else if ( !fault_page_show && lv_subject_get_int(title_type) == 4 )
//    {//不显示错误页面
//        lv_obj_add_flag(ih->title, LV_OBJ_FLAG_HIDDEN);
//    }
//    else{
//        lv_obj_clear_flag(ih->title, LV_OBJ_FLAG_HIDDEN);
//    }
//    language_lv_label_set_text_static(ih->title, _titles[lv_subject_get_int(title_type)]);
//
//    if (lv_subject_get_int(bat_level) != lv_subject_get_previous_int(bat_level))
//    {
//        xlv_battery_set_value(h->battery, lv_subject_get_int(bat_level));
//    }
//
//    if (lv_subject_get_int(bat_charging) != lv_subject_get_previous_int(bat_charging))
//    {
//        xlv_battery_set_charging(h->battery, lv_subject_get_int(bat_charging));
//    }
//}