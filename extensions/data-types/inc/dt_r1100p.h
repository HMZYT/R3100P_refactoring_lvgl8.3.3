#ifndef DT_YLM_H_
#define DT_YLM_H_

#include "dt_r1100p_ui_data.h"
#include <stdbool.h>

typedef struct
{
    /* 按键、电量、是否插电 */
//    dt_keys_t *keys;
//    dt_power_t *power;
    dt_r1100p_ui_t *ui;
}dt_r1100p_t;

extern dt_r1100p_t *dt_r1100p_create( void );

#endif /*  DT_YLM_H_ */