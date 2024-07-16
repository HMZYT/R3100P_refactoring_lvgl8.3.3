#include "../inc/fact_page_align_displacement.h"
#include <stdio.h>
#include "../../User/inc/UiRun.h"
#include "../inc/working_page_home.h"

static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        const char *txt = lv_btnmatrix_get_btn_text(obj, id);
        LV_UNUSED(txt);
        LV_LOG_USER("%s was pressed\n", txt);
    }
}

static void btn0_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    
    if (code == LV_EVENT_CLICKED)
    {
        fact_page_align_displacement_t *page = lv_event_get_user_data(e);

    }
}

static void btn10_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        fact_page_align_displacement_t *page = lv_event_get_user_data(e);
    }
}

static void btn5_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        fact_page_align_displacement_t *page = lv_event_get_user_data(e);
    
    }
}


lv_obj_t* fact_page_algin_displacement_init(lv_obj_t *page)
{
    fact_page_align_displacement_t *p = lv_mem_alloc(sizeof (fact_page_align_displacement_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style, lv_color_white());
    lv_style_set_pad_all(&bg_style, 0);
    lv_style_set_pad_gap(&bg_style, 0);
    lv_style_set_border_width(&bg_style, 0);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height);
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_add_style(obj, &bg_style, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

#if 0 // for testing

    static lv_style_t style_test;
    lv_style_init(&style_test);
    lv_style_set_text_color(&style_test, lv_color_white());

    lv_obj_t *test_label = lv_label_create(obj);
    lv_label_set_text(test_label, "FACT-ALIGN-DISPLACEMENT");
    lv_obj_set_pos(test_label, 0, 0);
    lv_obj_add_style(test_label, &style_test, 0);
#endif


    static lv_style_t style_btn_default;
    lv_style_init(&style_btn_default);
    lv_style_set_text_color(&style_btn_default, lv_color_black());
    lv_style_set_text_font(&style_btn_default, &working_mode_28px);
    //lv_style_set_bg_image_src(&style_btn_default, &menu_key01);

    static lv_style_t style_btn_pressed;
    lv_style_init(&style_btn_pressed);
    //lv_style_set_bg_image_src(&style_btn_pressed, &menu_key02);

    static const char *map[] = {
        "排量", "\n",
        NULL};

    static const char *map_eng[] = {
            "Displacement", "\n",
            NULL};

    p->btnm = lv_btnmatrix_create(obj);
    lv_btnmatrix_set_map(p->btnm, map);
    lv_obj_add_style(p->btnm, &bg_style, 0);
    lv_obj_add_style(p->btnm, &style_btn_default, LV_PART_ITEMS);
    lv_obj_add_style(p->btnm, &style_btn_pressed, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_add_event_cb(p->btnm, event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_size(p->btnm, 168, 68*2);
    lv_obj_set_pos(p->btnm, 0, 0);
    lv_obj_align(p->btnm, LV_ALIGN_LEFT_MID, 0, 0 );

    lv_btnmatrix_set_btn_ctrl_all(p->btnm, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(p->btnm, true);
    lv_btnmatrix_set_btn_ctrl(p->btnm, 0, LV_BTNMATRIX_CTRL_CHECKED);


    lv_obj_t *displacement_img = lv_img_create( obj );
    //lv_img_set_src( displacement_img, &xxzz );
    lv_obj_set_size( displacement_img, 234, 234 );
    lv_obj_align(displacement_img, LV_ALIGN_CENTER, 100, 0);

    p->btn_0 = lv_btn_create( obj );
    lv_obj_t *label_0 = lv_label_create( p->btn_0 );
    lv_obj_center( label_0 );
    lv_label_set_text( label_0, "label_64" );
    lv_obj_set_size( p->btn_0, 160, 60 );
    lv_obj_set_pos( p->btn_0, 280, 325 );
    lv_obj_add_style(p->btn_0, &style_btn_default, 0);
    lv_obj_add_style(p->btn_0, &style_btn_pressed, LV_STATE_CHECKED);
    lv_obj_add_flag(p->btn_0, LV_OBJ_FLAG_CHECKABLE );
    lv_obj_add_event_cb(p->btn_0, btn0_event_handler, LV_EVENT_CLICKED, page);
 


    p->btn_10 = lv_btn_create( obj );
    lv_obj_t *label_10 = lv_label_create( p->btn_10 );
    lv_obj_center( label_10 );
    lv_label_set_text( label_10, "label_65" );
    lv_obj_set_size( p->btn_10, 160, 60 );
    lv_obj_set_pos( p->btn_10, 555, 325 );
    lv_obj_add_style(p->btn_10, &style_btn_default, 0);
    lv_obj_add_style(p->btn_10, &style_btn_pressed, LV_STATE_CHECKED);
    lv_obj_add_flag(p->btn_10, LV_OBJ_FLAG_CHECKABLE );
    lv_obj_add_event_cb(p->btn_10, btn10_event_handler, LV_EVENT_CLICKED, page);
    

    p->btn_5 = lv_btn_create( obj );
    lv_obj_t *label_5 = lv_label_create( p->btn_5 );
    lv_obj_center( label_5 );
    lv_label_set_text( label_5, "label_66" );
    lv_obj_set_size( p->btn_5, 160, 60 );
    lv_obj_set_pos( p->btn_5, 420, 60 );
    lv_obj_add_style(p->btn_5, &style_btn_default, 0);
    lv_obj_add_style(p->btn_5, &style_btn_pressed, LV_STATE_CHECKED);
    lv_obj_add_flag(p->btn_5, LV_OBJ_FLAG_CHECKABLE );
    lv_obj_add_event_cb(p->btn_5, btn5_event_handler, LV_EVENT_CLICKED, page);


    p->label_v0 = lv_label_create( obj );
    p->label_v10 = lv_label_create( obj );
    p->label_v5 = lv_label_create( obj );

    lv_obj_add_style( p->label_v0, &bg_style, 0 );
    lv_obj_add_style( p->label_v5, &bg_style, 0 );
    lv_obj_add_style( p->label_v10, &bg_style, 0 );

    lv_label_set_text( p->label_v0, "" );
    lv_label_set_text( p->label_v5, "" );
    lv_label_set_text( p->label_v10, "" );

    lv_obj_set_pos( p->label_v0, 300, 295 );
    lv_obj_set_pos( p->label_v10, 605, 295 );
    lv_obj_set_pos( p->label_v5, 460, 30 );

    return obj;
}
//static void align_displacement_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject) {
//    lv_obj_t *page_home = lv_observer_get_target_obj(observer);
//    fact_page_align_displacement_t *p = (fact_page_align_displacement_t *) observer->user_data;
//    temp_value_t temp_v;
//    temp_value_t temp_vv;
//    char temp[ 64 ];
//
//    temp_v = lv_subject_get_int_from_type(subject, factory_align_disp_min, 0, pageid_factory);
//    if (temp_v.different_flag) {
//        sprintf(temp, "0x%4X", temp_v.current_value);
//        lv_label_set_text(p->label_v0, temp);
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, factory_align_disp_mid, 0, pageid_factory);
//    if (temp_v.different_flag) {
//        sprintf(temp, "0x%4X", temp_v.current_value);
//        lv_label_set_text(p->label_v5, temp);
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, factory_align_disp_max, 0, pageid_factory);
//    if (temp_v.different_flag) {
//        sprintf(temp, "0x%4X", temp_v.current_value);
//        lv_label_set_text(p->label_v10, temp);
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, factory_align_disp_selected_pos, 0, pageid_factory);
//    if (temp_v.different_flag) {
//        if ( temp_v.current_value == 0 )
//        {//清除所有选择
//            lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        }
//        else if ( temp_v.current_value == 1 )
//        {//选择 校准-0
//            lv_obj_add_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        }
//        else if (  temp_v.current_value == 2 )
//        {//选择 校准-5
//
//            lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_add_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        }
//        else if (  temp_v.current_value == 3 )
//        {//选择 校准-10
//            lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//            lv_obj_add_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        }
//    }
//
//
//}
//static void _refresh(irc_lcd_page_t *ipage, void *data)
//{
//    fact_page_align_displacement_t *page = (fact_page_align_displacement_t *)ipage;
//    rc_lcd_fact_cali_displacement_data_t *d = (rc_lcd_fact_cali_displacement_data_t *)data;
//
//    char temp[ 64 ];
//
//    sprintf(temp, "0x%4X", d->min);
//    lv_label_set_text(p->label_v0, temp);
//
//    sprintf(temp, "0x%4X", d->mid);
//    lv_label_set_text(p->label_v5, temp);
//
//    sprintf(temp, "0x%4X", d->max);
//    lv_label_set_text(p->label_v10, temp);
//
//
//    if ( d->selected_pos == 0 )
//    {//清除所有选择
//        lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//    }
//    else if ( d->selected_pos == 1 )
//    {//选择 校准-0
//        lv_obj_add_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//    }
//    else if ( d->selected_pos == 2 )
//    {//选择 校准-5
//
//        lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_add_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//    }
//    else if ( d->selected_pos == 3 )
//    {//选择 校准-10
//        lv_obj_clear_state(p->btn_0, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_clear_state(p->btn_5, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//        lv_obj_add_state(p->btn_10, LV_STATE_PRESSED | LV_STATE_CHECKED | LV_STATE_FOCUSED);
//    }
//}
