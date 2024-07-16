#ifndef __WORKING_PAGE_ANTIPPING_H__
#define __WORKING_PAGE_ANTIPPING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct{
    lv_obj_t *current_label;		
    lv_obj_t *mode_label;
    lv_obj_t *mode_img;
    lv_obj_t *down_leg;
    lv_obj_t *leg_1;
    lv_obj_t *leg_2;
    lv_obj_t *leg_3;
    lv_obj_t *leg_4;
    lv_obj_t *leg_1_level;
    lv_obj_t *leg_2_level;
    lv_obj_t *leg_3_level;
    lv_obj_t *leg_4_level;
    lv_obj_t *leg_1_level_label;
    lv_obj_t *leg_2_level_label;
    lv_obj_t *leg_3_level_label;
    lv_obj_t *leg_4_level_label;
    lv_obj_t *red_obj;
    lv_obj_t *yellow_obj;
    lv_obj_t *green_obj;
    lv_obj_t *safety_bg;
    lv_obj_t *rec1[7];
    lv_obj_t *rec2[7];
    lv_obj_t *rec3[7];
    lv_obj_t *rec4[7];

    lv_obj_t *bubble;
    lv_obj_t *label_warning1;
    lv_obj_t *label_warning2;
    lv_obj_t *label_warning3;

    
    lv_obj_t *tip_left_up;
    lv_obj_t *tip_left_down;
    lv_obj_t *tip_right_up;
    lv_obj_t *tip_right_down;
    lv_obj_t *tip_tover;
    lv_obj_t *tip_icon;
    lv_obj_t *legs[4];
    lv_obj_t *leg_tover;

    lv_obj_t *g2;
    lv_obj_t *title_text;
    lv_obj_t *title_icon;

    lv_obj_t *rk_tip;
    lv_obj_t *rk_icon;
    lv_obj_t *rk_bar;

    lv_obj_t *arms_up[8];
    lv_obj_t *arms_up_lock[8];
    lv_obj_t *arms_down[8];
    lv_obj_t *arms_down_lock[8];

    lv_obj_t *warning_title;
    lv_obj_t *warning_content1;
    lv_obj_t *warning_content2;
    lv_obj_t *warning1_cycle;
    lv_obj_t *warning2_cycle;
    lv_obj_t *bus_state_bg;
    lv_obj_t *label_angle;
    lv_obj_t *danger_level_icon[4];
    lv_obj_t *danger_level_1[3];
    lv_obj_t *danger_leve1_2[3];
    lv_obj_t *danger_leve1_3[3];
    lv_obj_t *danger_leve1_4[3];
    lv_obj_t *bus_cycle;
    lv_obj_t *any_state_busbg;
    lv_obj_t *coord_bg;
    lv_obj_t *warning_icon[4];
    lv_obj_t *bus_cycle_any;
    lv_obj_t *leg_length[4];
    lv_obj_t *line_cycle;
    lv_obj_t *danger_mode_icon;

    lv_obj_t *red_leg_1_long;
    lv_obj_t *red_leg_1_short;
    lv_obj_t *red_leg_2_long;
    lv_obj_t *red_leg_2_short;
    lv_obj_t *red_leg_3_long;
    lv_obj_t *red_leg_4_long;
    lv_obj_t *red_leg_5_long;
    lv_obj_t *red_leg_6_long;
}working_page_antipping_t;

lv_obj_t* working_page_antipping_init(lv_obj_t *page);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif  //__WORKING_PAGE_ANTIPPING_H__
