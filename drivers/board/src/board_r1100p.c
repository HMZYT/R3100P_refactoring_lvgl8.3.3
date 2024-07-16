#include "stdlib.h"
#include "../drivers/board/inc/board_r1100p.h"
//#include "bsp_ylm.h"
//#include "dev_ylm.h"



board_r1100p_t* board_r1100p_create( void )
{
    board_r1100p_t *bd = ( board_r1100p_t* )malloc( sizeof( board_r1100p_t ) );
#ifdef ENABLE_ASSERT
	assert( bd == NULL );
#endif  

    /***********************按键***********************/
#if DEV_ENABLE_KEYS == 1
    bd->keys =  dev_keys_create(
		(dev_handler)bsp_keys_init,
        (dev_ret_bool_handler)bsp_keys_read_up,
        (dev_ret_bool_handler)bsp_keys_read_down,
        (dev_ret_bool_handler)bsp_keys_read_left,
        (dev_ret_bool_handler)bsp_keys_read_right,
        (dev_ret_bool_handler)bsp_keys_read_enter,
				4,//多少s才判断为长按
				180//多少s才判断为超时进入待机
    );
#endif

#if DEV_ENABLE_POWER == 1
		bd->adc = dev_adc_create( bsp_adc_init, bsp_adc_read, 50 );
		bd->charge = dev_charge_create( bsp_charge_init, bsp_charge_read );
    /***********************供电电源***********************/
    bd->power = dev_power_create( bd->adc, bd->charge, 100 );
#endif

    /***********************串口***********************/
#if DEV_ENABLE_UART0 == 1
    dev_uart_handle_t uart_handle = {
        .UARTx = UART0,
        .buf_size_rx = 64,
        .buf_size_tx = 64,
        .init = bsp_uart0_init,
        .tx = bsp_usart0_tx,
        .tx_en = bsp_uart0_tx_en,
        .rx_en = bsp_uart0_rx_en,
        .set_tx_dma_buf = bsp_uart0_tx_dma_init,
        .tx_dma_tc_get = bsp_uart0_dma_get_tx_finish_flag,
		.tx_dma_tc_set = bsp_uart0_dma_tx_finish_flag_set,
        .tx_dma_tc_reset = bsp_uart0_dma_tx_finish_flag_reset,
        .write_byte = bsp_uart0_write_byte,
        .read_byte = bsp_uart0_read_byte,
    };
    bd->uart0 = dev_uart_create( &uart_handle );
#endif
		
#if DEV_ENABLE_LED == 1
    bd->led_r = dev_led_create( bsp_led_r_init, bsp_led_r_on, bsp_led_r_off, bsp_led_r_toggle );
    bd->led_g = dev_led_create( bsp_led_g_init, bsp_led_g_on, bsp_led_g_off, bsp_led_g_toggle );
    bd->led_b = dev_led_create( bsp_led_b_init, bsp_led_b_on, bsp_led_b_off, bsp_led_b_toggle );
#endif

#if DEV_ENABLE_SIGNAL_Z == 1
    bd->signal_z = dev_signal_z_create( bsp_signal_z_init, bsp_signal_z_read );
#endif

#if DEV_ENABLE_FLASH == 1
    dev_flash_t falsh_handle = {
        .read = FlashDiskRead,
        .write = FlashDiskWrite,
        .erase = FlashDiskFlush,
    };
    bd->flash = dev_flash_create( &falsh_handle );
#endif

#if DEV_ENABLE_TIMER == 1
    bd->timer_1s = dev_timer_create( BTIMR2, bsp_timer2_init, bsp_timer2_start, bsp_timer2_stop );
    bd->timer_1ms = dev_timer_create( BTIMR3, bsp_timer3_init, bsp_timer3_start, bsp_timer3_stop );
#endif

#if DEV_ENABLE_FAFTS == 1
    bd->fatfs = dev_fatfs_create( bsp_fatfs_init, bsp_fatfs_read, bsp_fatfs_write, bsp_fatfs_delete );
#endif

#if DEV_ENABLE_IAP == 1
    bd->iap = dev_iap_create( bsp_iap_set_update_req_flag );
#endif
	
	return bd;

}