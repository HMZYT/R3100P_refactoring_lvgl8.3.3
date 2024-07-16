#ifndef __WORKING_PAGE_HOME_H__
#define __WORKING_PAGE_HOME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "../../User/inc/sysparas_defs.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../User/inc/images_v4_0.h"
#include "../../../../../res/fonts/gui_fonts.h"
#include "../../../Model/inc/data_info_v4_0.h"
#include "../../User/inc/images_v4_0.h"
#include "../res/fonts/gui_fonts.h"
#include "../api/inc/xlv_battery.h"
#include "../../User/inc/UiRun.h"
#include "../../res/fonts/language_control.h"
#include "../../theme/inc/theme_R1100P_white.h"
#include "../../theme/inc/theme_style.h"

typedef struct{
    int32_t current_value;
    int32_t previous_value;
    bool different_flag;
}temp_value_t;

typedef struct{
    /*************************************************************************************
     * 一区：
     * - 发动机转速
     * - 瞬时油耗
     * - ECO，泵送节能状态
     * - 排量档位
     * - 推荐经济档位
     *************************************************************************************/
    lv_obj_t *speed_up;
    lv_obj_t *speed_down;
    lv_obj_t *engine_speed_label;
    lv_obj_t *engine_speed_pointer;
    lv_obj_t *local_level_label;
    lv_obj_t *sug_level_label;
    lv_obj_t *oil_consume;
    lv_obj_t *eco_img;
    lv_obj_t *displacement_label;
    lv_obj_t *suggest_eco_gear;

    /*************************************************************************************
     * 二区：
     * - 泵送压力
     * - 物料状态
     * - 疏通
     *************************************************************************************/
    lv_obj_t *pump_press_label;
    lv_obj_t *pump_press_pointer;
    lv_obj_t *icon_materials;
    lv_obj_t *icon_materials_label;
    lv_obj_t *direction_err;
    lv_obj_t *bump_oil_tep;
    lv_obj_t *duguan;
    lv_obj_t *press_status;
    lv_obj_t *wind_status;
    lv_obj_t *wind_status_emr;
    lv_obj_t *jiaoban_status;
    lv_obj_t *jiaoban_status_emr;
    lv_obj_t *shutong_label;
    lv_obj_t *shutong_title;
    lv_obj_t *bump_direction_label;
    lv_obj_t *cycle_emr;
    /*************************************************************************************
     * 三区：
     * - 臂动
     * - 臂动限制
     *************************************************************************************/
    lv_obj_t *arms_angel[8];
    lv_obj_t *arms_up_lock[8];
    lv_obj_t *arms_down[8];
    lv_obj_t *arms_down_lock[8];
    lv_obj_t *arm_oil_label;
    lv_obj_t *cycle_angel_label;
    lv_obj_t *lock_img;

    /*************************************************************************************
     * 四区：
     * - 高低压
     * - 正反泵
     * - 正反搅拌
     * - 回转角度
     * - 臂架液压油温
     * - 泵送液压油温
     * - 支撑模式
     * - 油位
     * - 尿素液位
		 * - 安全系数条
     *************************************************************************************/
    lv_obj_t *pressure_high_low;
    lv_obj_t *pump_pos_neg;
    lv_obj_t *pump_err;
    lv_obj_t *jiaoban;
    lv_obj_t *jiaoban_err;
    
    lv_obj_t *turnover_label;
    lv_obj_t *pump_temperature_label;
    lv_obj_t *arms_temperature_label;
    lv_obj_t *arm_support_label;
    lv_obj_t *arm_img;

    lv_obj_t *oil_bar;
    lv_obj_t *oil_pos;
    lv_obj_t *uera_pos;
    lv_obj_t *truck;
    lv_obj_t *uera_rect[ 10 ];
    lv_obj_t *oil_rect[ 10 ];
    lv_obj_t *danger;
    lv_obj_t *danger_icon;
		
    lv_obj_t *red_obj;
    lv_obj_t *yellow_obj;
    lv_obj_t *green_obj;
    lv_obj_t *safety_bg;
    lv_obj_t *danger_mode_icon;
}working_page_home_t;

extern lv_obj_t* working_page_home_init(lv_obj_t *page);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
