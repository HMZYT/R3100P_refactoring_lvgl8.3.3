#include "stdlib.h"
#include "../extensions/data-types/inc/dt_r1100p.h"

dt_r1100p_t *dt_r1100p_create( void )
{
    dt_r1100p_t* dt = ( dt_r1100p_t* )malloc( sizeof( dt_r1100p_t ) );
    if(dt == NULL) {
        return NULL;
    }

   // dt->keys = dt_ylm_keys_create();
    //dt->power = dt_ylm_power_create();
    dt->ui = dt_r1100p_ui_create();

    return dt;
}