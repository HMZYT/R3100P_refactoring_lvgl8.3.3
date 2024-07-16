#ifndef DT_R1100P_UI_DATA_H_
#define DT_R1100P_UI_DATA_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct{
    int32_t language;
    int32_t mode;
    int32_t page_id;
    int32_t powerkey;
    int32_t screen_lock;
    int32_t language_set;
}lcd_system_paras;

typedef struct {
	uint8_t dredge 				: 1;		//疏通
	uint8_t strong_power 		: 1;
	uint8_t save_power 			: 1;
	uint8_t horn 				: 1;		//启动/电铃
	uint8_t engine_stop 		: 1;		//发动机熄火
	uint8_t slow 				: 1;		//慢速
	uint8_t dampcan_enable 		: 1;		//臂架减震
	uint8_t left_swing_pump 	: 1;		//左摆缸点动
	uint8_t right_swing_pump 	: 1;		//右摆缸点动
	uint8_t cw 					: 1;		//正泵
	uint8_t ccw 				: 1;		//反泵
	uint8_t rpm_minus 			: 1;		//RPM-
	uint8_t rpm_plus 			: 1;		//RPM+
	uint8_t pilot_valve 		: 1;		//旁通阀
	uint8_t all_open			: 1;
	uint8_t all_material 		: 1;
	uint8_t	_1 					: 1;
	uint8_t _1_2 				: 1;
	uint8_t _1_2_3 				: 1;
	uint8_t _2 					: 1;
	uint8_t _3 					: 1;
	uint8_t _2_3 				: 1;
	uint8_t start_key			: 1;		//启动按键按下：1, 启动按键松开：0
	uint8_t powerkey			: 1;		//开机键复用
}working_rc_space;

typedef struct {
	uint8_t leg_left_up_collapse : 1;	 // 左前支腿塌陷
	uint8_t leg_left_down_collapse : 1;	 // 左后支腿塌陷
	uint8_t leg_right_up_collapse : 1;	 // 右前支腿塌陷
	uint8_t leg_right_down_collapse : 1; // 右后支腿塌陷
	uint8_t leg_not_open : 1;			 // 根据支腿未全开标志位显示：false：无显示；true：支腿未全开
	uint8_t pressure : 1;				 // 高低压
	uint8_t cw : 1;						 // 正泵
	uint8_t ccw : 1;					 // 反泵
	uint8_t mixer_cw : 1;				 // 正搅拌
	uint8_t mixer_ccw : 1;				 // 反搅拌
	uint8_t danger_level : 2;			 // 危险等级byte(0-2)（0、1：安全，指示绿灯，2：慢档，黄灯，3：危险，红灯）
	uint8_t save_energy : 1;			 // 泵送节能状态（0：显示灰色图标，1：显示绿色节能状态图标）
	uint8_t ang_over : 1;				 // 车身倾角过大标志位bool：false，正常；true，倾角过大
	uint8_t lcd_on:1;					//显示屏点亮
	uint8_t beep:1;
	uint8_t led_alarm:1;				//报警灯控制
	uint8_t	arm1_lock:1;				//禁止收1臂
	uint8_t	armSupport_cw_lock:1;		//顺回转限位
	uint8_t	armSupport_ccw_lock:1;		//逆回转限位
	uint8_t acc_flag:1;					//加速标志
	uint8_t dec_flag:1;					//减速标志
	uint8_t fan_manual :1;				//风机(手动)
	uint8_t fan_auto :1;				//风机(自动)
	uint8_t fan_close :1;				//风机(关)
	uint8_t fan_emr :1;					//风机应急
	uint8_t mixer_emr:1;				//搅拌应急
	uint8_t cw_emr:1;					//回转应急
	uint8_t arm0_cw_en:1;				//顺回转使能
	uint8_t arm1_cw_en:1;				//1臂展使能
	uint8_t arm2_cw_en:1;				//2臂展使能
	uint8_t arm3_cw_en:1;				//3臂展使能
	uint8_t arm4_cw_en:1;				//4臂展使能
	uint8_t arm5_cw_en:1;				//5臂展使能
	uint8_t arm6_cw_en:1;				//6臂展使能
	uint8_t arm7_cw_en:1;				//7臂展使能
	uint8_t arm0_ccw_en:1;				//逆回转使能
	uint8_t arm1_ccw_en:1;				//1臂收使能
	uint8_t arm2_ccw_en:1;				//2臂收使能
	uint8_t arm3_ccw_en:1;				//3臂收使能
	uint8_t arm4_ccw_en:1;				//4臂收使能
	uint8_t arm5_ccw_en:1;				//5臂收使能
	uint8_t arm6_ccw_en:1;				//6臂收使能
	uint8_t arm7_ccw_en:1;				//7臂收使能
	uint8_t collapse_flag :1;			//20a,显示屏机手页面勾选塌陷识别功能标志位：false，未勾选；true，勾选
	uint8_t alarm_flag :1;				//20a,支撑安全预警系统警示灯提示标志位：false，未勾选；true，勾选
	uint8_t limit_flag :1;				//20a,支撑安全预警系统限制功能标志位：false，未勾选；true，勾选
}working_machine_space;

typedef struct{
#if DATA_FLOW_ENABLE == 1
	uint8_t flow;
#endif
	//1位一键待机
	uint8_t dredge 				: 1;		//疏通
	uint8_t strong_power 		: 1;
	uint8_t save_power 			: 1;
	uint8_t horn 				: 1;		//启动/电铃
	uint8_t engine_stop 		: 1;		//发动机熄火
	uint8_t slow 				: 1;		//慢速
	uint8_t dampcan_enable 		: 1;		//臂架减震
	uint8_t left_swing_pump 	: 1;		//左摆缸点动
	uint8_t right_swing_pump 	: 1;		//右摆缸点动
	uint8_t cw 					: 1;		//正泵
	uint8_t ccw 				: 1;		//反泵
	uint8_t rpm_minus 			: 1;		//RPM-
	uint8_t rpm_plus 			: 1;		//RPM+
	uint8_t pilot_valve 		: 1;		//旁通阀
	uint8_t all_open			: 1;
	uint8_t all_material 		: 1;
	uint8_t	_1 					: 1;
	uint8_t _1_2 				: 1;
	uint8_t _1_2_3 				: 1;
	uint8_t _2 					: 1;
	uint8_t _3 					: 1;
	uint8_t _2_3 				: 1;
	uint8_t start_key			: 1;		//启动按键按下：1, 启动按键松开：0

	uint8_t powerkey			: 1;		//开机键复用

	int8_t displacement;					//排量
	uint8_t armSupport;						//臂架顺时针/逆时针
	uint8_t arm1;							//一级臂
	uint8_t arm2;							//一级臂
	uint8_t arm3;							//一级臂
	uint8_t arm4;							//一级臂
	uint8_t arm5;							//一级臂
	//	uint8_t arm6;							//六级臂
	//	uint8_t arm7;

	bool halt;
	bool connected;
}dt_rc_status_t;


typedef struct{
#if DATA_FLOW_ENABLE == 1
	uint8_t flow;
#endif
	uint8_t alarm_idx[6];				 // 6个故障编码
	uint16_t motor_speed;				 // 发动机转速, 0-3200
	uint16_t pumping_pressure;			 // 泵送压力：0-32MPa
	uint16_t safe_k;					 // 安全系数（ 数据类型：int）
	uint8_t oil_consume;				 // 瞬时油耗*0.01（单位：L/方，数据类型：usint）
	uint8_t suggest_eco;					 // 推荐经济档位*0.1（单位：，数据类型：usint）
	uint8_t gear;						 // 排量档位(0 - 10)
	uint8_t materials;					 // 料况可泵性状态 0：不显示 1：可泵性好 2：可泵性一般 3：可泵性差
	uint8_t suggest_pump;				 // 泵送模式推荐（0：不显示，1：强力，2：疏通，3：节能）
	uint8_t emr;						 // 应急换向模式(0 关闭 1左主缸 2右主缸 3水箱 4 无传感)
	int16_t cround;						 // 回转角度*10（有正负）， ±360°
	int16_t pump_temperature;			 // 泵送液压油温（单位：0.1℃，数据类型：int）
	int16_t arms_temperature;			 // 臂架液压油温（单位：0.1℃，数据类型：int，有正负）
	uint8_t support_mode;				 // 支撑模式(0-无支撑、1-全支撑、2-左支撑、3-右支撑、4-前支撑、5-小支撑 7-左前、8 -右前、100-RPC)
	uint8_t oil_pos;					 // 油位（单位：%，数据类型：usint）
	uint8_t urea_pos;					 // 尿素液位（单位：%，数据类型：usint，数据范围0-100。发送FF表示数据异常，显示屏显示--以表示未识别到尿素液位)
	uint8_t arm_lock[2];				 // 臂锁
	uint8_t ang_x;						 // 车身倾角X int（ 单位  0.1°，偏移量5°，数据类型：int）
//<1-30
	int8_t leg_left_up;					 // 左前支腿开度
	int8_t leg_left_down;				 // 左后支腿开度
	int8_t leg_right_up;				 // 右前支腿开度
	int8_t leg_right_down;				 // 右后支腿开度
	uint8_t leg_left_up_collapse : 1;	 // 左前支腿塌陷
	uint8_t leg_left_down_collapse : 1;	 // 左后支腿塌陷
	uint8_t leg_right_up_collapse : 1;	 // 右前支腿塌陷
	uint8_t leg_right_down_collapse : 1; // 右后支腿塌陷
	uint8_t leg_not_open : 1;			 // 根据支腿未全开标志位显示：false：无显示；true：支腿未全开
	uint8_t pressure : 1;				 // 高低压
	uint8_t cw : 1;						 // 正泵
	uint8_t ccw : 1;					 // 反泵
	uint8_t mixer_cw : 1;				 // 正搅拌
	uint8_t mixer_ccw : 1;				 // 反搅拌
	uint8_t danger_level : 2;			 // 危险等级byte(0-2)（0、1：安全，指示绿灯，2：慢档，黄灯，3：危险，红灯）
	uint8_t save_energy : 1;			 // 泵送节能状态（0：显示灰色图标，1：显示绿色节能状态图标）
	uint8_t ang_over : 1;				 // 车身倾角过大标志位bool：false，正常；true，倾角过大
	uint8_t lcd_on:1;					//显示屏点亮
	uint8_t beep:1;
	uint8_t led_alarm:1;				//报警灯控制
	uint8_t	arm1_lock:1;				//禁止收1臂
	uint8_t	armSupport_cw_lock:1;		//顺回转限位
	uint8_t	armSupport_ccw_lock:1;		//逆回转限位
	uint8_t acc_flag:1;					//加速标志
	uint8_t dec_flag:1;					//减速标志
	uint8_t arm4_alarm;					/** 四臂油缸报警编号
										 * 1: 四臂无杆腔压力传感器故障，请更换传感器。如继续施工，三四臂夹角必须大于90°；
										 * 2: 四臂有杆腔压力传感器故障，请更换传感器。如继续施工，三四臂夹角必须大于90°；
										 * 3: 三臂倾角传感器故障，请更换传感器。如继续施工，三四臂夹角必须大于90°；
										 * 4: 四臂倾角传感器故障，请更换传感器。如继续施工，三四臂夹角必须大于90°；
										 * 5: 四臂油缸载荷须小于1000，当前载荷为XX，请调整臂架姿态。
										 * 6: 三四臂夹角须大于90°，当前三四臂夹角为XX°。
										 * 7: 报警解除，如需布料，请重新启动泵送。后续泵送时，建议三四臂夹角大于90°。
										 */
	uint16_t arm4_load;					//四臂负载值，对应四臂油缸报警编号的编号5中的值
	int16_t arm3_4_angle;				//三四臂当前夹角（有正负）/
	int16_t arm0_status;				//回转角度(单位0.1°,有正负)											20D(2-3)
	int16_t arm1_status;				//1臂角度(单位0.1°,有正负)											20D(4-5)
	int16_t arm2_status;				//2臂角度(单位0.1°,有正负)											20D(6-7)
	int16_t arm3_status;				//3臂角度(单位0.1°,有正负)											20E(0-1)
	int16_t arm4_status;				//4臂角度(单位0.1°,有正负)											20E(2-3)
	int16_t arm5_status;				//5臂角度(单位0.1°,有正负)											20E(4-5)
	int16_t arm6_status;				//6臂角度(单位0.1°,有正负)											20E(6-7)
//<31-60
	int16_t arm_pos;					//末端高度(单位0.1m,数据类型int)										20F(0-1)
	int16_t arm_pos_max;				//末端最高高度(单位0.1m,数据类型int)									20F(2-3)
	int16_t arm_pos_min;				//末端最低高度(单位0.1m,数据类型int)									20F(4-5)
	uint8_t id_target;					//姿态编号(被控车->接收机->发射机->屏幕)									210(0)
	int16_t arm1_target;				//1臂目标角(单位1°,int)												210(2-3)
	int16_t arm2_target;				//2臂目标角(单位1°,int)												210(4-5)
	int16_t arm3_target;				//3臂目标角(单位1°,int)												210(6-7)
	int16_t arm4_target;				//4臂目标角(单位1°,int)												211(0-1)
	int16_t arm5_target;				//5臂目标角(单位1°,int)												211(2-3)
	int16_t arm6_target;				//6臂目标角(单位1°,int)												211(4-5)
	uint8_t ang_y;						//车身倾角Y int（ 单位  0.1°，偏移量5°，数据类型：int）
	uint8_t blocking;					//堵管状态(1：正常 2：堵管预警 3：堵管报警)
	uint8_t pump_freq;					//泵送频率(单位：次/分钟，uint)
	uint8_t fan_manual :1;				//风机(手动)
	uint8_t fan_auto :1;				//风机(自动)
	uint8_t fan_close :1;				//风机(关)
	uint8_t fan_emr :1;					//风机应急
	uint8_t mixer_emr:1;				//搅拌应急
	uint8_t cw_emr:1;					//回转应急
	uint8_t arm0_cw_en:1;				//顺回转使能
	uint8_t arm1_cw_en:1;				//1臂展使能
	uint8_t arm2_cw_en:1;				//2臂展使能
	uint8_t arm3_cw_en:1;				//3臂展使能
	uint8_t arm4_cw_en:1;				//4臂展使能
	uint8_t arm5_cw_en:1;				//5臂展使能
	uint8_t arm6_cw_en:1;				//6臂展使能
	uint8_t arm7_cw_en:1;				//7臂展使能
	uint8_t arm0_ccw_en:1;				//逆回转使能
	uint8_t arm1_ccw_en:1;				//1臂收使能
	uint8_t arm2_ccw_en:1;				//2臂收使能
	uint8_t arm3_ccw_en:1;				//3臂收使能
	uint8_t arm4_ccw_en:1;				//4臂收使能
	uint8_t arm5_ccw_en:1;				//5臂收使能
	uint8_t arm6_ccw_en:1;				//6臂收使能
	uint8_t arm7_ccw_en:1;				//7臂收使能
	int8_t leg_left_up_level;	 		//左前支腿塌陷级别（-3~3）
	int8_t leg_right_up_level;			//右前支腿塌陷级别
	int8_t leg_left_down_level;			//左后支腿塌陷级别
	int8_t leg_right_down_level; 		//右后支腿塌陷级别
	bool afs_trans;
	uint16_t up_dis;					//前方安全距离
	uint16_t down_dis;					//后方安全距离
	uint16_t left_dis;					//左方安全距离
	uint16_t right_dis;					//右方安全距离
	uint8_t danger_edge;				//侧翻危险边
	uint8_t support_logo;				//20a,主监控任意支撑功能图标状态与颜色：0-不显示，1-灰色，2-绿色，3-黄色，4-红色
	uint8_t collapse_logo;				//20a,主监控塌陷识别功能图标状态与颜色：0-不显示，1-灰色，2-绿色，3-黄色，4-红色
	uint8_t collapse_flag :1;			//20a,显示屏机手页面勾选塌陷识别功能标志位：false，未勾选；true，勾选
	uint8_t alarm_flag :1;				//20a,支撑安全预警系统警示灯提示标志位：false，未勾选；true，勾选
	uint8_t limit_flag :1;				//20a,支撑安全预警系统限制功能标志位：false，未勾选；true，勾选
	uint8_t water_temp;					//212,冷却水温（单位：1℃，偏移：-40，范围：-40~210℃，16#FF表示无效数据）
	uint8_t group_index;				//220,组索引（byte，范围1-10）
	uint8_t point_index;				//220,点索引（byte，范围1-72）
	int16_t dis_x;						//220,坐标x（int，单位0.1m）
	int16_t dis_y;						//220,坐标y（int，单位0.1m）
	uint8_t pump_mode;				 	//泵送模式推荐（1：强力，2：疏通，3：节能）
	uint8_t fault_total;				//故障总数
	uint8_t fault_id;					//故障序号
	uint16_t fault_detail;				//故障代码
//<91+
}dt_machine_status_t;

/* RSSI值 */
typedef struct{
    uint8_t trans[2];//发射机
    uint8_t recv[2];//接收机
}dt_rc_rssi_t;

typedef struct{
    volatile uint8_t mode;
    volatile uint8_t page;
    volatile bool low_power;//屏幕自身的低功耗状态
    volatile bool backlight;
    volatile bool wireless_off;
    bool lcd_off;
}rc_lcd_status_data_t;

typedef struct{
    volatile uint8_t mode;
    volatile uint8_t page;
    volatile bool low_power;//屏幕自身的低功耗状态
    volatile bool backlight;
    volatile bool wireless_off;
}rc_lcd_status_data_r;

typedef struct{
    bool emergency;
    bool low_power;
    bool sd_card_err;
    bool key_wrong;

}rc_lcd_global_data_t;


typedef struct{
    uint8_t title_type;
    uint8_t bat_level;  //0, 1, 2, 3, 4, 5,
    uint8_t wireless_level; //0, 1, 2, 3, 4, 5,
    uint8_t	rf_channel;	//信道号
    uint8_t bat_charging: 1;
    uint8_t wireless : 1; //有线：false
    uint8_t whistle : 1;
}rc_lcd_header_data_t;

typedef struct{
    uint8_t power_level;    //只显示当前电量：0-100
}rc_lcd_off_charging_data_t;



//关机充电的数据

typedef struct{
    uint32_t lcd_boot;					//LCD-BOOT固件版本号
    uint32_t lcd_app;						//LCD-APP固件版本号
    uint32_t trans_boot;				//发射机BOOT固件版本号
    uint32_t trans_update;			//发射机UPDATE固件版本号
    uint32_t trans_app;					//发射机APP固件版本号(发射机主MCU程序版本号)
    uint32_t trans_standby_mcu;					//发射机备用固件版本号(发射机副MCU程序版本号)
    uint32_t rf_app;					//射频固件版本号
    uint32_t trans_address;					//LCD-BOOT固件版本号
    uint8_t trans_hardware;
}rc_lcd_version_data_t;

//工作模式的输入数据
typedef struct{
    dt_machine_status_t machine;
    dt_rc_status_t rc;
    dt_rc_rssi_t rssi;
    rc_lcd_header_data_t header;
    rc_lcd_global_data_t global;
    rc_lcd_status_data_t lcd;
    rc_lcd_version_data_t version;
}rc_lcd_input_data_t;


//关机充电输入数据
typedef struct{
    uint8_t mode;
    uint8_t page_idx;
    rc_lcd_off_charging_data_t data;
}rc_lcd_off_charging_input_data_t;

typedef struct{
    uint8_t mode;
    uint8_t page_idx;
    dt_rc_status_t rc;
}rc_lcd_preparation_input_data_t;

typedef struct{
    uint8_t selected_cali_arm;	//[0,6]
    uint8_t selected_pos;		//0, 1, 2, 3
    uint16_t min[7];
    uint16_t mid[7];
    uint16_t max[7];
}rc_lcd_fact_cali_arm_data_t;

typedef struct{
    uint8_t selected_pos;		//0, 1, 2, 3
    uint16_t min;
    uint16_t mid;
    uint16_t max;
}rc_lcd_fact_cali_displacement_data_t;

//工厂模式的输入数据
typedef struct{
    uint8_t mode;
    uint8_t page_idx;
    bool backlight;
    union{
        rc_lcd_fact_cali_arm_data_t cali;
        rc_lcd_fact_cali_displacement_data_t cali_dis;
        uint8_t inner_idx;  // 内部页面索引
    }data;


}rc_lcd_fact_input_data_t;
typedef struct
{
    rc_lcd_input_data_t working;
    rc_lcd_fact_input_data_t factory;
    rc_lcd_preparation_input_data_t prepared;
    rc_lcd_off_charging_input_data_t charging;
    working_rc_space rc_space;
    working_machine_space machine_space;
    lcd_system_paras paras;
} dt_r1100p_ui_t;

extern dt_r1100p_ui_t dt_ui;

extern dt_r1100p_ui_t *dt_r1100p_ui_create(void);

extern void dt_r1100p_ui_data_change_uint( void );

#endif /*  DT_R1100P_UI_DATA_H_ */