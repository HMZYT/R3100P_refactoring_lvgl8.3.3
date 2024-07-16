#ifndef __DATA_INFO_V4_0_H__
#define __DATA_INFO_V4_0_H__


#include <stdint.h>
#include <stdbool.h>
#include "machine_status.h"
#include "rc_status.h"

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

#endif  /* __DATA_INFO_V4_0_H__ */

