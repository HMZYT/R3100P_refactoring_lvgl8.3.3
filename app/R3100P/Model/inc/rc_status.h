/*
 * dt_rc_status_r1100p_v6c3.h
 *
 *  Created on: Feb 27, 2023
 *      Author: ren.xfyer
 */

#ifndef DATA_TYPES_INCLUDE_DT_RC_STATUS_R1100P_V6C3_H_
#define DATA_TYPES_INCLUDE_DT_RC_STATUS_R1100P_V6C3_H_



#include <stdint.h>
#include <stdbool.h>

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




#endif /* DATA_TYPES_INCLUDE_DT_RC_STATUS_R1100P_V6C3_H_ */
