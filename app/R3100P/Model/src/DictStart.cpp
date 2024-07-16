//
// Created by wpl on 2024/4/24.
//

#include "../inc/DictStart.h"
#include "../../../../extensions/data-types/inc/dt_r1100p_ui_data.h"
#include "../inc/DtR1100PUi.h"
#include "../../View/User/inc/sysparas_defs.h"
#include "../../View/User/inc/PageManage.h"

void dictInit()
{
    //绑字典
#pragma region 系统参数
    dtR1100PUi.dtR1100pDictAdd(system_paras_language, &dt_ui.paras.language, 0);
    dtR1100PUi.dtR1100pDictAdd(system_paras_mode, &dt_ui.paras.mode, 0);
    dtR1100PUi.dtR1100pDictAdd(system_paras_page, &dt_ui.paras.page_id, 2);
    dtR1100PUi.dtR1100pDictAdd(system_paras_power_key, &dt_ui.paras.powerkey, 0);
    dtR1100PUi.dtR1100pDictAdd(system_paras_screen_lock, &dt_ui.paras.screen_lock, 0);
    dtR1100PUi.dtR1100pDictAdd(system_paras_language_set, &dt_ui.paras.language_set, 0);
#pragma endregion 系统参数

#pragma region header
    dtR1100PUi.dtR1100pDictAdd(header_title_type, &dt_ui.working.header.title_type, 0);
    dtR1100PUi.dtR1100pDictAdd(header_bat_level, &dt_ui.working.header.bat_level, 0);
    dtR1100PUi.dtR1100pDictAdd(header_wireless_level, &dt_ui.working.header.wireless_level, 0);
    dtR1100PUi.dtR1100pDictAdd(header_rf_channel, &dt_ui.working.header.rf_channel, 0);
//    dtR1100PUi.dtR1100pDictAdd(header_bat_charging, &dt_ui.working.header.bat_charging, 0);
//    dtR1100PUi.dtR1100pDictAdd(header_wireless, &dt_ui.working.header.wireless, 0);
#pragma endregion header

    //machine
    dtR1100PUi.dtR1100pDictAdd(machine_motor_speed, &dt_ui.working.machine.motor_speed, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_acc_flag, &dt_ui.working.machine.acc_flag, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_dec_flag, &dt_ui.working.machine.dec_flag, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_gear, &dt_ui.working.machine.gear, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_water_temp, &dt_ui.working.machine.water_temp, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_pump_mode, &dt_ui.working.machine.pump_mode, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_oil_pos, &dt_ui.working.machine.oil_pos, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_urea_pos, &dt_ui.working.machine.urea_pos, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_pumping_pressure, &dt_ui.working.machine.pumping_pressure, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_cw, &dt_ui.working.machine.cw, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_ccw, &dt_ui.working.machine.ccw, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_emr, &dt_ui.working.machine.emr, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_materials, &dt_ui.working.machine.materials, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_pump_freq, &dt_ui.working.machine.pump_freq, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_pump_temperature, &dt_ui.working.machine.pump_temperature, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_blocking, &dt_ui.working.machine.blocking, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_pressure, &dt_ui.working.machine.pressure, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_fan_manual, &dt_ui.working.machine.fan_manual, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_fan_auto, &dt_ui.working.machine.fan_auto, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_fan_close, &dt_ui.working.machine.fan_close, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_fan_emr, &dt_ui.working.machine.fan_emr, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_mixer_cw, &dt_ui.working.machine.mixer_cw, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_mixer_ccw, &dt_ui.working.machine.mixer_ccw, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_mixer_emr, &dt_ui.working.machine.mixer_emr, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm0_cw_en, &dt_ui.working.machine.arm0_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm1_cw_en, &dt_ui.working.machine.arm1_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm2_cw_en, &dt_ui.working.machine.arm2_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm3_cw_en, &dt_ui.working.machine.arm3_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm4_cw_en, &dt_ui.working.machine.arm4_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm5_cw_en, &dt_ui.working.machine.arm5_cw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm0_ccw_en, &dt_ui.working.machine.arm0_ccw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm1_ccw_en, &dt_ui.working.machine.arm1_ccw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm2_ccw_en, &dt_ui.working.machine.arm2_ccw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm3_ccw_en, &dt_ui.working.machine.arm3_ccw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm4_ccw_en, &dt_ui.working.machine.arm4_ccw_en, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_arm5_ccw_en, &dt_ui.working.machine.arm5_ccw_en, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm0_status, &dt_ui.working.machine.arm0_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm1_status, &dt_ui.working.machine.arm1_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm2_status, &dt_ui.working.machine.arm2_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm3_status, &dt_ui.working.machine.arm3_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm4_status, &dt_ui.working.machine.arm4_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arm5_status, &dt_ui.working.machine.arm5_status, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_support_mode, &dt_ui.working.machine.support_mode, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_arms_temperature, &dt_ui.working.machine.arms_temperature, 0);
    //dtR1100PUi.dtR1100pDictAdd(machine_cw_emr, &dt_ui.working.machine.cw_emr, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_support_logo, &dt_ui.working.machine.support_logo, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_collapse_logo, &dt_ui.working.machine.collapse_logo, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_safe_k, &dt_ui.working.machine.safe_k, 0);
    dtR1100PUi.dtR1100pDictAdd(machine_data_space, &dt_ui.machine_space, 0);

    //rc
    dtR1100PUi.dtR1100pDictAdd(rc_armSupport, &dt_ui.working.rc.armSupport, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_arm1, &dt_ui.working.rc.arm1, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_arm2, &dt_ui.working.rc.arm2, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_arm3, &dt_ui.working.rc.arm3, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_arm4, &dt_ui.working.rc.arm4, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_arm5, &dt_ui.working.rc.arm5, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_displacement, &dt_ui.working.rc.displacement, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_1, &dt_ui.working.rc._1, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_1_2, &dt_ui.working.rc._1_2, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_1_2_3, &dt_ui.working.rc._1_2_3, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_2, &dt_ui.working.rc._2, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_3, &dt_ui.working.rc._3, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_2_3, &dt_ui.working.rc._2_3, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_engine_stop, &dt_ui.working.rc.engine_stop, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_start_key, &dt_ui.working.rc.start_key, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_horn, &dt_ui.working.rc.horn, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_halt, &dt_ui.working.rc.halt, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_ccw, &dt_ui.working.rc.ccw, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_cw, &dt_ui.working.rc.cw, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_right_swing_pump, &dt_ui.working.rc.right_swing_pump, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_left_swing_pump, &dt_ui.working.rc.left_swing_pump, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_slow, &dt_ui.working.rc.slow, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_rpm_minus, &dt_ui.working.rc.rpm_minus, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_rpm_plus, &dt_ui.working.rc.rpm_plus, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_dredge, &dt_ui.working.rc.dredge, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_strong_power, &dt_ui.working.rc.strong_power, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_powerkey, &dt_ui.working.rc.powerkey, 0);
    //dtR1100PUi.dtR1100pDictAdd(rc_flag, &dt_ui.working.rc.flag, 0);
    dtR1100PUi.dtR1100pDictAdd(rc_data_space, &dt_ui.rc_space, 0);

    //faults
    dtR1100PUi.dtR1100pDictAdd(faults_id, &dt_ui.working.machine.fault_id, 0);
    dtR1100PUi.dtR1100pDictAdd(faults_detail, &dt_ui.working.machine.fault_detail, 0);
    dtR1100PUi.dtR1100pDictAdd(faults_total, &dt_ui.working.machine.fault_total, 0);

    //antipping
    //dtR1100PUi.dtR1100pDictAdd(antipping_collapse_flag, &dt_ui.working.machine.collapse_flag, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_alarm_flag, &dt_ui.working.machine.alarm_flag, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_limit_flag, &dt_ui.working.machine.limit_flag, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_up_level, &dt_ui.working.machine.leg_left_up_level, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_up_level, &dt_ui.working.machine.leg_right_up_level, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_down_level, &dt_ui.working.machine.leg_left_down_level, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_down_level, &dt_ui.working.machine.leg_right_down_level, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_up_collapse, &dt_ui.working.machine.leg_left_up_collapse, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_down_collapse, &dt_ui.working.machine.leg_left_down_collapse, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_up_collapse, &dt_ui.working.machine.leg_right_up_collapse, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_down_collapse, &dt_ui.working.machine.leg_right_down_collapse, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_up_dis, &dt_ui.working.machine.up_dis, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_down_dis, &dt_ui.working.machine.down_dis, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_left_dis, &dt_ui.working.machine.left_dis, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_right_dis, &dt_ui.working.machine.right_dis, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_danger_edge, &dt_ui.working.machine.danger_edge, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_support_mode, &dt_ui.working.machine.support_mode, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_up, &dt_ui.working.machine.leg_left_up, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_left_down, &dt_ui.working.machine.leg_left_down, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_up, &dt_ui.working.machine.leg_right_up, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_leg_right_down, &dt_ui.working.machine.leg_right_down, 0);
    //dtR1100PUi.dtR1100pDictAdd(antipping_leg_not_open, &dt_ui.working.machine.leg_not_open, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_arm0_status, &dt_ui.working.machine.arm0_status, 0);
    dtR1100PUi.dtR1100pDictAdd(antipping_safe_k, &dt_ui.working.machine.safe_k, 0);

    //factory
    dtR1100PUi.dtR1100pDictAdd(factory_align_disp_min, &dt_ui.factory.data.cali_dis.min, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_disp_mid, &dt_ui.factory.data.cali_dis.mid, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_disp_max, &dt_ui.factory.data.cali_dis.max, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_disp_selected_pos, &dt_ui.factory.data.cali_dis.selected_pos, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_selected_cali_arm, &dt_ui.factory.data.cali.selected_cali_arm, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_min_arr, &dt_ui.factory.data.cali.min, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_mid_arr, &dt_ui.factory.data.cali.mid, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_max_arr, &dt_ui.factory.data.cali.max, 0);
    dtR1100PUi.dtR1100pDictAdd(factory_align_selected_pos, &dt_ui.factory.data.cali.selected_pos, 0);

    //设初值
    //系统参数
    dtR1100PUi.setDtInt(system_paras_language, 0);
    dtR1100PUi.setDtInt(system_paras_mode, 0);
    dtR1100PUi.setDtInt(system_paras_page, page_end_flag);
    dtR1100PUi.setDtInt(system_paras_power_key, 0);
    dtR1100PUi.setDtInt(system_paras_screen_lock, 0);
    dtR1100PUi.setDtInt(system_paras_language_set, 0);

    //int a = dtR1100PUi.getDtInt(system_paras_page);

    //header
    for(int i = header_title_type; i < header_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
    //machine
    for(int i = machine_motor_speed; i < machine_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
    //rc
    for(int i = rc_armSupport; i < rc_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
    //faults
    for(int i = faults_id; i < faults_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
    //antipping
    for(int i = antipping_collapse_flag; i < antipping_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
    //factory
    for(int i = factory_align_disp_min; i < factory_align_end; i++) {
        dtR1100PUi.setDtInt(i, 0);
    }
}