#ifndef BOARD_R1100P_H_
#define BOARD_R1100P_H_
//
// #include "project_config.h"
// #include "dev_ylm.h"
// #include "bsp_ylm.h"

typedef struct
{
#if DEV_ENABLE_KEYS == 1
    dev_keys_t *keys;
#endif

#if DEV_ENABLE_POWER == 1
		dev_adc_t *adc;
		dev_charge_t *charge;
    dev_power_t *power;
#endif

#if DEV_ENABLE_UART0 == 1
    dev_uart_t *uart0;
#endif

#if DEV_ENABLE_POWER == 1
    dev_led_t *led_r;
    dev_led_t *led_g;
    dev_led_t *led_b;
#endif

#if DEV_ENABLE_SIGNAL_Z == 1
    dev_signal_z_t *signal_z;
#endif

#if DEV_ENABLE_FLASH == 1
    dev_flash_t *flash;
#endif

#if DEV_ENABLE_TIMER == 1
    dev_timer_t *timer_1s;//用于判断存储log与设置时间
    dev_timer_t *timer_1ms;//用于运行modbus与iap
#endif

#if DEV_ENABLE_FAFTS == 1
    dev_fatfs_t *fatfs;
#endif

#if DEV_ENABLE_IAP == 1
    dev_iap_t *iap;
#endif

}board_r1100p_t;

extern board_r1100p_t* board_r1100p_create( void );

#endif /*  BOARD_R1100P_H_ */