#ifndef __APP_R1100P_H__
#define __APP_R1100P_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../lv_port_pc_eclipse/lvgl/lvgl.h"
#include "../extensions/data-types/inc/dt_r1100p.h"
#include "../drivers/board/inc/board_r1100p.h"
typedef struct
 {
  board_r1100p_t *bd;
  dt_r1100p_t *dt;

  //struct stateMachine sm;
  //stateMachineEvents_t *sme;

 }app_r1100p_t;

 extern app_r1100p_t *app;

 extern app_r1100p_t *app_r1100p_create( void );

 extern void app_r1100p_init( app_r1100p_t *bd );

 extern void app_r1100p_run( app_r1100p_t *app );


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
