#ifndef LVGL_SYSPARAS_DEFS_H
#define LVGL_SYSPARAS_DEFS_H

typedef enum {
    pageid_system,
    pageid_home,
    pageid_rc,
    pageid_note,
    pageid_faults,
    pageid_factory,
    pageid_antipping,
    pageid_end
}page_idx;

typedef enum {
#pragma region system
    system_paras_language,          //当前语言
    system_paras_mode,              //界面模式
    system_paras_page,              //显示页面
    system_paras_power_key,         //电源按键
    system_paras_screen_lock,       //锁屏
    system_paras_language_set,      //语言设置序号
    system_end,
#pragma endregion

#pragma region header
    header_title_type,
    header_bat_level,               //0, 1, 2, 3, 4, 5,
    header_wireless_level,          //0, 1, 2, 3, 4, 5,
    header_rf_channel,	            //信道号
    header_bat_charging,
    header_wireless,                //有线：false
    header_end,
#pragma endregion

#pragma region machine
    machine_motor_speed,            //发动机转速(0-3200)
    machine_gear,                   //排量档位(0-10)
    machine_water_temp,             //冷却水温（单位：1℃，偏移：-40，范围：-40~210℃，16#FF表示无效数据）
    machine_pump_mode,              //泵送模式推荐（1：强力，2：疏通，3：节能）
    machine_oil_pos,                //油位（单位：%）
    machine_urea_pos,               //尿素液位（单位：%,数据范围0-100。发送FF表示数据异常，显示屏显示--以表示未识别到尿素液位)
    machine_pumping_pressure,       //泵送压(0-32MPa)
    machine_emr,                    //应急换向模式(0 关闭 1左主缸 2右主缸 3水箱 4 无传感)
    machine_materials,              //料况可泵性状态 0：不显示 1：可泵性好 2：可泵性一般 3：可泵性差
    machine_pump_freq,              //泵送频率(单位：次/分钟)
    machine_pump_temperature,       //泵送液压油温（单位：0.1℃）
    machine_blocking,               //堵管状态(1：正常 2：堵管预警 3：堵管报警)
    machine_arm0_status,            //回转角度(单位0.1°,有正负)
    machine_arm1_status,            //1臂角度(单位0.1°,有正负)
    machine_arm2_status,            //2臂角度(单位0.1°,有正负)
    machine_arm3_status,            //3臂角度(单位0.1°,有正负)
    machine_arm4_status,            //4臂角度(单位0.1°,有正负)
    machine_arm5_status,            //5臂角度(单位0.1°,有正负)
    machine_arm6_status,            //5臂角度(单位0.1°,有正负)
    machine_support_mode,           //支撑模式(0-无支撑、1-全支撑、2-左支撑、3-右支撑、4-前支撑、5-小支撑 7-左前、8 -右前、100-RPC)
    machine_arms_temperature,       //臂架液压油温（单位：0.1℃，有正负）
    machine_support_logo,           //20a,主监控任意支撑功能图标状态与颜色：0-不显示，1-灰色，2-绿色，3-黄色，4-红色
    machine_collapse_logo,          //20a,主监控塌陷识别功能图标状态与颜色：0-不显示，1-灰色，2-绿色，3-黄色，4-红色
    machine_safe_k,                 //安全系数
    machine_data_space,
    //位数据
    machine_acc_flag,               //加速标志
    machine_dec_flag,               //减速标志
    machine_cw,                     //正泵
    machine_ccw,                    //反泵
    machine_pressure,               //高低压
    machine_fan_manual,             //风机(手动)
    machine_fan_auto,               //风机(自动)
    machine_fan_close,              //风机(关)
    machine_fan_emr,                //风机应急
    machine_mixer_cw,               //正搅拌
    machine_mixer_ccw,              //反搅拌
    machine_mixer_emr,              //搅拌应急
    machine_arm0_cw_en,             //顺回转使能
    machine_arm1_cw_en,             //1臂展使能
    machine_arm2_cw_en,             //2臂展使能
    machine_arm3_cw_en,             //3臂展使能
    machine_arm4_cw_en,             //4臂展使能
    machine_arm5_cw_en,             //5臂展使能
    machine_arm0_ccw_en,            //逆回转使能
    machine_arm1_ccw_en,            //1臂收使能
    machine_arm2_ccw_en,            //2臂收使能
    machine_arm3_ccw_en,            //3臂收使能
    machine_arm4_ccw_en,            //4臂收使能
    machine_arm5_ccw_en,            //5臂收使能
    machine_cw_emr,                 //回转应急
    machine_fault_total,            //故障总数
    machine_arm_pos_max,            //末端最高高度
    machine_arm_pos_min,            //末端最低高度
    machine_arm_pos,                //末端高度
    machine_end,
#pragma endregion

#pragma region rc
    rc_armSupport,                  //臂架顺时针/逆时针
    rc_arm1,                        //一级臂
    rc_arm2,                        //二级臂
    rc_arm3,                        //三级臂
    rc_arm4,                        //四级臂
    rc_arm5,                        //五级臂
    rc_arm6,                        //六级臂
    rc_arm7,                        //七级臂
    rc_displacement,                //排量
    rc_halt,
    rc_connected,
    rc_data_space,

    //位数据
    rc_1,
    rc_1_2,
    rc_1_2_3,
    rc_2,
    rc_3,
    rc_2_3,
    rc_engine_stop,                 //发动机熄火
    rc_start_key,                   //启动按键按下：1, 启动按键松开：0
    rc_horn,                        //启动/电铃
    rc_ccw,                         //反泵
    rc_cw,                          //正泵
    rc_dampcan_enable,              //减震
    rc_right_swing_pump,            //右摆缸点动
    rc_left_swing_pump,             //左摆缸点动
    rc_slow,                        //慢速
    rc_rpm_minus,                   //RPM-
    rc_rpm_plus,                    //RPM+
    rc_dredge,                      //疏通
    rc_strong_power,                //强力
    rc_powerkey,                    //开机键复用
    rc_deploy_retract,              //一键展收
    rc_pour,                        //一键布料
    rc_normal,                      //常规模式
    rc_flag,                        //是否锁屏
    rc_end,
#pragma endregion

#pragma region faults
    faults_id,                      //故障序号
    faults_detail,                  //故障代码
    faults_total,                   //故障总数
    faults_end,
#pragma endregion

#pragma region antipping
    antipping_collapse_flag,          //20a,显示屏机手页面勾选塌陷识别功能标志位：false，未勾选；true，勾选
    antipping_alarm_flag,             //20a,支撑安全预警系统警示灯提示标志位：false，未勾选；true，勾选
    antipping_limit_flag,             //20a,支撑安全预警系统限制功能标志位：false，未勾选；true，勾选
    antipping_leg_left_up_level,      //左前支腿塌陷级别（-3~3）
    antipping_leg_right_up_level,     //右前支腿塌陷级别
    antipping_leg_left_down_level,    //左后支腿塌陷级别
    antipping_leg_right_down_level,   //右后支腿塌陷级别
    antipping_leg_left_up_collapse,   //左前支腿塌陷
    antipping_leg_left_down_collapse, //左后支腿塌陷
    antipping_leg_right_up_collapse,  //右前支腿塌陷
    antipping_leg_right_down_collapse,//右后支腿塌陷
    antipping_up_dis,                 //前方安全距离
    antipping_down_dis,               //后方安全距离
    antipping_left_dis,               //左方安全距离
    antipping_right_dis,              //右方安全距离
    antipping_danger_edge,            //侧翻危险边
    antipping_support_mode,           //支撑模式(0-无支撑、1-全支撑、2-左支撑、3-右支撑、4-前支撑、5-小支撑 7-左前、8 -右前、100-RPC)
    antipping_leg_left_up,			  //左前支腿开度
    antipping_leg_left_down,		  //左后支腿开度
    antipping_leg_right_up,			  //右前支腿开度
    antipping_leg_right_down,		  //右后支腿开度
    antipping_leg_not_open,			  //根据支腿未全开标志位显示：false：无显示；true：支腿未全开
    antipping_arm0_status,            //回转角度(单位0.1°,有正负)
    antipping_safe_k,                 //安全系数
    antipping_end,
#pragma endregion

#pragma region factory
    factory_align_disp_min,
    factory_align_disp_mid,
    factory_align_disp_max,
    factory_align_disp_selected_pos,
    factory_align_displacement_end,
    factory_align_selected_cali_arm,
    factory_align_min_arr,
    factory_align_mid_arr,
    factory_align_max_arr,
    factory_align_selected_pos,
    factory_align_end,
#pragma endregion
    SUBJECT_COUNTS_PARAS_END
} subject_paras_t;

#endif //LVGL_SYSPARAS_DEFS_H
