#include "../inc/working_page_home.h"

static int32_t cal_angel(int32_t data);

lv_obj_t* working_page_home_init(lv_obj_t *page)
{
    working_page_home_t *p = lv_mem_alloc(sizeof (working_page_home_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *g1 = lv_obj_create(obj);
    lv_obj_t *g2 = lv_obj_create(obj);
    lv_obj_t *g3 = lv_obj_create(obj);
    lv_obj_clear_flag(g3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_size(g1, 394, 580);
    lv_obj_set_size(g2, 394, 580);
    lv_obj_set_size(g3, 394, 580);

    lv_obj_set_pos(g1, 27, 71 - 60);
    lv_obj_set_pos(g2, 442, 71 - 60);
    lv_obj_set_pos(g3, 861, 71 - 60);
    
#pragma region g1

    // 发动机转速背景图
    lv_obj_t *engine_rpm_img = lv_img_create(g1);
    lv_img_set_src(engine_rpm_img, &home_rpm);
    lv_obj_set_pos(engine_rpm_img, 108 - 27, 117 - 60);

    // 发动机转速指针
    p->engine_speed_pointer = lv_img_create(g1);
    lv_img_set_src(p->engine_speed_pointer, &home_pin);
    lv_img_set_angle(p->engine_speed_pointer, 1500);
    lv_img_set_pivot(p->engine_speed_pointer, 260 / 2, 260 / 2);
    lv_obj_set_pos(p->engine_speed_pointer, 108 - 27, 117 - 60);

    p->engine_speed_label = lv_label_create(g1);
    lv_obj_add_style(p->engine_speed_label, theme_style_get_label_edit_36px_0(), 0);
    lv_obj_set_pos(p->engine_speed_label, 181 - 27, 220 - 60);
    lv_obj_set_size(p->engine_speed_label, 110, 50);
    lv_label_set_text(p->engine_speed_label, "0");

    // 速度箭头上
    p->speed_up = lv_img_create(g1);
    lv_img_set_src(p->speed_up, &speed_up);
    lv_obj_set_pos(p->speed_up, 44 - 27, 89 - 60);

    // 速度箭头下
    p->speed_down = lv_img_create(g1);
    lv_img_set_src(p->speed_down, &speed_down);
    lv_obj_set_pos(p->speed_down, 357 - 27, 89 - 60);

    // 速度图标
    lv_obj_t *tmp_img;
    tmp_img = lv_img_create(g1);
    lv_img_set_src(tmp_img, &motor_speed);
    lv_obj_set_pos(tmp_img, 32 - 27, 205 - 60);
    lv_img_set_zoom(tmp_img, 220);

    // 当前档位
    tmp_img = lv_img_create(g1);
    lv_img_set_src(tmp_img, &current_level);
    lv_obj_set_pos(tmp_img, 37 - 27, 318 - 60);
    lv_img_set_zoom(tmp_img, 300);

    p->local_level_label = lv_label_create(g1);
    lv_obj_set_pos(p->local_level_label, 106 - 27, 335 - 60);
    lv_obj_add_style(p->local_level_label, theme_style_get_label_normal_36px_0(), 0);
    lv_label_set_text(p->local_level_label, "0");

    // 建议档位->水冷
    tmp_img = lv_img_create(g1);
    lv_img_set_src(tmp_img, &watercold);
    lv_obj_set_pos(tmp_img, 189 - 27, 318 - 60);
    // lv_img_set_zoom(tmp_img, 380);

    p->sug_level_label = lv_label_create(g1);
    lv_obj_set_pos(p->sug_level_label, 261 - 27, 335 - 60);
    lv_obj_add_style(p->sug_level_label, theme_style_get_label_normal_36px_0(), 0);
    lv_label_set_text(p->sug_level_label, "0.0");

    // ECO
    p->eco_img = lv_img_create(g1);
    lv_img_set_src(p->eco_img, &jieneng);
    lv_obj_set_pos(p->eco_img, 345 - 27, 318 - 60);

    // Adblue
    tmp_img = lv_label_create(g1);
    lv_label_set_text(tmp_img, "E");
    lv_obj_set_pos(tmp_img, 72 - 27, 456 - 60);
    lv_obj_add_style(tmp_img, theme_style_get_label_normal_36px_0(), 0);

    tmp_img = lv_label_create(g1);
    lv_label_set_text(tmp_img, "F");
    lv_obj_set_pos(tmp_img, 343 - 27, 457 - 60);
    lv_obj_add_style(tmp_img, theme_style_get_label_normal_36px_0(), 0);

    tmp_img = lv_img_create(g1);
    lv_img_set_src(tmp_img, &adblue);
    lv_obj_set_pos(tmp_img, 178 - 27, 437 - 60);
    lv_img_set_zoom(tmp_img, 300);

    for (int i = 0; i < 10; ++i)
    {
        p->uera_rect[i] = lv_obj_create(g1);
        lv_obj_set_size(p->uera_rect[i], 26, 16);
        lv_obj_set_pos(p->uera_rect[i], 72 - 27 + i * 29, 505 - 60);
        lv_obj_add_style(p->uera_rect[i], theme_style_get_bg_1(), 0);
    }

    p->uera_pos = lv_label_create(g1);
    lv_obj_add_style(p->uera_pos, theme_style_get_label_normal_36px_3(), 0);
    lv_obj_set_pos(p->uera_pos, 248 - 27, 445 - 60);
    lv_label_set_text(p->uera_pos, "0%");

    // oil
    tmp_img = lv_label_create(g1);
    lv_label_set_text(tmp_img, "E");
    lv_obj_set_pos(tmp_img, 74 - 27, 557 - 60);
    lv_obj_add_style(tmp_img, theme_style_get_label_normal_36px_0(), 0);

    tmp_img = lv_label_create(g1);
    lv_label_set_text(tmp_img, "F");
    lv_obj_set_pos(tmp_img, 343 - 27, 557 - 60);
    lv_obj_add_style(tmp_img, theme_style_get_label_normal_36px_0(), 0);

    tmp_img = lv_img_create(g1);
    lv_img_set_src(tmp_img, &oil_pos);
    lv_obj_set_pos(tmp_img, 177 - 27, 543 - 60);

    for (int i = 0; i < 10; ++i)
    {
        p->oil_rect[i] = lv_obj_create(g1);
        lv_obj_set_size(p->oil_rect[i], 26, 16);
        lv_obj_set_pos(p->oil_rect[i], 72 - 27 + i * 29, 604 - 60);
        lv_obj_add_style(p->oil_rect[i], theme_style_get_bg_2(), 0);
    }

    p->oil_pos = lv_label_create(g1);
    lv_obj_add_style(p->oil_pos, theme_style_get_label_normal_36px_4(), 0);
    lv_obj_set_pos(p->oil_pos, 248 - 27, 544 - 60);
    lv_label_set_text(p->oil_pos, "0%");

#pragma endregion g1

#pragma region g2

    // 压力背景图
    lv_obj_t *engine_mpa_img = lv_img_create(g2);
    lv_img_set_src(engine_mpa_img, &home_mpa);
    lv_obj_set_pos(engine_mpa_img, 519 - 442, 116 - 60);

    // 压力指针
    p->pump_press_pointer = lv_img_create(g2);
    lv_img_set_src(p->pump_press_pointer, &home_pin);
    lv_img_set_angle(p->pump_press_pointer, 0);
    lv_img_set_pivot(p->pump_press_pointer, 260 / 2, 260 / 2);
    lv_obj_set_pos(p->pump_press_pointer, 519 - 442, 116 - 60);

    p->pump_press_label = lv_label_create(g2);
    lv_obj_set_pos(p->pump_press_label, 594 - 442, 220 - 60);
    lv_obj_set_size(p->pump_press_label, 110, 50);
    lv_obj_add_style(p->pump_press_label, theme_style_get_label_edit_36px_0(), 0);
    lv_label_set_text(p->pump_press_label, "0.0");

    // 压力图标
    tmp_img = lv_img_create(g2);
    lv_img_set_src(tmp_img, &bump_press0);
    lv_obj_set_pos(tmp_img, 454 - 442, 215 - 60);

    // 打泵方向
    p->pump_pos_neg = lv_img_create(g2);
    lv_img_set_src(p->pump_pos_neg, &bump_stop);
    lv_obj_set_pos(p->pump_pos_neg, 487 - 442, 290 - 60);
    lv_img_set_zoom(p->pump_pos_neg, 300);

    p->bump_direction_label = lv_label_create(g2);
    lv_obj_set_pos(p->bump_direction_label, 581 - 442, 297 - 60);
    lv_obj_add_style(p->bump_direction_label, theme_style_get_label_normal_36px_0(), 0);
    language_lv_label_set_text(p->bump_direction_label, "label_01");

    p->icon_materials = lv_img_create(g2);
    lv_img_set_src(p->icon_materials, &liao_none);
    lv_obj_set_pos(p->icon_materials, 487 - 442, 302 - 60);
    lv_obj_add_flag(p->icon_materials, LV_OBJ_FLAG_HIDDEN);

    // 料矿
    p->icon_materials_label = lv_label_create(g2);
    lv_obj_set_pos(p->icon_materials_label, 581 - 442, 297 - 60);
    lv_obj_add_style(p->icon_materials_label, theme_style_get_label_normal_36px_0(), 0);
    language_lv_label_set_text(p->icon_materials_label, "label_17");
    lv_obj_add_flag(p->icon_materials_label, LV_OBJ_FLAG_HIDDEN);

    p->direction_err = lv_img_create(g2);
    lv_img_set_src(p->direction_err, &err);
    lv_obj_set_pos(p->direction_err, 518 - 442, 322 - 60);
    lv_obj_add_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);

    // 泵油温
    tmp_img = lv_img_create(g2);
    lv_img_set_src(tmp_img, &bump_oil);
    lv_obj_set_pos(tmp_img, 485 - 442, 431 - 60);

    p->bump_oil_tep = lv_label_create(g2);
    lv_obj_set_pos(p->bump_oil_tep, 549 - 442, 450 - 60);
    lv_obj_add_style(p->bump_oil_tep, theme_style_get_label_normal_36px_0(), 0);
    lv_label_set_text(p->bump_oil_tep, "0.0℃");

    // 堵管
    p->duguan = lv_img_create(g2);
    lv_img_set_src(p->duguan, &duguan);
    lv_obj_set_pos(p->duguan, 722 - 442, 445 - 60);
    lv_obj_add_flag(p->duguan, LV_OBJ_FLAG_HIDDEN);

    // 高低压
    p->press_status = lv_img_create(g2);
    lv_img_set_src(p->press_status, &highpress);
    lv_obj_set_pos(p->press_status, 463 - 442, 529 - 60);

    // 风机
    p->wind_status = lv_img_create(g2);
    lv_img_set_src(p->wind_status, &fan0);
    lv_obj_set_pos(p->wind_status, 580 - 442, 529 - 60);

    p->wind_status_emr = lv_img_create(g2);
    lv_img_set_src(p->wind_status_emr, &err);
    lv_obj_set_pos(p->wind_status_emr, 620 - 442, 558 - 60);
    lv_obj_add_flag(p->wind_status_emr, LV_OBJ_FLAG_HIDDEN);

    // 搅拌
    p->jiaoban_status = lv_img_create(g2);
    lv_img_set_src(p->jiaoban_status, &jiaoban_2);
    lv_obj_set_pos(p->jiaoban_status, 707 - 442, 529 - 60);

    p->jiaoban_status_emr = lv_img_create(g2);
    lv_img_set_src(p->jiaoban_status_emr, &err);
    lv_obj_set_pos(p->jiaoban_status_emr, 767 - 442, 558 - 60);
    lv_obj_add_flag(p->jiaoban_status_emr, LV_OBJ_FLAG_HIDDEN);

#pragma endregion g2

#pragma region g3
    // 锁定臂状态
    tmp_img = lv_img_create(g3);
    lv_img_set_src(tmp_img, &car);
    lv_obj_set_pos(tmp_img, 928 - 861, 111 - 60);

    int i;
    for (i = 0; i < 6; i++)
    {
        p->arms_up_lock[i] = lv_img_create(g3);
        lv_img_set_src(p->arms_up_lock[i], &xx_icon);
        lv_img_set_zoom(p->arms_up_lock[i], 160);
        //lv_obj_add_flag(p->arms_up_lock[i], LV_OBJ_FLAG_HIDDEN);

        p->arms_down_lock[i] = lv_img_create(g3);
        lv_img_set_src(p->arms_down_lock[i], &xx_icon);
        lv_img_set_zoom(p->arms_down_lock[i], 160);
        //lv_obj_add_flag(p->arms_down_lock[i], LV_OBJ_FLAG_HIDDEN);

        p->arms_angel[i] = lv_label_create(g3);
        lv_obj_add_style(p->arms_angel[i], theme_style_get_label_normal_20px_2(), 0);
        lv_obj_set_size(p->arms_angel[i], 90, 30);
        lv_label_set_text(p->arms_angel[i], "0°");
    }

    lv_obj_set_pos(p->arms_up_lock[0], 40, 250);
    lv_obj_set_pos(p->arms_up_lock[1], 60, 160);
    lv_obj_set_pos(p->arms_up_lock[2], 95, 80);
    lv_obj_set_pos(p->arms_up_lock[3], 165, 25);
    lv_obj_set_pos(p->arms_up_lock[4], 250, 23);
    lv_obj_set_pos(p->arms_up_lock[5], 320, 70);

    lv_obj_set_pos(p->arms_down_lock[0], 100, 270);
    lv_obj_set_pos(p->arms_down_lock[1], 120, 180);
    lv_obj_set_pos(p->arms_down_lock[2], 150, 110);
    lv_obj_set_pos(p->arms_down_lock[3], 185, 70);
    lv_obj_set_pos(p->arms_down_lock[4], 240, 68);
    lv_obj_set_pos(p->arms_down_lock[5], 270, 95);

    lv_obj_set_pos(p->arms_angel[0], 90, 330);
    lv_obj_set_pos(p->arms_angel[1], 120, 230);
    lv_obj_set_pos(p->arms_angel[2], 145, 145);
    lv_obj_set_pos(p->arms_angel[3], 165, 95);
    lv_obj_set_pos(p->arms_angel[4], 230, 70);
    lv_obj_set_pos(p->arms_angel[5], 290, 85);
    // lock
    p->lock_img = lv_img_create(g3);
    lv_img_set_src(p->lock_img, &mima_3);
    lv_obj_set_pos(p->lock_img, 1031 - 861, 338 - 60);
    lv_obj_add_flag(p->lock_img, LV_OBJ_FLAG_HIDDEN);

    // 危险标志
    p->danger = lv_img_create(g3);
    lv_img_set_src(p->danger, &danger0);
    lv_obj_set_pos(p->danger, 145, 235 - 20);
    lv_img_set_zoom(p->danger, 240);
    lv_obj_add_flag(p->danger, LV_OBJ_FLAG_HIDDEN);

    p->danger_icon = lv_img_create(g3);
    lv_img_set_src(p->danger_icon, &mode_icon0);
    lv_obj_set_pos(p->danger_icon, 60 + 145, 235 - 20);
    lv_img_set_zoom(p->danger_icon, 240);
    lv_obj_add_flag(p->danger_icon, LV_OBJ_FLAG_HIDDEN);

    // 支撑模式
    p->truck = lv_img_create(g3);
    lv_img_set_src(p->truck, &no_mode);
    lv_obj_set_pos(p->truck, 120, 440 - 60);
    lv_img_set_zoom(p->truck, 200);

    // 色块
    p->safety_bg = lv_obj_create(g3);
    lv_obj_set_size(p->safety_bg, 40, 120);
    lv_obj_set_pos(p->safety_bg, 320, 435);
    lv_obj_add_style(p->safety_bg, theme_style_get_bg_0(), 0);

    // 绿色
    p->green_obj = lv_obj_create(g3);
    lv_obj_set_size(p->green_obj, 40, 78);
    lv_obj_set_pos(p->green_obj, 320, 435);
    lv_obj_add_style(p->green_obj, theme_style_get_bg_0(), 0);
    lv_obj_set_style_bg_color(p->green_obj, lv_color_make(0x00, 0xff, 0x00), 0);
    lv_obj_set_style_border_color(p->green_obj, lv_color_make(0x00, 0xff, 0x00), 0);
    //lv_obj_add_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);

    // 黄色
    p->yellow_obj = lv_obj_create(g3);
    lv_obj_set_size(p->yellow_obj, 40, 30);
    lv_obj_set_pos(p->yellow_obj, 320, 78 + 435);
    lv_obj_add_style(p->yellow_obj, theme_style_get_bg_0(), 0);
    lv_obj_set_style_bg_color(p->yellow_obj, lv_color_make(0xff, 0xff, 0x00), 0);
    lv_obj_set_style_border_color(p->yellow_obj, lv_color_make(0xff, 0xff, 0x00), 0);
    //lv_obj_add_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);

    // 红色
    p->red_obj = lv_obj_create(g3);
    lv_obj_set_size(p->red_obj, 40, 12);
    lv_obj_set_pos(p->red_obj, 320, 30 + 78 + 435);
    lv_obj_add_style(p->red_obj, theme_style_get_bg_0(), 0);
    lv_obj_set_style_bg_color(p->red_obj, lv_color_make(0xff, 0x00, 0x00), 0);
    lv_obj_set_style_border_color(p->red_obj, lv_color_make(0xff, 0x00, 0x00), 0);
   // lv_obj_add_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);

    // 回转
    tmp_img = lv_img_create(g3);
    lv_img_set_src(tmp_img, &cycle_angel);
    lv_obj_set_pos(tmp_img, 0 - 10, 470);
    lv_img_set_zoom(tmp_img, 230);

    p->cycle_angel_label = lv_label_create(g3);
    lv_obj_set_pos(p->cycle_angel_label, 85, 510);
    lv_obj_add_style(p->cycle_angel_label, theme_style_get_label_normal_36px_0(), 0);
    lv_label_set_text(p->cycle_angel_label, "0.0°");

    p->cycle_emr = lv_img_create(g3);
    lv_img_set_src(p->cycle_emr, &err);
    lv_obj_set_pos(p->cycle_emr, 55, 500);
    lv_obj_add_flag(p->cycle_emr, LV_OBJ_FLAG_HIDDEN);

    // 臂架油温
    tmp_img = lv_img_create(g3);
    lv_img_set_src(tmp_img, &arm_oil);
    lv_obj_set_pos(tmp_img, 105 - 90, 420);

    p->arm_oil_label = lv_label_create(g3);
    lv_obj_set_pos(p->arm_oil_label, 190 - 90 - 15, 440);
    lv_obj_add_style(p->arm_oil_label, theme_style_get_label_normal_36px_0(), 0);
    lv_label_set_text(p->arm_oil_label, "0.0℃");
#pragma endregion g3

    return obj;
}

//static void home_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject) {
//    lv_obj_t *page_home = lv_observer_get_target_obj(observer);
//    working_page_home_t *p = (working_page_home_t *) observer->user_data;
//
//    char temp[64];
//    temp_value_t temp_v;
//    temp_value_t temp_vv;
//    temp_value_t temp_vvv;
//    /*************************************************************************************
//   * 一区：
//   * - 发动机转速
//   * - 瞬时油耗
//   * - ECO，泵送节能状态
//   * - 排量档位
//   * - 推荐经济档位
//   *************************************************************************************/
//
//#pragma region
//
//    //-----------------------------------------------------------------
//    // 1. 发动机转速
//    //-----------------------------------------------------------------
//    temp_v = lv_subject_get_int_from_type(subject, machine_motor_speed, 0, pageid_home);
//    if (temp_v.current_value > 2500)
//    {
//        temp_v.current_value  = 2500;
//    }
//    if(temp_v.different_flag)
//    {
//        snprintf(temp, 64, "%d", temp_v.current_value);
//        lv_label_set_text(p->engine_speed_label, temp);
//        lv_img_set_angle(p->engine_speed_pointer, temp_v.current_value * 1800.0 / 2500);
//    }
//
//
//    temp_v = lv_subject_get_int_from_type(subject, machine_acc_flag, 0, pageid_home);
//    if (temp_v.different_flag)
//    {
//        if (temp_v.current_value)
//        {
//            lv_img_set_src(p->speed_up, &speed_up_green);
//            lv_img_set_src(p->speed_down, &speed_down);
//        }
//        else
//        {
//            lv_img_set_src(p->speed_up, &speed_up);
//            lv_img_set_src(p->speed_down, &speed_down_green);
//        }
//    }
//
//    temp_v = lv_subject_get_int_from_type(subject, machine_dec_flag, 0, pageid_home);
//    if (temp_v.different_flag)
//    {
//        if (temp_v.current_value)
//        {
//            lv_img_set_src(p->speed_up, &speed_up_green);
//            lv_img_set_src(p->speed_down, &speed_down);
//        }
//        else
//        {
//            lv_img_set_src(p->speed_up, &speed_up);
//            lv_img_set_src(p->speed_down, &speed_down_green);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 2. 排量档位
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_dec_flag, 0, pageid_home);
//    if(temp_v.different_flag)
//    {
//        sprintf(temp, "%.1f",temp_v.current_value / 10.0);
//        lv_label_set_text(p->local_level_label, temp);
//    }
//
//    //-----------------------------------------------------------------
//    // 3. 水冷
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_water_temp, 0, pageid_home);
//    if(temp_v.different_flag)
//    {
//        sprintf(temp, "%d℃", temp_v.current_value -40);
//        lv_label_set_text(p->sug_level_label, temp);
//    }
//
//    //-----------------------------------------------------------------
//    // 4. 疏通强力节能
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_pump_mode, 0, pageid_home);
//    if(temp_v.different_flag)
//    {
//        if (temp_v.current_value == 2 )
//        { //疏通
//            lv_img_set_src(p->eco_img, &shutong);
//        }
//        else if(temp_v.current_value == 1 )
//        {//强力
//            lv_img_set_src(p->eco_img, &qiangli);
//        }
//        else if(temp_v.current_value == 3  )
//        {//节能
//            lv_img_set_src(p->eco_img, &jieneng);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 5. 油位
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_oil_pos, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if ( temp_v.current_value > 100 )
//        {
//            lv_label_set_text_fmt( p->oil_pos, "--%%", temp_v.current_value );
//        }
//        else
//        {
//            lv_label_set_text_fmt( p->oil_pos, "%d%%", temp_v.current_value );
//        }
//
//        uint8_t nn =temp_v.current_value / 10 + (temp_v.current_value % 10 ? 1: 0);
//        if ( nn > 10 )
//        {
//            nn = 10;
//        }
//        uint8_t mm =  nn;
//
//        for ( int i = 0; i < mm; ++i )
//        {
//            lv_obj_remove_style( p->oil_rect[ i ],theme_style_get_bg_0(), 0 );
//            lv_obj_add_style( p->oil_rect[ i ], theme_style_get_bg_2(), 0);
//        }
//        for ( int i = mm; i < 10; ++i )
//        {
//            lv_obj_remove_style( p->oil_rect[ i ],theme_style_get_bg_2(), 0 );
//            lv_obj_add_style( p->oil_rect[ i ], theme_style_get_bg_0(), 0);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 6. 尿素液位
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_urea_pos, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value > 100 )
//        {
//            lv_label_set_text_fmt( p->uera_pos, "--%%", temp_v.current_value );
//        }
//        else
//        {
//            lv_label_set_text_fmt( p->uera_pos, "%d%%", temp_v.current_value );
//        }
//
//
//        uint8_t n = temp_v.current_value / 10 + (temp_v.current_value % 10 ? 1: 0);
//        if ( n > 10 )
//        {
//            n = 10;
//        }
//        uint8_t m =  n;
//
//        for ( int j = 0; j < m; ++j )
//        {
//            lv_obj_remove_style( p->uera_rect[ j ],theme_style_get_bg_0(), 0 );
//            lv_obj_add_style( p->uera_rect[ j ], theme_style_get_bg_1(), 0);
//        }
//        for ( int j = m; j < 10; ++j )
//        {
//            lv_obj_remove_style( p->uera_rect[ j ],theme_style_get_bg_1(), 0 );
//            lv_obj_add_style( p->uera_rect[ j ], theme_style_get_bg_0(), 0);
//        }
//    }
//    //-----------------------------------------------------------------
//    // 7. 泵送压力
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_pumping_pressure, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if ( temp_v.current_value > 600 )
//        {
//            temp_v.current_value = 600;
//        }
//        snprintf(temp, 64, "%.1f", temp_v.current_value / 10.0);
//        lv_label_set_text(p->pump_press_label, temp);
//
//        lv_img_set_angle(p->pump_press_pointer, temp_v.current_value / 10.0 * 1800.0 / 60);
//    }
//    //-----------------------------------------------------------------
//    // 8. 正反泵
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_cw, 0,pageid_home);
//    temp_vv = lv_subject_get_int_from_type(subject, machine_ccw, 0,pageid_home);
//    if(temp_v.different_flag || temp_vv.different_flag) {
//        if (temp_v.current_value)
//        { //正泵
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src(p->pump_pos_neg, &bump_up );
//        }
//        else if (temp_vv.current_value)
//        { //反泵
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src(p->pump_pos_neg, &bump_down);
//        }
//        else
//        {
//            //lv_obj_add_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src(p->pump_pos_neg, &bump_stop);
//        }
//    }
//    if (temp_v.current_value == 0 && temp_vv.current_value == 0 ) //补充情况 （初始化值都为0，上面else跑不进）
//    {
//        //lv_obj_add_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//        lv_img_set_src(p->pump_pos_neg, &bump_stop);
//    }
//
//    temp_v =  lv_subject_get_int_from_type(subject, machine_emr, 0 ,pageid_home);
//    if(temp_v.different_flag) {
//        if ( temp_v.current_value == 0 )
//        {//关闭
//            lv_obj_add_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//        else if ( temp_v.current_value == 1 )
//        {//左主缸
//            lv_obj_clear_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//        else if ( temp_v.current_value == 2 )
//        {//右主缸
//            lv_obj_clear_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//        else if ( temp_v.current_value == 3 )
//        {//水箱
//            lv_obj_clear_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//        else if ( temp_v.current_value == 4 )
//        {//无传感
//            lv_obj_clear_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//        else{
//            lv_obj_clear_flag(p->direction_err, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 9. 物料状态
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_materials, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if ( temp_v.current_value == 0 )
//        {//不显示n
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src( p->icon_materials, &liao_none  );
//        }else if ( temp_v.current_value == 1 ){//1：可泵性好
//            //压力值不再闪烁，且颜色为绿色
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src( p->icon_materials, &liao_good  );
//        }else if ( temp_v.current_value == 2 ){//2：可泵性一般
//            //压力值不再闪烁，且颜色为绿色
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src( p->icon_materials, &liao_common );
//        }else if ( temp_v.current_value == 3 ){//3：可泵性差
//            //料况差时，图标为红色，压力值为红色，图标以及压力值以1s频率闪烁
//            lv_obj_clear_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//            lv_img_set_src( p->icon_materials, &liao_err );
//        }else{
//            //lv_obj_add_flag( p->icon_materials, LV_OBJ_FLAG_HIDDEN );
//        }
//    }
//    //-----------------------------------------------------------------
//    // 10. 泵送频率
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_pump_freq, 0, pageid_home);
//    if(temp_v.different_flag) {
//        snprintf(temp, 64, "%d次/min",temp_v.current_value );
//        lv_label_set_text(p->bump_direction_label, temp);
//    }
//    //-----------------------------------------------------------------
//    // 11. 泵送油温
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_pump_temperature, 0, pageid_home);
//    if(temp_v.different_flag) {
//        sprintf(temp, "%.1f℃", temp_v.current_value / 10.0);
//        lv_label_set_text(p->bump_oil_tep, temp);
//    }
//
//    //-----------------------------------------------------------------
//    // 12. 堵管报警
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_blocking, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value  >= 2 )
//        {
//            lv_obj_clear_flag( p->duguan, LV_OBJ_FLAG_HIDDEN );
//        }
//        else
//        {
//            lv_obj_add_flag( p->duguan, LV_OBJ_FLAG_HIDDEN );
//        }
//    }
//    //-----------------------------------------------------------------
//    // 13. 高低压
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_pressure, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value)
//        { //高压
//            lv_obj_clear_flag(p->press_status, LV_OBJ_FLAG_HIDDEN);
//            lv_img_set_src(p->press_status, &highpress);
//        }
//        else
//        { //低压
//            lv_obj_clear_flag(p->press_status, LV_OBJ_FLAG_HIDDEN);
//            lv_img_set_src(p->press_status, &lowpress);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 14.风机
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_fan_manual, 0, pageid_home);
//    temp_vv =  lv_subject_get_int_from_type(subject, machine_fan_auto, 0, pageid_home);
//    temp_vvv =  lv_subject_get_int_from_type(subject, machine_fan_close, 0, pageid_home);
//    if(temp_v.different_flag || temp_vv.different_flag || temp_vvv.different_flag) {
//        if (temp_v.current_value)
//        {
//            lv_img_set_src(p->wind_status, &fan0);
//        }
//        if (temp_vv.current_value)
//        {
//            lv_img_set_src(p->wind_status, &fan1);
//        }
//        if (temp_vvv.current_value)
//        {
//            lv_img_set_src(p->wind_status, &fan2);
//        }
//    }
//    //风机应急
//    temp_v =  lv_subject_get_int_from_type(subject, machine_fan_emr, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value)
//        {
//            lv_obj_clear_flag(p->wind_status_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_add_flag(p->wind_status_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//    //-----------------------------------------------------------------
//    // 15. 正反搅拌
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_mixer_cw, 0, pageid_home);
//    temp_vv =  lv_subject_get_int_from_type(subject, machine_mixer_ccw, 0, pageid_home);
//    if(temp_v.different_flag || temp_vv.different_flag ) {
//        if (temp_v.current_value)
//        { //正搅拌
//            lv_obj_clear_flag(p->jiaoban_status, LV_OBJ_FLAG_HIDDEN);
//            //lv_img_set_src(p->jiaoban_status, &jiaoban_status_rig); //gggyf
//        }
//        else if ( temp_vv.current_value )
//        { //反搅拌
//            lv_obj_clear_flag(p->jiaoban_status, LV_OBJ_FLAG_HIDDEN);
//            //lv_img_set_src(p->jiaoban_status, &jiaoban_status_left);//gggyf
//        }
//        else
//        { //低压
//            lv_obj_clear_flag(p->jiaoban_status, LV_OBJ_FLAG_HIDDEN);
//            //lv_img_set_src(p->jiaoban_status, &jiaoban_status_stop);//gggyf
//        }
//    }
//    //搅拌应急
//    temp_v =  lv_subject_get_int_from_type(subject, machine_mixer_emr, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value)
//        {
//            lv_obj_clear_flag(p->jiaoban_status_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_add_flag(p->jiaoban_status_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//    //-----------------------------------------------------------------
//    //16. 锁臂使能
//    //-----------------------------------------------------------------
//    for (int i = machine_arm0_cw_en; i <= machine_arm5_ccw_en;i++) {
//        temp_v =  lv_subject_get_int_from_type(subject, i, 0, pageid_home);
//        if (temp_v.current_value == 0) {
//            lv_obj_clear_flag(p->lock_img, LV_OBJ_FLAG_HIDDEN);
//            break;
//        }
//        if((i == machine_arm5_ccw_en) && (temp_v.current_value != 0)) {
//            lv_obj_add_flag(p->lock_img, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//
//    //-----------------------------------------------------------------
//    // 17. 锁臂
//    //-----------------------------------------------------------------
//    //上
//    for(int i = machine_arm1_cw_en; i <=  machine_arm5_cw_en; i++) {
//        temp_v =  lv_subject_get_int_from_type(subject, i, 0, pageid_home);
//        if(temp_v.different_flag) {
//            if(temp_v.current_value == 0)
//            {
//                lv_obj_clear_flag(p->arms_up_lock[4-(machine_arm5_cw_en-i)], LV_OBJ_FLAG_HIDDEN);
//            }else{
//                lv_obj_add_flag(p->arms_up_lock[4-(machine_arm5_cw_en-i)], LV_OBJ_FLAG_HIDDEN);
//            }
//        }
//    }
//    //下
//    for(int i = machine_arm1_ccw_en; i <=  machine_arm5_ccw_en; i++) {
//        temp_v =  lv_subject_get_int_from_type(subject, i, 0, pageid_home);
//        if(temp_v.different_flag) {
//            if(temp_v.current_value == 0)
//            {
//                lv_obj_clear_flag(p->arms_down_lock[4-(machine_arm5_ccw_en-i)], LV_OBJ_FLAG_HIDDEN);
//            }else{
//                lv_obj_add_flag(p->arms_down_lock[4-(machine_arm5_ccw_en-i)], LV_OBJ_FLAG_HIDDEN);
//            }
//        }
//    }
//    //-----------------------------------------------------------------
//    // 18. 角度
//    //-----------------------------------------------------------------
//    int32_t data_t = 0;
//    for(int i = machine_arm1_status; i <=  machine_arm5_status; i++) {
//        temp_v =  lv_subject_get_int_from_type(subject, i, 0, pageid_home);
//        data_t = data_t +temp_v.current_value;
//        sprintf(temp, "%d°", cal_angel(data_t) / 10);
//        lv_label_set_text(p->arms_angel[4-(machine_arm5_status-i)], temp);
//    }
//
//    //-----------------------------------------------------------------
//    // 19. 支撑模式
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_support_mode, 0, pageid_home);
//    if(temp_v.different_flag) {
//        // if (temp_v.current_value == 1)
//        // { //全支撑模式
//        //     //lv_label_set_text(p->arm_support_label, "全支撑");
//        //     lv_img_set_src( p->truck, &bus_status_1 );
//        // }
//        // else if (temp_v.current_value == 2)
//        // { //左支撑模式
//        //     //lv_label_set_text(p->arm_support_label, "左支撑");
//        //     lv_img_set_src( p->truck, &bus_status_7 );
//        // }
//        // else if (temp_v.current_value == 3)
//        // { //右支撑模式
//        //     //lv_label_set_text(p->arm_support_label, "右支撑");
//        //     lv_img_set_src( p->truck, &bus_status_5 );
//        // }
//        // else if (temp_v.current_value == 4)
//        // { //前支撑模式
//        //     //lv_label_set_text(p->arm_support_label, "前支撑");
//        //     lv_img_set_src( p->truck, &bus_status_3 );
//        // }
//        // else if (temp_v.current_value == 5)
//        // { //小支撑模式???
//        //     //lv_label_set_text(p->arm_support_label, "小支撑");
//        //     lv_img_set_src( p->truck, &bus_status_2 );
//        // }
//        // else if (temp_v.current_value == 6)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "一级腿");
//        //     lv_img_set_src( p->truck, &bus_status_2 );
//        // }
//        // else if (temp_v.current_value == 7)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "左前");
//        //     lv_img_set_src( p->truck, &bus_status_8 );
//        // }
//        // else if (temp_v.current_value == 8)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "右前");
//        //     lv_img_set_src( p->truck, &bus_status_6 );
//        // }
//        // else if (temp_v.current_value == 9)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "两级腿");
//        //     lv_img_set_src( p->truck, &bus_status_2 );
//        // }
//        // else if (temp_v.current_value == 10)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "任意支撑");
//        //     lv_img_set_src( p->truck, &bus_status_4 );
//        // }
//        // else if (temp_v.current_value == 100)
//        // {
//        //     //lv_label_set_text(p->arm_support_label, "RPC");
//        //     lv_img_set_src( p->truck, &bus_status_9 );
//        // }
//        // else
//        // { //无支撑模式
//        //     //lv_label_set_text(p->arm_support_label, "无支撑");
//        //     lv_img_set_src( p->truck, &bus_status_0 );
//        // }
//    }
//    //-----------------------------------------------------------------
//    // 20. 臂架液压油温
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_arms_temperature, 0, pageid_home);
//    if(temp_v.different_flag) {
//        sprintf(temp, "%.1f℃",temp_v.current_value / 10.0);
//        lv_label_set_text(p->arm_oil_label, temp);
//    }
//    //-----------------------------------------------------------------
//    // 21. 回转角度
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_arm0_status, 0, pageid_home);
//    if(temp_v.different_flag) {
//        sprintf(temp, "%.1f°", temp_v.current_value / 10.0);
//        lv_label_set_text(p->cycle_angel_label, temp);
//    }
//    temp_v =  lv_subject_get_int_from_type(subject, machine_cw_emr, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value)
//        {
//            lv_obj_clear_flag(p->cycle_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_add_flag(p->cycle_emr, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//    //-----------------------------------------------------------------
//    // 22. 危险等级
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_support_mode, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value == 1)
//        {
//            lv_img_set_src(p->danger, & danger0);
//        }
//        else if (temp_v.current_value == 2)
//        {
//            lv_img_set_src(p->danger, &danger1);
//        }
//        else if (temp_v.current_value == 3)
//        {
//            lv_img_set_src(p->danger, &danger2);
//        }
//        else if (temp_v.current_value == 4)
//        {
//            lv_img_set_src(p->danger, &danger3);
//        }
//
//        if (temp_v.current_value == 0)
//        {
//            lv_obj_add_flag(p->danger, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_clear_flag(p->danger, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//    //-----------------------------------------------------------------
//    // 23. 塌陷
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_collapse_logo, 0, pageid_home);
//    if(temp_v.different_flag) {
//        if (temp_v.current_value == 1)
//        {
//            lv_img_set_src(p->danger_icon, &mode_icon0);
//        }
//        else if (temp_v.current_value == 2)
//        {
//            lv_img_set_src(p->danger_icon, &mode_icon1);
//        }
//        else if (temp_v.current_value == 3)
//        {
//            lv_img_set_src(p->danger_icon, &mode_icon2);
//        }
//        else if (temp_v.current_value == 4)
//        {
//            lv_img_set_src(p->danger_icon, &mode_icon3);
//        }
//
//        if (temp_v.current_value == 0)
//        {
//            lv_obj_add_flag(p->danger_icon, LV_OBJ_FLAG_HIDDEN);
//        }
//        else
//        {
//            lv_obj_clear_flag(p->danger_icon, LV_OBJ_FLAG_HIDDEN);
//        }
//    }
//    //-----------------------------------------------------------------
//    // 24. 安全系数
//    //-----------------------------------------------------------------
//    temp_v =  lv_subject_get_int_from_type(subject, machine_support_mode, 0, pageid_home);
//    temp_vv =  lv_subject_get_int_from_type(subject, machine_safe_k, 0, pageid_home);
//    if(temp_v.current_value == 10) {
//        lv_obj_clear_flag(p->safety_bg, LV_OBJ_FLAG_HIDDEN);
//        if(temp_vv.different_flag) {
//            if(temp_vv.current_value > 200)
//			{
//					temp_vv.current_value = 200;
//			}
//			if(temp_vv.current_value == 0)
//			{
//					lv_obj_add_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_add_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_add_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);
//			}
//			if(temp_vv.current_value >= 100 && temp_vv.current_value <= 110)
//			{
//					lv_obj_add_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_add_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_clear_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);
//
//					lv_obj_set_size(p->red_obj, 35, 80*(temp_vv.current_value - 100)/100.0 );
//					lv_obj_set_pos(p->red_obj, 65 + 145, 275 + 52 + 20 + (8 - 80*(temp_vv.current_value - 100)/100.0)) ;
//			}
//			else if(temp_vv.current_value > 110 && temp_vv.current_value <= 135)
//			{
//					lv_obj_add_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_clear_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_clear_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);
//
//					lv_obj_set_size(p->red_obj, 35, 8);
//					lv_obj_set_pos(p->red_obj, 65 + 145, 275 + 52 + 20);
//
//					lv_obj_set_size(p->yellow_obj, 35, 80*(temp_vv.current_value - 110)/100.0 );
//					lv_obj_set_pos(p->yellow_obj, 65 + 145, 275 + 52 + (20 - 80*(temp_vv.current_value - 110)/100.0)) ;
//			}
//			else if(temp_vv.current_value > 135 && temp_vv.current_value <= 200)
//			{
//					lv_obj_clear_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_clear_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);
//					lv_obj_clear_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);
//
//					lv_obj_set_size(p->red_obj, 35, 8);
//					lv_obj_set_pos(p->red_obj, 65 + 145, 275 + 52 + 20);
//
//					lv_obj_set_size(p->yellow_obj, 35, 20);
//					lv_obj_set_pos(p->yellow_obj, 65 + 145, 275 + 52);
//
//					lv_obj_set_size(p->green_obj, 35, 80*(temp_vv.current_value - 135)/100.0);
//					lv_obj_set_pos(p->green_obj, 65 + 145, 275 + (52 - 80*(temp_vv.current_value - 135)/100.0));
//			}
//        }
//        else
//        {
//            lv_obj_add_flag(p->safety_bg, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag(p->green_obj, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag(p->yellow_obj, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_add_flag(p->red_obj, LV_OBJ_FLAG_HIDDEN);
//        }
//
//    }
//
//
//
//
//#pragma endregion
//}


static int32_t cal_angel(int32_t data)
{
    while ( data < -1800)
    {
        data = data + 3600;
    }
    while ( data >= 1800)
    {
        data = data - 3600;
    }
    return data;
}