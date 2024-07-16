#include "../inc/fact_page_align.h"
#include <stdio.h>
#include "../../User/inc/UiRun.h"
#include "../inc/working_page_home.h"
#include "../../res/fonts/language_control.h"
#include "../../res/fonts/lv_i18n.h"

static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        const char *txt = lv_btnmatrix_get_btn_text(obj, id);
    }
}

static void align_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);

        bool was_toggled = lv_btnmatrix_has_btn_ctrl(obj, id, LV_BTNMATRIX_CTRL_CHECKED);

        lv_btnmatrix_clear_btn_ctrl_all(obj, LV_BTNMATRIX_CTRL_CHECKED);
        if (!was_toggled)
        {
            lv_btnmatrix_set_btn_ctrl(obj, id, LV_BTNMATRIX_CTRL_CHECKED);
            lv_btnmatrix_set_selected_btn(obj, id);
        }
    }
}

lv_obj_t* fact_page_algin_init(lv_obj_t *page)
{
    fact_page_align_t *p = lv_mem_alloc(sizeof (fact_page_align_t));
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
    lv_label_set_text(test_label, "FACT-ALIGN");
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
        "label_54", "\n",
        "label_55", "\n",
        "label_56", "\n",
        "label_57", "\n",
        "label_58", "\n",
        "label_59", "\n",
        NULL};

    p->btnm_arm = lv_btnmatrix_create(obj);
    lv_btnmatrix_set_map(p->btnm_arm, map);
    lv_obj_add_style(p->btnm_arm, &bg_style, 0);
    lv_obj_add_style(p->btnm_arm, &style_btn_default, LV_PART_ITEMS);
    lv_obj_add_style(p->btnm_arm, &style_btn_pressed, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_add_event_cb(p->btnm_arm, event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_size(p->btnm_arm, 168, parent_height + parent_height / 7);
    lv_obj_set_pos(p->btnm_arm, 0, 0);

    lv_btnmatrix_set_btn_ctrl_all(p->btnm_arm, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(p->btnm_arm, true);
    lv_btnmatrix_set_btn_ctrl(p->btnm_arm, 0, LV_BTNMATRIX_CTRL_CHECKED);

    p->label_arm_top = lv_label_create(obj);
    p->label_arm_btm = lv_label_create(obj);
    p->label_arm_mid = lv_label_create(obj);
    lv_obj_set_pos(p->label_arm_top, 660, 130);
    lv_obj_set_pos(p->label_arm_btm, 660, 330);
    lv_obj_set_pos(p->label_arm_mid, 660, 230);
    lv_obj_add_style(p->label_arm_top, &bg_style, 0);
    lv_obj_add_style(p->label_arm_btm, &bg_style, 0);
    lv_obj_add_style(p->label_arm_mid, &bg_style, 0);

    lv_label_set_text(p->label_arm_top, "");
    lv_label_set_text(p->label_arm_btm, "");
    lv_label_set_text(p->label_arm_mid, "");

    p->rocker_up = lv_img_create(obj);
    p->rocker_mid = lv_img_create(obj);
    p->rocker_btm = lv_img_create(obj);
    p->rocker_left = lv_img_create(obj);
    p->rocker_right = lv_img_create(obj);

    lv_obj_set_size(p->rocker_up, 43, 75);
    lv_obj_set_size(p->rocker_mid, 23, 6);
    lv_obj_set_size(p->rocker_btm, 43, 75);
    lv_obj_set_size(p->rocker_left, 43, 75);
    lv_obj_set_size(p->rocker_right, 43, 75);

    lv_obj_set_pos(p->rocker_up, 290, 80);
    lv_obj_set_pos(p->rocker_mid, 300, 235);
    lv_obj_set_pos(p->rocker_btm, 290, 310);
    lv_obj_set_pos(p->rocker_left, 290, 80);
    lv_obj_set_pos(p->rocker_right, 290, 310);

//    lv_img_set_src(p->rocker_up, &arm_up);
//    lv_img_set_src(p->rocker_mid, &arm_mid);
//    lv_img_set_src(p->rocker_btm, &arm_down);
//    lv_img_set_src(p->rocker_left, &arm_up);
//    lv_img_set_src(p->rocker_right, &arm_down);

    lv_obj_add_style(p->rocker_up, &bg_style, 0);
    lv_obj_add_style(p->rocker_mid, &bg_style, 0);
    lv_obj_add_style(p->rocker_btm, &bg_style, 0);
    lv_obj_add_style(p->rocker_left, &bg_style, 0);
    lv_obj_add_style(p->rocker_right, &bg_style, 0);

    lv_img_set_angle(p->rocker_left,  2700);
    lv_img_set_angle(p->rocker_right,  2700);

    lv_obj_add_flag( p->rocker_up, LV_OBJ_FLAG_HIDDEN );
    lv_obj_add_flag(p->rocker_btm, LV_OBJ_FLAG_HIDDEN );
    lv_obj_add_flag( p->rocker_left, LV_OBJ_FLAG_HIDDEN );
    lv_obj_add_flag( p->rocker_right, LV_OBJ_FLAG_HIDDEN );

    static lv_style_t bg_style_align;
    lv_style_init(&bg_style_align);
    lv_style_set_bg_color(&bg_style_align, lv_color_make(17, 17, 17));
    lv_style_set_bg_opa(&bg_style_align, LV_OPA_COVER);
    lv_style_set_text_color(&bg_style_align, lv_color_white());
    lv_style_set_pad_all(&bg_style_align, 10);
    lv_style_set_pad_gap(&bg_style_align, 10);
    lv_style_set_border_width(&bg_style_align, 0);

    static const char *align_btn_map[] = {
        "最大值", "\n",
        "零值", "\n",
        "最小值", "\n",
        NULL};

    p->align_btnm = lv_btnmatrix_create(obj);
    lv_btnmatrix_set_map(p->align_btnm, align_btn_map);
    lv_obj_add_style(p->align_btnm, &bg_style_align, 0);
    lv_obj_add_style(p->align_btnm, &style_btn_default, LV_PART_ITEMS);
    lv_obj_add_style(p->align_btnm, &style_btn_pressed, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_add_event_cb(p->align_btnm, align_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_size(p->align_btnm, 168, 100 * 4);
    lv_obj_set_pos(p->align_btnm, 440, 80);

    lv_btnmatrix_set_one_checked(p->align_btnm, false);
    lv_btnmatrix_set_btn_ctrl(p->align_btnm, 1, LV_BTNMATRIX_CTRL_CHECKED);

    return obj;
}

//static void align_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject) {
//    lv_obj_t *page_home = lv_observer_get_target_obj(observer);
//    fact_page_align_t *p = (fact_page_align_t *) observer->user_data;
//    temp_value_t temp_v;
//    temp_value_t temp_vv;
//    uint8_t arm = 0;;
//    temp_v = lv_subject_get_int_from_type(subject, factory_align_selected_cali_arm, 0, pageid_factory);
//    if (temp_v.different_flag)
//    {
//        arm = temp_v.current_value;
//        if(arm > 6) {
//            arm = 6;
//        }
//        lv_btnmatrix_set_btn_ctrl(p->btnm_arm, arm, LV_BTNMATRIX_CTRL_CHECKED);
//
//        if (temp_v.current_value == 7)
//        {
//            lv_obj_add_flag( p->rocker_up, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag(p->rocker_btm, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_clear_flag( p->rocker_left, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_clear_flag( p->rocker_right, LV_OBJ_FLAG_HIDDEN );
//        }
//        else
//        {
//            lv_obj_clear_flag( p->rocker_up, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_clear_flag(p->rocker_btm, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->rocker_left, LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->rocker_right, LV_OBJ_FLAG_HIDDEN );
//        }
//
//        char temp[ 64 ];
//        temp_vv = lv_subject_get_int_from_type(subject, factory_align_max_arr, temp_v.current_value, pageid_factory);
//        sprintf(temp, "0x%4X", temp_vv.current_value);
//        lv_label_set_text(p->label_arm_top, temp);
//
//        temp_vv = lv_subject_get_int_from_type(subject, factory_align_mid_arr, temp_v.current_value,pageid_factory);
//        sprintf(temp, "0x%4X", temp_vv.current_value);
//        lv_label_set_text(p->label_arm_mid, temp);
//
//        temp_vv = lv_subject_get_int_from_type(subject, factory_align_min_arr, temp_v.current_value,pageid_factory);
//        sprintf(temp, "0x%4X", temp_vv.current_value);
//        lv_label_set_text(p->label_arm_btm, temp);
//
//        temp_v = lv_subject_get_int_from_type(subject, factory_align_selected_pos,0, pageid_factory);
//        uint32_t cali_idx = temp_v.current_value;
//        if ( cali_idx > 3 )
//        {
//            cali_idx = 3;
//        }
//        lv_btnmatrix_clear_btn_ctrl_all(p->align_btnm, LV_BTNMATRIX_CTRL_CHECKED);
//        if ( cali_idx != 0 )
//        {
//            lv_btnmatrix_set_btn_ctrl(p->align_btnm, 2 - (cali_idx - 1), LV_BTNMATRIX_CTRL_CHECKED);
//        }
//
//    }
//}

