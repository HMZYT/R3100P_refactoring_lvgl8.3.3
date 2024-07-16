#include "../inc/working_page_rc.h"
#include "../inc/working_page_home.h"

int bg_light_level = 100;

static rocker_t *_create_rocker(lv_obj_t *parent);
static rc_lcd_button_t *_create_button(lv_obj_t *parent);
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v);                //二选一或三选一开关设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked);         //侧边按键设置
static void _button_lock_arm_set_v(lv_obj_t *btn, lv_obj_t *l, uint8_t v); //锁臂按键设置
static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v);  //排量设置
static void _set_rocker(rocker_t *rocker, uint8_t v);


lv_obj_t* working_page_rc_init(lv_obj_t *page)
{
    working_page_rc_t *p = lv_mem_alloc(sizeof (working_page_rc_t));

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    int i = 0;
    for (i = 0; i < 6; ++i)
    {
        p->rockers[i] = _create_rocker(obj);
        lv_obj_set_size(p->rockers[i]->ibase, 101, 181);
        lv_obj_set_pos(p->rockers[i]->ibase, 170 + 120 * i, 173 - 60);

        p->up[i] = lv_label_create(obj);
        p->down[i] = lv_label_create(obj);

        lv_obj_set_pos(p->up[i], 250 + 120 * i, 173 - 70);
        lv_obj_add_flag( p->up[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->up[i], "127" );

        lv_obj_set_pos(p->down[i], 250 + 120 * i, 340 - 70);
        lv_obj_add_flag( p->down[i], LV_OBJ_FLAG_HIDDEN );
        lv_label_set_text( p->down[i], "-127" );
    }

    for (i = 0; i < 6; ++i)
    {
        p->btns[i] = _create_button(obj);
        lv_obj_set_size(p->btns[i]->ibase, 88, 82);
        lv_obj_set_pos(p->btns[i]->ibase, 287 + 97 * i, 501 - 60);
        _button_set_v(p->btns[i], 0);
    }

    p->btn_whistle_and_off = lv_img_create(obj);
    lv_img_set_src(p->btn_whistle_and_off, &control_margin_02);
    lv_obj_set_pos(p->btn_whistle_and_off, 0, 173 - 60);
    lv_obj_set_size(p->btn_whistle_and_off, 32, 86);

    lv_obj_t * tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &horn_rc);
    lv_obj_set_pos( tmp_label, 46, 226 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_power_red);
    lv_obj_set_pos( tmp_label, 46, 159 - 60);

    p->btn_stop = lv_img_create(obj);
    lv_img_set_src(p->btn_stop, &control_margin_02);
    lv_obj_set_pos(p->btn_stop, 0, 510 - 60);
    lv_obj_set_size(p->btn_stop, 32, 86);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_stop );
    lv_obj_set_pos( tmp_label, 46, 520 - 60);

    p->btn_start = lv_img_create(obj);
    lv_img_set_src(p->btn_start, &control_margin_02);
    lv_obj_set_pos(p->btn_start, 0, 420 - 60);
    lv_obj_set_size(p->btn_start, 32, 86);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_start );
    lv_obj_set_pos( tmp_label, 46, 430 - 60 );

    p->btn_replacement = lv_img_create(obj);
    lv_img_set_src(p->btn_replacement, &control_cycle_Bbtn2);
    lv_obj_set_pos(p->btn_replacement, 1040, 490 - 60);
    lv_obj_set_size(p->btn_replacement, 60, 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Bbtn1 );
    lv_obj_set_pos( tmp_label, 1005, 449 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &bbbbb_bump );
    lv_obj_set_pos( tmp_label, 1055, 583 - 60);

    p->btn_lock_arms = lv_img_create(obj);
    lv_img_set_src(p->btn_lock_arms, &control_cycle_Sbtn);
    lv_obj_set_pos(p->btn_lock_arms, 135, 515 - 60);
    lv_obj_set_size(p->btn_lock_arms, 70, 70);

    //锁臂
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &control_cycle_Sbtn_bg);
    lv_obj_set_pos( tmp_label, 102, 480 - 60);

    //锁臂
    tmp_label = lv_img_create(obj);
    lv_img_set_src( tmp_label, &img_arm_lock );
    lv_obj_set_pos( tmp_label, 140, 584 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gh0_v6c2);
    lv_obj_set_pos( tmp_label, 1017, 137 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gh1_v6c2);
    lv_obj_set_pos( tmp_label, 1017, 340 - 60);

    p->arms06a = lv_img_create( obj );
    lv_img_set_src( p->arms06a, &arm_gX1);
    lv_obj_set_pos( p->arms06a, 1157, 150 - 60);
    lv_img_set_zoom(p->arms06a, 200);

    p->arms06b = lv_img_create( obj );
    lv_img_set_src( p->arms06b, &bbbbb_other);
    lv_obj_set_pos( p->arms06b, 1002, 187 - 60);

    p->arms06c = lv_img_create( obj );
    lv_img_set_src( p->arms06c, &button_cycle_red);
    lv_obj_set_pos( p->arms06c, 1038, 224 - 60);
    lv_img_set_zoom(p->arms06c, 120);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a0);
    lv_obj_set_pos( tmp_label, 190, 105 - 60);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b0_v6c2);
    lv_obj_set_pos( tmp_label, 290 , 125 - 60);
    //lv_img_set_zoom(tmp_label, 220);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 0 , 115 - 60);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 1, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 2, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f0);
    lv_obj_set_pos( tmp_label, 430 + 120 * 3, 115 - 60 );
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_a1);
    lv_obj_set_pos( tmp_label, 190, 366 - 60);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_b1_v6c2);
    lv_obj_set_pos( tmp_label, 290 , 316);
    //lv_img_set_zoom(tmp_label, 220);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_c1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 0, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_d1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 1, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_e1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 2, 305);
    //lv_img_set_zoom(tmp_label, 200);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_f1);
    lv_obj_set_pos( tmp_label, 430 + 120 * 3, 305);
    //v_img_set_zoom(tmp_label, 200);

    p->btn_swing_left = lv_img_create(obj);
    lv_img_set_src(p->btn_swing_left, &control_margin_02);
    lv_obj_set_pos(p->btn_swing_left, parent_width - 34, 370 - 60);
    lv_obj_set_size(p->btn_swing_left, 32, 86);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_left);
    lv_obj_set_pos( tmp_label, 1160, 380 - 60);

    p->btn_swing_right = lv_img_create(obj);
    lv_img_set_src(p->btn_swing_right, &control_margin_02);
    lv_obj_set_pos(p->btn_swing_right, parent_width - 34, 470 - 60);
    lv_obj_set_size(p->btn_swing_right, 32, 86);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_swing_right);
    lv_obj_set_pos( tmp_label, 1160, 480 - 60);

    p->btn_emergency = lv_img_create(obj);
    lv_img_set_src(p->btn_emergency, &control_margin_02);
    lv_obj_set_pos(p->btn_emergency, parent_width - 34, 570 - 60);
    lv_obj_set_size(p->btn_emergency, 32, 86);

    tmp_label = lv_label_create(obj);
    lv_obj_set_pos(tmp_label,  parent_width - 104, 600 - 60);
    lv_label_set_text(tmp_label, "急停");
    lv_obj_add_style(tmp_label, theme_style_get_label_normal_32px_red(), 0);

    //位置1
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_down);
    lv_obj_set_pos( tmp_label, 310, 462 - 60 );
    lv_img_set_zoom(tmp_label, 280);

    //位置2
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_up);
    lv_obj_set_pos( tmp_label, 404, 402 );

    //位置3
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &fast_mode);
    lv_obj_set_pos( tmp_label, 501 , 402 );

    //位置4
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &vibrate_on);
    lv_obj_set_pos( tmp_label, 593, 402 );

    //位置5
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gX1);
    lv_obj_set_pos( tmp_label, 687, 392);
    lv_img_set_zoom(tmp_label, 200);

    //位置6
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 786, 402 );

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_strong);
    lv_obj_set_pos( tmp_label, 786 + 10, 402);

    //位置1
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump_up);
    lv_obj_set_pos( tmp_label, 310, 590 - 60);
    lv_img_set_zoom(tmp_label, 280);

    //位置2
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_motor_down);
    lv_obj_set_pos( tmp_label, 404, 530);

    //位置3
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &slow_mode);
    lv_obj_set_pos( tmp_label, 501, 530);

    //位置4
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &vibrate_off);
    lv_obj_set_pos( tmp_label, 593, 530);

    //位置5
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &arm_gX2_v6c2);
    lv_obj_set_pos( tmp_label, 687, 530);

    //位置6
    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_bump);
    lv_obj_set_pos( tmp_label, 786, 530);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &img_eco);
    lv_obj_set_pos( tmp_label, 786 + 10, 530);

    tmp_label = lv_img_create( obj );
    lv_img_set_src( tmp_label, &shutong);
    lv_obj_set_pos( tmp_label, 850, 460);
    lv_img_set_zoom(tmp_label, 280);

    p->backlight_bar = lv_bar_create( obj);
    lv_bar_set_range(p->backlight_bar, 0, 100);
    lv_obj_set_pos(p->backlight_bar, 250, 6);
    lv_obj_set_size(p->backlight_bar, 300, 14);
    lv_obj_set_style_bg_color(p->backlight_bar, lv_color_hex(0xd0d0d0), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(p->backlight_bar, LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_bg_color(p->backlight_bar, lv_color_hex(0x171717), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(p->backlight_bar, LV_OPA_100, LV_PART_INDICATOR);
    lv_bar_set_value(p->backlight_bar, 70, LV_ANIM_ON);
    lv_obj_add_flag( p->backlight_bar, LV_OBJ_FLAG_HIDDEN );

    return obj;
}

//static void rc_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject) {
//    lv_obj_t *page_rc = lv_observer_get_target_obj(observer);
//    working_page_rc_t *p = (working_page_rc_t *) observer->user_data;
//
//    char temp[64];
//    temp_value_t temp_v;
//    temp_value_t temp_vv;
//    temp_value_t temp_vvv;
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_armSupport, 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[0], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {//下降
//            lv_obj_add_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_clear_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->down[0], "-%d", temp_v.current_value);
//        }
//        else
//        {//上升
//            lv_obj_clear_flag( p->up[0], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[0], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[0], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm1 , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[1], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[1], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag( p->down[1], LV_OBJ_FLAG_HIDDEN);
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {
//            lv_obj_add_flag( p->up[1], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag( p->down[1], LV_OBJ_FLAG_HIDDEN);
//            lv_label_set_text_fmt( p->down[1], "-%d", temp_v.current_value);
//        }
//        else
//        {
//            lv_obj_clear_flag( p->up[1], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[1], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[1], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm2 , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[2], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[2], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag( p->down[2], LV_OBJ_FLAG_HIDDEN);
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {
//            lv_obj_add_flag( p->up[2], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag( p->down[2], LV_OBJ_FLAG_HIDDEN);
//            lv_label_set_text_fmt( p->down[2], "-%d", temp_v.current_value);
//        }
//        else
//        {
//            lv_obj_clear_flag( p->up[2], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[2], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[2], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm3 , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[3], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[3], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag( p->down[3], LV_OBJ_FLAG_HIDDEN);
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {
//            lv_obj_add_flag( p->up[3], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag( p->down[3], LV_OBJ_FLAG_HIDDEN);
//            lv_label_set_text_fmt( p->down[3], "-%d", temp_v.current_value);
//        }
//        else
//        {
//            lv_obj_clear_flag( p->up[3], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[3], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[3], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm4 , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[4], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[4], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag( p->down[4], LV_OBJ_FLAG_HIDDEN);
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {
//            lv_obj_add_flag( p->up[4], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag( p->down[4], LV_OBJ_FLAG_HIDDEN);
//            lv_label_set_text_fmt( p->down[4], "-%d", temp_v.current_value);
//        }
//        else
//        {
//            lv_obj_clear_flag( p->up[4], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[4], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[4], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm5 , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_rocker(p->rockers[5], temp_v.current_value);
//        if (temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->up[5], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag( p->down[5], LV_OBJ_FLAG_HIDDEN);
//        }
//        else if (temp_v.current_value <= 0x7F )
//        {
//            lv_obj_add_flag( p->up[5], LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag( p->down[5], LV_OBJ_FLAG_HIDDEN);
//            lv_label_set_text_fmt( p->down[5], "-%d", temp_v.current_value);
//        }
//        else
//        {
//            lv_obj_clear_flag( p->up[5], LV_OBJ_FLAG_HIDDEN );
//            lv_obj_add_flag( p->down[5], LV_OBJ_FLAG_HIDDEN );
//            lv_label_set_text_fmt( p->up[5], "%d", 0xFF - (uint8_t)temp_v.current_value + 1);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_arm6 , 0, pageid_rc);
//    temp_vv = lv_subject_get_int_from_type(subject, rc_arm7 , 0, pageid_rc);
//    if(temp_v.different_flag || temp_vv.different_flag)
//    {
//        float vx, vy;
//        if ( temp_v.current_value <= 0x7F &&  temp_vv.current_value <= 0x7F) //象限4
//        {
//            vy = 0.3543 * temp_v.current_value;
//            vx = 0.3543 * temp_vv.current_value;
//            lv_obj_set_pos( p->arms06c, 658 + vx , 120 + vy);
//            lv_label_set_text_fmt( p->label_dow, "-%d", temp_v.current_value );
//            lv_label_set_text_fmt( p->label_rig, "-%d", temp_vv.current_value );
//        }
//        else if ( temp_v.current_value > 0x7F &&  temp_vv.current_value <= 0x7F )//象限1
//        {
//            vy = 0.3543 * (0xFF-temp_v.current_value +1);
//            vx = 0.3543 * temp_vv.current_value;
//            lv_obj_set_pos( p->arms06c, 658 + vx , 120 - vy);
//            lv_label_set_text_fmt( p->label_dow, "%d", 0xFF - temp_v.current_value + 1);
//            lv_label_set_text_fmt( p->label_rig, "-%d", temp_vv.current_value );
//        }
//        else if ( temp_v.current_value > 0x7F &&  temp_vv.current_value > 0x7F )//象限2
//        {
//            vy = 0.3543 * (0xFF-temp_v.current_value +1);
//            vx = 0.3543 * (0xFF-temp_vv.current_value +1);
//            lv_obj_set_pos( p->arms06c, 658 - vx , 120 - vy);
//            lv_label_set_text_fmt( p->label_dow, "%d", 0xFF - temp_v.current_value + 1);
//            lv_label_set_text_fmt( p->label_rig, "%d", 0xFF - temp_vv.current_value + 1);
//        }
//        else if ( temp_v.current_value <= 0x7F &&  temp_vv.current_value > 0x7F )//象限3
//        {
//            vy = 0.3543 * temp_v.current_value;
//            vx = 0.3543 * (0xFF-temp_vv.current_value +1);
//            lv_obj_set_pos( p->arms06c, 658 - vx , 120 + vy);
//            lv_label_set_text_fmt( p->label_dow, "-%d", temp_v.current_value );
//            lv_label_set_text_fmt( p->label_rig, "%d", 0xFF - temp_vv.current_value + 1);
//        }
//
//        if ( temp_v.current_value == 0 )
//        {
//            lv_obj_add_flag( p->label_dow, LV_OBJ_FLAG_HIDDEN );
//        }
//        else
//        {
//            lv_obj_clear_flag( p->label_dow, LV_OBJ_FLAG_HIDDEN );
//        }
//
//        if ( temp_vv.current_value == 0 )
//        {
//            lv_obj_add_flag( p->label_rig, LV_OBJ_FLAG_HIDDEN );
//        }
//        else
//        {
//            lv_obj_clear_flag( p->label_rig, LV_OBJ_FLAG_HIDDEN );
//        }
//
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, rc_displacement , 0, pageid_rc);
//    if (temp_v.different_flag)
//    {
//        _set_displacement(p->btn_replacement, p->label_displacement, temp_v.current_value);
//    }
//
//    int temp_count = 0;
//    static uint8_t last_lock = 0;
//    for (int nIndex = rc_1; nIndex <= rc_2_3; nIndex++)
//    {
//        temp_count++;
//        temp_v = lv_subject_get_int_from_type(subject, nIndex , 0, pageid_rc);
//        if (temp_v.current_value)
//        {
//            break;
//        }
//    }
//
//
//    uint8_t v[ 7 ] = { 0 };
//    static uint8_t last_v[ 7 ] = { 0 };
//
//    /***************************
//    * BUTTON1: 正反泵
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_ccw , 0, pageid_rc);
//    temp_vv = lv_subject_get_int_from_type(subject, rc_cw , 0, pageid_rc);
//    if (temp_v.different_flag || temp_vv.different_flag)
//    {
//        if (temp_v.current_value)
//        {//下
//            v[ 0 ] = 2;
//        }
//        else if (temp_vv.current_value)
//        {//上
//            v[ 0 ] = 1;
//        }
//        else
//        {//中
//            v[ 0 ] = 0;
//        }
//
//        if ( v[ 0 ] != last_v[ 0 ] )
//        {
//            _button_set_v(p->btns[0], v[ 0 ]);
//            last_v[ 0 ] = v[ 0 ];
//        }
//    }
//
//    /***************************
//    * BUTTON2: PRM
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_rpm_minus , 0, pageid_rc);
//    temp_vv = lv_subject_get_int_from_type(subject, rc_rpm_plus , 0, pageid_rc);
//    if(temp_v.different_flag || temp_vv.different_flag)
//    {
//        if (temp_v.current_value)
//        {//下
//            v[ 1 ] = 2;
//        }
//        else if (temp_vv.current_value)
//        {//上
//            v[ 1 ] = 1;
//        }
//        else
//        {//中
//            v[ 1 ] = 0;
//        }
//
//        if ( v[ 1 ] != last_v[ 3 ] )
//        {
//            _button_set_v(p->btns[1], v[ 1 ]);
//            last_v[ 1 ] = v[ 1 ];
//        }
//
//    }
//
//    /***************************
//    * BUTTON3: 龟兔
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_slow , 0, pageid_rc);
//    if(temp_v.different_flag)
//    {
//        if (temp_v.current_value)
//        {//下
//            v[ 2 ] = 2;
//        }
//        else
//        {//上
//            v[ 2 ] = 1;
//        }
//
//        if ( v[ 2 ] != last_v[ 2 ] )
//        {
//            _button_set_v(p->btns[2], v[ 2 ]);
//            last_v[ 2 ] = v[ 2 ];
//        }
//
//    }
//
//    /***************************
//    * BUTTON4: 减震
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_dampcan_enable , 0, pageid_rc);
//    if(temp_v.different_flag)
//    {
//        if ( temp_v.current_value )
//        {//上
//            v[ 3 ] = 1;
//        }
//        else
//        {//下
//            v[ 3 ] = 2;
//        }
//
//        if ( v[ 3 ] != last_v[ 3 ] )
//        {
//            _button_set_v(p->btns[3], v[ 3 ]);
//            last_v[ 3 ] = v[ 3 ];
//        }
//    }
//
//    /***************************
//    * BUTTON5: 一键展收&&一键布料
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_deploy_retract , 0, pageid_rc);
//    temp_vv = lv_subject_get_int_from_type(subject, rc_pour , 0, pageid_rc);
//    temp_vvv = lv_subject_get_int_from_type(subject, rc_normal , 0, pageid_rc);
//    if(temp_v.different_flag || temp_vv.different_flag || temp_vvv.current_value)
//    {
//        if ( temp_v.current_value )
//        {//下
//            v[ 4 ] = 2;
//        }
//        else if ( temp_vv.current_value )
//        {//上
//            v[ 4 ] = 1;
//        }
//        else if (temp_vvv.current_value)
//        {//中
//            v[ 6 ] = 0;
//        }
//
//        if ( v[ 4 ] != last_v[ 4 ] )
//        {
//            _button_set_v(p->btns[4], v[ 4 ]);
//            last_v[ 4 ] = v[ 4 ];
//        }
//    }
//
//    /***************************
//    * BUTTON6: 强力疏通节能
//    ***************************/
//    temp_v = lv_subject_get_int_from_type(subject, rc_dredge , 0, pageid_rc);
//    temp_vv = lv_subject_get_int_from_type(subject, rc_strong_power , 0, pageid_rc);
//    if(temp_v.different_flag || temp_vv.different_flag)
//    {
//        if ( temp_v.current_value )
//        {//疏通
//            v[ 5 ] = 0;
//        }
//        else if ( temp_vv.current_value )
//        {//强力
//            v[ 5 ] = 1;
//        }
//        else
//        {//节能
//            v[ 5 ] = 2;
//        }
//
//        if ( v[ 5 ] != last_v[ 5 ] )
//        {
//            _button_set_v(p->btns[5], v[ 5 ]);
//            last_v[ 5 ] = v[ 5 ];
//        }
//    }
//    //四周6个按钮 + 锁臂 + 排量 ————todo
//
//    //
//    // if (temp_count != last_lock)
//    // {
//    //     _button_lock_arm_set_v(p->btn_lock_arms, p->label_lock, temp_count);
//    //     last_lock = temp_count;
//    // }
//
//
//    // temp_v = lv_subject_get_int_from_type(subject, rc_engine_stop , 0, pageid_rc);
//    // if (temp_v.different_flag)
//    // {
//    //     _button_side_set_clicked(p->btn_stop, temp_v.current_value);
//    // }
//    //
//    // temp_v = lv_subject_get_int_from_type(subject, rc_start_key , 0, pageid_rc);
//    // if (temp_v.different_flag)
//    // {
//    //     _button_side_set_clicked(p->btn_start, temp_v.current_value);
//    // }
//    //
//    // temp_v = lv_subject_get_int_from_type(subject, rc_horn , 0, pageid_rc);
//    // if (temp_v.different_flag)
//    // {
//    //     _button_side_set_clicked(p->btn_whistle, temp_v.current_value);
//    // }
//    //
//    // temp_v = lv_subject_get_int_from_type(subject, rc_halt , 0, pageid_rc);
//    // if (temp_v.different_flag)
//    // {
//    //     _button_side_set_clicked(p->btn_emergency, temp_v.current_value);
//    // }
//    // temp_v = lv_subject_get_int_from_type(subject, rc_powerkey , 0, pageid_rc);
//    // if (temp_v.different_flag)
//    // {
//    //     _button_side_set_clicked(p->btn_off, temp_v.current_value);
//    // }
//}

static rc_lcd_button_t *_create_button(lv_obj_t *parent)
{
    rc_lcd_button_t *btn = (rc_lcd_button_t *)malloc(sizeof(rc_lcd_button_t));
    if (!btn)
    {
        return NULL;
    }

    btn->ibase = lv_label_create(parent);
    lv_label_set_text(btn->ibase, "");
    btn->v = lv_img_create(btn->ibase);
    lv_img_set_src(btn->v, &control_s_btn02);
    lv_obj_set_pos(btn->v, 0, 0);
    lv_obj_set_size(btn->v, 88, 82);
    lv_obj_clear_flag(btn->ibase, LV_OBJ_FLAG_SCROLLABLE);

    return btn;
}

//二选一或三选一开关设置
static void _button_set_v(rc_lcd_button_t *btn, uint8_t v)
{
    if (v == 0)
    { //中间
        lv_img_set_src(btn->v, &control_s_btn02);
    }
    else if (v == 1)
    { //上
        lv_img_set_src(btn->v, &control_s_btn01);
    }
    else if (v == 2)
    { //下
        lv_img_set_src(btn->v, &control_s_btn03);
    }
    else
    {
        lv_img_set_src(btn->v, &control_s_btn02);
    }
}

//侧边按键设置
static void _button_side_set_clicked(lv_obj_t *btn, bool clicked)
{
    if (clicked)
    {
        lv_img_set_src(btn, &control_margin_01);
    }
    else
    {
        lv_img_set_src(btn, &control_margin_02);
    }
}

//锁臂按键设置
static void _button_lock_arm_set_v(lv_obj_t *btn, lv_obj_t *l, uint8_t v)
{
    static const char *texts[] = {
        "0",
        "1",
        "1+2",
        "1+2+3",
        "2",
        "3",
        "2+3"};
    if (v > 6)
    {
        v = 6;
    }
    lv_label_set_text(l, texts[v]);
    //图片旋转
    lv_img_set_angle(btn, v * 257);
}

static void _set_displacement(lv_obj_t *btn, lv_obj_t *label, uint8_t v) //排量设置
{
    if (v > 127)
    {
        v = 127;
    }
    char temp[10];
    float tv = v / 12.7;
    sprintf(temp, "%.1f", tv);
    lv_label_set_text(label, temp);
    //图片旋转
    lv_img_set_angle(btn, tv * 285);
}

static void _set_rocker(rocker_t *rocker, uint8_t v)
{
    if (v == 0x00)
    { //在中间
        lv_img_set_src(rocker->v, &control_btn02);
        lv_obj_set_pos(rocker->v, 0, 34);
    }
    else if (v <= 0x7F)
    { //下降
        lv_img_set_src(rocker->v, &control_btn04);
        lv_obj_set_pos(rocker->v, 0, 34 + 25);
    }
    else
    { //上升
        lv_img_set_src(rocker->v, &control_btn03);
        lv_obj_set_pos(rocker->v, 0, 34 - 25);
    }
}

rocker_t *_create_rocker(lv_obj_t *parent)
{
    rocker_t *r = (rocker_t *)malloc(sizeof(rocker_t));
    if (!r)
    {
        return NULL;
    }

    r->ibase = lv_label_create(parent);
    lv_label_set_text(r->ibase, "");
    lv_obj_t *bg_img = lv_img_create(r->ibase);
    lv_img_set_src(bg_img, &control_btn01);
    lv_obj_set_pos(bg_img, 0, 0);
    lv_obj_set_size(bg_img, 101, 181);
    lv_obj_clear_flag(r->ibase, LV_OBJ_FLAG_SCROLLABLE);

    r->v = lv_img_create(bg_img);
    lv_img_set_src(r->v, &control_btn02);
    lv_obj_set_pos(r->v, 4, 39);
    lv_obj_set_size(r->v, 91, 82);


    return r;
}
