#include "stdlib.h"
#include "../extensions/data-types/inc/dt_r1100p_ui_data.h"
#include <stdbool.h>
#include "../app/R3100P/Model/inc//app_r1100p.h"
//#include "../app/R1100P-V5C_IN/Model/inc/DtR1100PUi.h"

#define FACTOR_DEFAULT 1
#define FACTOR_MM_TO_INCH 0.03937 // 转换关系1mm = 0.03937inch
#define FACTOR_M_TO_YARD 1.09361  // 转换关系1m = 1.09361yard

dt_r1100p_ui_t dt_ui;

//数据范围
//static dt_ylm_data_limit_t _limit_m100to100 = {-100, 100};

dt_r1100p_ui_t *dt_r1100p_ui_create(void)
{
	//dt_ylm_dict_paras_create(dt_ylm_dict_log_paras_add, dt_r1100p_ui_uint_get); // 注册钩子函数
	//dt_ylm_dict_belts_create(dt_ylm_dict_log_belts_add, dt_r1100p_ui_uint_get); // 注册钩子函数

	return &dt_ui;
}
