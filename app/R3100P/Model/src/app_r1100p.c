#include <malloc.h>
#include "../inc/app_r1100p.h"


app_r1100p_t *app;
app_r1100p_t *app_r1100p_create( void )
{
    app_r1100p_t* app = ( app_r1100p_t* )malloc( sizeof( app_r1100p_t ) );

    app->bd = board_r1100p_create();

    app->dt = dt_r1100p_create();
    //stateM_init( &app->sm, &state_idle , &state_err );
   // app->sme = stateME_create();

    return app;
}
void app_r1100p_init( app_r1100p_t *app )
{

#if DEV_ENABLE_KEYS == 1
    dev_keys_init( app->bd->keys, app->dt );
#endif

#if DEV_ENABLE_KEYS == 1
    dev_power_init( app->bd->power, app->dt );
#endif

#if DEV_ENABLE_LED == 1
    dev_led_init( app->bd->led_r );
    dev_led_init( app->bd->led_g );
    dev_led_init( app->bd->led_b );
#endif

#if DEV_ENABLE_SIGNAL_Z == 1
    dev_signal_z_init( app->bd->signal_z, app->dt );
#endif

#if DEV_ENABLE_UART0== 1
    app->bd->uart0->iuart->init( app->bd->uart0 );
#endif

#if DEV_ENABLE_TIMER == 1
    dev_timer_init( app->bd->timer_1s );
    dev_timer_init( app->bd->timer_1ms );
#endif

#if DEV_ENABLE_FAFTS == 1
    dev_fatfs_init( app->bd->fatfs, app->dt );
    bool _is_fatfs_read_success = dev_fatfs_read( app->bd->fatfs, (uint8_t *)&app->dt->ui->flash, sizeof( dt_ylm_ui_flash_t ) );
#endif

#if DEV_ENABLE_IAP == 1
    dev_iap_init( app->bd->iap, &app->bd->uart0->buf_rx );
#endif

    //dt_r1100p_ui_init( false );//字典内数值初始化

}
