#include <stdio.h>
#include <math.h>
#include "../inc/working_page_arms.h"
#include "../inc/working_page_home.h"
#include "../../theme/inc/theme_R1100P_white.h"
#include "../../theme/inc/theme_style.h"
#include "../../User/inc/images_v4_0.h"
#include "../../User/inc/UiRun.h"

static lv_style_t style8;

lv_obj_t* working_page_arms_init(lv_obj_t *page)
{
    working_page_arms_t *p = lv_mem_alloc(sizeof (working_page_arms_t));

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    int i;

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);


    static lv_style_t style_mode_bg;
    lv_style_init(&style_mode_bg);
    lv_style_set_bg_color(&style_mode_bg, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_border_width(&style_mode_bg, 6);
    lv_style_set_border_color(&style_mode_bg, lv_color_make(0xde, 0xde, 0xde));
    lv_style_set_bg_opa(&style_mode_bg, LV_OPA_COVER);

    lv_obj_t *g1 = lv_obj_create(obj);
    lv_obj_t *g2 = lv_obj_create(obj);

    lv_obj_set_size(g1, 616, 574);
    lv_obj_set_size(g2, 616, 574);

    lv_obj_set_pos(g1, 16,10);
    lv_obj_set_pos(g2, 648,10);

    //隐藏不选中
    p->mode_bg[0] = lv_obj_create(obj);
    lv_obj_set_size(p->mode_bg[0], 192, 240);
    lv_obj_set_pos(p->mode_bg[0], 27 , 135 - 60);
    lv_obj_add_style(p->mode_bg[0], &style_mode_bg, 0);
    lv_obj_add_flag( p->mode_bg[0], LV_OBJ_FLAG_HIDDEN );

    //状态小背景
    for(i = 1; i < 4; i++ )
    {
        p->mode_bg[i] = lv_obj_create(obj);
        lv_obj_set_size(p->mode_bg[i], 198, 248);
        lv_obj_set_pos(p->mode_bg[i], 26 + ( (i - 1) * 200), 135 - 62);
        lv_obj_add_style(p->mode_bg[i], &style_mode_bg, 0);
    }

    for(i = 4; i < 7; i++ )
    {
        p->mode_bg[i] = lv_obj_create(obj);
        lv_obj_set_size(p->mode_bg[i], 198, 248);
        lv_obj_set_pos(p->mode_bg[i], 26 + ( (i - 4) * 200), 391 - 62);
        lv_obj_add_style(p->mode_bg[i], &style_mode_bg, 0);
    }

    lv_obj_t *temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state1);
    lv_obj_set_pos(temp_state, 27, 135 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "最小姿态" );
    lv_obj_set_pos(temp_state, 75, 332 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state2);
    lv_obj_set_pos(temp_state, 227, 135 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "打底板" );
    lv_obj_set_pos(temp_state, 287 , 332 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state3);
    lv_obj_set_pos(temp_state, 427, 135 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "打高楼" );
    lv_obj_set_pos(temp_state, 499, 332 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state4);
    lv_obj_set_pos(temp_state, 27, 391 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "存储姿态1" );
    lv_obj_set_pos(temp_state, 80, 591 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state5);
    lv_obj_set_pos(temp_state, 227, 391 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "存储姿态2" );
    lv_obj_set_pos(temp_state, 280, 589 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &arms_state6);
    lv_obj_set_pos(temp_state, 427, 391 - 60);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "自定义1" );
    lv_obj_set_pos(temp_state, 480, 589 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "目标形态" );
    lv_obj_set_pos(temp_state, 262, 83 - 60);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_32px_0(), 0);

    // 需要修改   arm_d_a:135px arm_d_b:90px arm_d_c:86px arm_d_d:78px arm_d_e:68px arm_d_f:56px arm_d_g:32px
    p->arm_ground = lv_img_create(obj);
    lv_img_set_src(p->arm_ground, &arm_d_0);
    lv_obj_set_pos(p->arm_ground, 660 , 530);

    p->arm_01 = lv_img_create(obj);
    lv_img_set_src(p->arm_01, &arm_d_a);
    lv_img_set_pivot(p->arm_01, 0, 0);
    lv_obj_set_pos(p->arm_01, 660 + 50  ,530);

    p->arm_02 = lv_img_create(obj);
    lv_img_set_src(p->arm_02, &arm_d_b);
    lv_img_set_pivot(p->arm_02, 0, 0);
    lv_obj_set_pos(p->arm_02, 660 + 50 + 135  ,530);

    p->arm_03 = lv_img_create(obj);
    lv_img_set_src(p->arm_03, &arm_d_c);
    lv_img_set_pivot(p->arm_03, 0, 0);
    lv_obj_set_pos(p->arm_03, 660 + 50 + 135 + 90  ,530 );

    p->arm_04 = lv_img_create(obj);
    lv_img_set_src(p->arm_04, &arm_d_d);
    lv_img_set_pivot(p->arm_04, 0, 0);
    lv_obj_set_pos(p->arm_04, 660 + 50 + 135 + 90 + 86   ,530);

    p->arm_05 = lv_img_create(obj);
    lv_img_set_src(p->arm_05, &arm_d_e);
    lv_img_set_pivot(p->arm_05, 0, 0);
    lv_obj_set_pos(p->arm_05, 660 + 50 + 135 + 90 + 86 + 78   ,530);

    p->arm_06 = lv_img_create(obj);
    lv_img_set_src(p->arm_06, &arm_d_f);
    lv_img_set_pivot(p->arm_06, 0, 0);
    lv_obj_set_pos(p->arm_06, 660 + 50 + 135 + 90 + 86 + 78 + 68   ,530);

    p->arm_07 = lv_img_create(obj);
    lv_img_set_src(p->arm_07, &arm_d_g);
    lv_img_set_pivot(p->arm_07, 0, 0);
    lv_obj_set_pos(p->arm_07, 660 + 50 + 135 + 90 + 86 + 78 + 68 +56   ,530);

    p->arm_p01 = lv_img_create(obj);
    lv_img_set_src(p->arm_p01, &arm_d_1);
    lv_obj_set_pos(p->arm_p01, 660 +39  ,528 );

    p->arm_p02 = lv_img_create(obj);
    lv_img_set_src(p->arm_p02, &arm_d_1);
    lv_obj_set_pos(p->arm_p02, 660 +39 + (135+1) ,528);

    p->arm_p03 = lv_img_create(obj);
    lv_img_set_src(p->arm_p03, &arm_d_2);
    lv_obj_set_pos(p->arm_p03, 660 +39 + (135+1)  + (90+1)   ,528);

    p->arm_p04 = lv_img_create(obj);
    lv_img_set_src(p->arm_p04, &arm_d_2);
    lv_obj_set_pos(p->arm_p04, 660 +39 + (135+1)  + (90+1) + (86+1) ,528);

    p->arm_p05 = lv_img_create(obj);
    lv_img_set_src(p->arm_p05, &arm_d_2);
    lv_obj_set_pos(p->arm_p05, 660 +39 + (135+1)  + (90+1) + (86+1) + (78+1)  ,528);

    p->arm_p06 = lv_img_create(obj);
    lv_img_set_src(p->arm_p06, &arm_d_2);
    lv_obj_set_pos(p->arm_p06, 660 +39 + (135+1)  + (90+1) + (86+1) + (78+1) + (68+1)   ,528);

    p->arm_p07 = lv_img_create(obj);
    lv_img_set_src(p->arm_p07, &arm_d_2);
    lv_obj_set_pos(p->arm_p07, 660 +39 + (135+1)  + (90+1) + (86+1) + (78+1) + (68+1) + (56+1) ,528);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "末端最高：" );
    lv_obj_set_pos(temp_state,  950 , 12);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "末端最低：" );
    lv_obj_set_pos(temp_state,  950  , 12+32);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "末端高度：" );
    lv_obj_set_pos(temp_state, 950, 12 + 32 *2);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    //max min
    p->label_show[0] = lv_label_create(obj);
    lv_label_set_text( p->label_show[0], "0m" );
    lv_obj_set_pos(p->label_show[0], 950 + 115 ,12);
    lv_obj_add_style(p->label_show[0],theme_style_get_label_normal_24px_1(), 0);

    p->label_show[1] = lv_label_create(obj);
    lv_label_set_text( p->label_show[1], "0m" );
    lv_obj_set_pos(p->label_show[1], 950 + 115, 12+32);
    lv_obj_add_style(p->label_show[1],theme_style_get_label_normal_24px_1(), 0);

    p->label_show[2] = lv_label_create(obj);
    lv_label_set_text( p->label_show[2], "0m" );
    lv_obj_set_pos(p->label_show[2], 950 + 115, 12 + 32 *2);
    lv_obj_add_style(p->label_show[2],theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "1臂：" );
    lv_obj_set_pos(temp_state, 1141 , 12 + 32 *1);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "2臂：" );
    lv_obj_set_pos(temp_state, 1141,12 + 32 *2 );
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "3臂：" );
    lv_obj_set_pos(temp_state, 1141 , 12 + 32 *3);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "4臂：" );
    lv_obj_set_pos(temp_state, 1141, 12 + 32 *4);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "5臂：" );
    lv_obj_set_pos(temp_state, 1141, 12 + 32 *5);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "6臂：" );
    lv_obj_set_pos(temp_state, 1141, 12 + 32 *6);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    temp_state = lv_label_create(obj);
    lv_label_set_text( temp_state, "回转：" );
    lv_obj_set_pos(temp_state, 1141 -10, 12);
    lv_obj_add_style(temp_state,theme_style_get_label_normal_24px_1(), 0);

    for (i = 3; i < 9; i++)
    {
        p->label_show[i] = lv_label_create(obj);
        lv_label_set_text( p->label_show[i], "0°" );
        lv_obj_set_pos(p->label_show[i], 1124 + 75, 12+32 + (i-3) * 32);
        lv_obj_add_style(p->label_show[i],theme_style_get_label_normal_24px_1(), 0);
    }

    //回转
    p->label_show[9] = lv_label_create(obj);
    lv_label_set_text( p->label_show[9], "0°" );
    lv_obj_set_pos(p->label_show[9], 1124 + 75, 12);
    lv_obj_add_style(p->label_show[9],theme_style_get_label_normal_24px_1(), 0);

    return obj;
}

static void _set_data(lv_obj_t *label, int32_t v)
{
    char temp[10];
    sprintf(temp, "%.1f°", v / 10.0);
    lv_label_set_text(label, temp);
}

static void _set_data_m(lv_obj_t *label, int32_t v)
{
    char temp[10];
    sprintf(temp, "%.1fm", v / 10.0);
    lv_label_set_text(label, temp);
}

//static void arms_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject)
//{
//#if 1
//    working_page_arms_t *p = (working_page_arms_t *) observer->user_data;
//    static uint8_t mode_choose = 0;
//    static int _count0 = 0;
//    static bool change_flag = false;
//    static uint8_t mode_number = 1;
//    static uint8_t mode_final = 1;
//    temp_value_t powerkey = lv_subject_get_int_from_type(subject, system_paras_power_key, 0, pageid_system);
//    temp_value_t arm_pos_max = lv_subject_get_int_from_type(subject, machine_arm_pos_max, 0, pageid_home);
//    temp_value_t arm_pos_min = lv_subject_get_int_from_type(subject, machine_arm_pos_min, 0, pageid_home);
//    temp_value_t arm_pos = lv_subject_get_int_from_type(subject, machine_arm_pos, 0, pageid_home);
//    temp_value_t arm1_status = lv_subject_get_int_from_type(subject, machine_arm1_status, 0, pageid_home);
//    temp_value_t arm2_status = lv_subject_get_int_from_type(subject, machine_arm2_status, 0, pageid_home);
//    temp_value_t arm3_status = lv_subject_get_int_from_type(subject, machine_arm3_status, 0, pageid_home);
//    temp_value_t arm4_status = lv_subject_get_int_from_type(subject, machine_arm4_status, 0, pageid_home);
//    temp_value_t arm5_status = lv_subject_get_int_from_type(subject, machine_arm5_status, 0, pageid_home);
//    temp_value_t arm6_status = lv_subject_get_int_from_type(subject, machine_arm6_status, 0, pageid_home);
//    temp_value_t arm0_status = lv_subject_get_int_from_type(subject, machine_arm0_status, 0, pageid_home);
//
//    //边框初始化
//    for(int i = 0; i < 7; i++)
//    {
//        lv_obj_set_style_border_color(p->mode_bg[i] ,lv_color_make(0xde, 0xde, 0xde),LV_STATE_DEFAULT);
//    }
//
//    //红框标定选定模式
//    lv_obj_set_style_border_color(p->mode_bg[mode_choose] ,lv_color_make(0xff, 0x00, 0x00),LV_STATE_DEFAULT);
//
//    //绿框标定当前按钮选中模式
//    if (mode_choose != (mode_number+7)%7)
//    {
//        _count0++;
//        if (_count0 >4)
//        {
//            change_flag = !change_flag ;
//            _count0 = 0;
//        }
//        if(change_flag)
//        {
//            lv_obj_set_style_border_color(p->mode_bg[(mode_number+7)%7] ,lv_color_make(0x00, 0xff, 0x00),LV_STATE_DEFAULT);
//            lv_obj_set_style_border_width(p->mode_bg[(mode_number+7)%7], 4,LV_STATE_DEFAULT);
//        }
//        else
//        {
//            lv_obj_set_style_border_color(p->mode_bg[(mode_number+7)%7] ,lv_color_make(0xde, 0xde, 0xde),LV_STATE_DEFAULT);
//            lv_obj_set_style_border_width(p->mode_bg[(mode_number+7)%7], 2,LV_STATE_DEFAULT);
//        }
//    }
//    else
//    {
//        _count0++;
//        if (_count0 >4)
//        {
//            change_flag = !change_flag ;
//            _count0 = 0;
//        }
//        if(change_flag)
//        {
//            lv_obj_set_style_border_color(p->mode_bg[(mode_number+7)%7] ,lv_color_make(0x00, 0xff, 0x00),LV_STATE_DEFAULT);
//            lv_obj_set_style_border_width(p->mode_bg[(mode_number+7)%7], 4,LV_STATE_DEFAULT);
//        }
//        else
//        {
//            lv_obj_set_style_border_color(p->mode_bg[(mode_number+7)%7] ,lv_color_make(0xff, 0x00, 0x00),LV_STATE_DEFAULT);
//            lv_obj_set_style_border_width(p->mode_bg[(mode_number+7)%7], 4,LV_STATE_DEFAULT);
//        }
//    }
//
//    if (powerkey.different_flag && powerkey.current_value == 1)
//    {
//        mode_final = (mode_number+7)%7;
//        mode_choose = mode_final;
//    }
//
//    //刷新实时姿态
//    if (arm_pos_max.different_flag)
//    {
//        _set_data_m(p->label_show[0], arm_pos_max.current_value);
//    }
//
//    if (arm_pos_min.different_flag)
//    {
//        _set_data_m(p->label_show[1], arm_pos_min.current_value);
//    }
//
//    if (arm_pos.different_flag)
//    {
//        _set_data_m(p->label_show[2], arm_pos.current_value);
//    }
//
//    if (arm1_status.different_flag)
//    {
//        _set_data(p->label_show[3], arm1_status.current_value);
//    }
//
//    if (arm2_status.different_flag)
//    {
//        _set_data(p->label_show[4], arm2_status.current_value);
//    }
//
//    if (arm3_status.different_flag)
//    {
//        _set_data(p->label_show[5], arm3_status.current_value);
//    }
//
//    if (arm4_status.different_flag)
//    {
//        _set_data(p->label_show[6], arm4_status.current_value);
//    }
//
//    if (arm5_status.different_flag)
//    {
//        _set_data(p->label_show[7], arm5_status.current_value);
//    }
//
//    if (arm6_status.different_flag)
//    {
//        _set_data(p->label_show[8], arm6_status.current_value);
//    }
//
//    if (arm0_status.different_flag)
//    {
//        _set_data(p->label_show[9], arm0_status.current_value);
//    }
//    //计算每个臂倾角
//
//    int16_t ag[6];
//    double AG[6];
//    int16_t Vx[7],Vy[7],V[7],lg[7] = {0, 135, 90, 86, 78, 68, 56};
//    ag[0] = (int16_t)(arm1_status.current_value / 10 ) ;
//    ag[1] = (int16_t)((arm1_status.current_value + arm2_status.current_value) / 10 );
//    ag[2] = (int16_t)((arm1_status.current_value + arm2_status.current_value + arm3_status.current_value) / 10 );
//    ag[3] = (int16_t)((arm1_status.current_value + arm2_status.current_value + arm3_status.current_value + arm4_status.current_value) / 10 );
//    ag[4] = (int16_t)((arm1_status.current_value + arm2_status.current_value + arm3_status.current_value + arm4_status.current_value
//                       + arm5_status.current_value) / 10 );
//    ag[5] = (int16_t)((arm1_status.current_value + arm2_status.current_value + arm3_status.current_value + arm4_status.current_value
//                       + arm5_status.current_value + arm6_status.current_value) / 10 ) ;
//
//    //计算每个臂倾角弧度
//    for(int i = 0; i < 6; i++)
//    {
//        AG[i] = ag[i]* 3.14 / 180;
//    }
//
//    Vx[0] = 710;
//    Vy[0] = 530;
//
//    for(int i=1; i<7; i++)
//    {
//        Vx[i] = Vx[i-1] + lg[i]*cos(AG[i-1]);
//        Vy[i] = Vy[i-1] - lg[i]*sin(AG[i-1]);
//    }
//
//    lv_img_set_angle(p->arm_01,  -ag[0] * 10);
//
//    lv_obj_set_pos(p->arm_02, Vx[1] , Vy[1]);
//    lv_img_set_angle(p->arm_02,  -ag[1] * 10);
//
//    lv_obj_set_pos(p->arm_03, Vx[2] , Vy[2]);
//    lv_img_set_angle(p->arm_03,  -ag[2] * 10);
//
//    lv_obj_set_pos(p->arm_04, Vx[3] , Vy[3]);
//    lv_img_set_angle(p->arm_04,  -ag[3] * 10);
//
//    lv_obj_set_pos(p->arm_05, Vx[4] , Vy[4]);
//    lv_img_set_angle(p->arm_05,  -ag[4] * 10);
//
//    lv_obj_set_pos(p->arm_06, Vx[5] , Vy[5]);
//    lv_img_set_angle(p->arm_06,  -ag[5] * 10);
//
//    lv_obj_set_pos(p->arm_07, Vx[6] , Vy[6]);
//    lv_img_set_angle(p->arm_07, 900);
//
//    for(int i=1; i<7; i++)
//    {
//        Vx[i] = Vx[i-1] + (lg[i]-1)*cos(AG[i-1]);
//        Vy[i] = Vy[i-1] - (lg[i])*sin(AG[i-1]);
//    }
//
//    lv_obj_set_pos(p->arm_p02, Vx[1] , Vy[1]);
//    lv_obj_set_pos(p->arm_p03, Vx[2] , Vy[2]);
//    lv_obj_set_pos(p->arm_p04, Vx[3] , Vy[3]);
//    lv_obj_set_pos(p->arm_p05, Vx[4] , Vy[4]);
//    lv_obj_set_pos(p->arm_p06, Vx[5] , Vy[5]);
//    lv_obj_set_pos(p->arm_p07, Vx[6] , Vy[6]);
//#endif
//
//}