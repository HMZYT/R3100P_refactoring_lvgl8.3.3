#include "../inc/images_v4_0.h"

//重构使用.c
//public
lv_img_dsc_t public_04;
lv_img_dsc_t home_rpm;
lv_img_dsc_t home_pin;
lv_img_dsc_t speed_up;
lv_img_dsc_t speed_down;
lv_img_dsc_t speed_up_green;
lv_img_dsc_t speed_down_green;
lv_img_dsc_t motor_speed;
lv_img_dsc_t current_level;
lv_img_dsc_t sug_level;
lv_img_dsc_t adblue;
lv_img_dsc_t oil_pos;
lv_img_dsc_t home_mpa;
lv_img_dsc_t bump_press0;
lv_img_dsc_t bump_up;
lv_img_dsc_t bump_down;
lv_img_dsc_t bump_oil;
lv_img_dsc_t fengji_switch;
lv_img_dsc_t wind_auto;
lv_img_dsc_t fengji_stop;
lv_img_dsc_t jiaoban_2;
lv_img_dsc_t jiaoban_3;
lv_img_dsc_t jiaoban_stop;
lv_img_dsc_t car;
lv_img_dsc_t xx_icon;
lv_img_dsc_t no_mode;
lv_img_dsc_t four_mode;
lv_img_dsc_t second_mode;
lv_img_dsc_t mode_12;
lv_img_dsc_t any_mode;
lv_img_dsc_t mode_24;
lv_img_dsc_t mode_124;
lv_img_dsc_t mode_13;
lv_img_dsc_t mode_123;
lv_img_dsc_t RPC;
lv_img_dsc_t arm_oil;
lv_img_dsc_t cycle_angel;
lv_img_dsc_t eco_gray;
lv_img_dsc_t eco_green;
lv_img_dsc_t err;
lv_img_dsc_t mima_3;
lv_img_dsc_t duguan;
lv_img_dsc_t liao_0;
lv_img_dsc_t liao_1;
lv_img_dsc_t liao_2;
lv_img_dsc_t liao_3;
lv_img_dsc_t leg0;
lv_img_dsc_t qiangli;
lv_img_dsc_t shutong;
lv_img_dsc_t wirefull;
lv_img_dsc_t zoomlion;
lv_img_dsc_t horn_rc_header;

lv_img_dsc_t leg_1;
lv_img_dsc_t leg_2;
lv_img_dsc_t leg_3;
lv_img_dsc_t leg_4;
lv_img_dsc_t car_bg;
lv_img_dsc_t down_leg;
lv_img_dsc_t pos_bg;
lv_img_dsc_t pos_level;

lv_img_dsc_t control_arrow01;
lv_img_dsc_t control_arrow02;
lv_img_dsc_t button_7;
lv_img_dsc_t arm_gX1;
lv_img_dsc_t bbbbb_other;
lv_img_dsc_t bbbbb_other1;
lv_img_dsc_t control_power_press;
lv_img_dsc_t arm_d_g;
lv_img_dsc_t arm_d_0;
lv_img_dsc_t arm_d_1;
lv_img_dsc_t arm_d_2;
lv_img_dsc_t arm_d_a;
lv_img_dsc_t arm_d_b;
lv_img_dsc_t arm_d_c;
lv_img_dsc_t arm_d_d;
lv_img_dsc_t arm_d_e;
lv_img_dsc_t arm_d_f;
lv_img_dsc_t img_arm_lock;
lv_img_dsc_t img_bump;
lv_img_dsc_t img_bump_down;
lv_img_dsc_t img_bump_up;
lv_img_dsc_t img_eco;
lv_img_dsc_t img_motor_down;
lv_img_dsc_t img_motor_start;
lv_img_dsc_t img_motor_stop;
lv_img_dsc_t img_motor_up;
lv_img_dsc_t img_power_red;
lv_img_dsc_t img_strong;
lv_img_dsc_t img_swing_left;
lv_img_dsc_t img_swing_right;
lv_img_dsc_t img_language;
lv_img_dsc_t button_cycle_red;

lv_img_dsc_t arm_a0;
lv_img_dsc_t arm_a1;
lv_img_dsc_t arm_b0;
lv_img_dsc_t arm_b1;
lv_img_dsc_t arm_c0;
lv_img_dsc_t arm_c1;
lv_img_dsc_t arm_d0;
lv_img_dsc_t arm_d1;
lv_img_dsc_t arm_e0;
lv_img_dsc_t arm_e1;
lv_img_dsc_t arm_f0;
lv_img_dsc_t arm_f1;
lv_img_dsc_t bump_down;
lv_img_dsc_t bump_up;
lv_img_dsc_t butt_off;
lv_img_dsc_t butt_on;
lv_img_dsc_t elecdrive_off;
lv_img_dsc_t elecdrive_on;
lv_img_dsc_t fast_mode;
lv_img_dsc_t slow_mode;
lv_img_dsc_t mode_3;
lv_img_dsc_t RPM_down;
lv_img_dsc_t RPM_up;
lv_img_dsc_t swing_left;
lv_img_dsc_t swing_right;
lv_img_dsc_t vibrate_off;
lv_img_dsc_t vibrate_on;
lv_img_dsc_t horn_rc;
lv_img_dsc_t power_butt;

lv_img_dsc_t control_btn_0;
lv_img_dsc_t control_btn_1;
lv_img_dsc_t control_s_btn01;
lv_img_dsc_t control_s_btn02;
lv_img_dsc_t control_s_btn03;
lv_img_dsc_t control_cycle_Bbtn1;
lv_img_dsc_t control_cycle_Bbtn2;
lv_img_dsc_t control_cycle_Sbtn;
lv_img_dsc_t control_cycle_Sbtn_bg;
lv_img_dsc_t control_margin_01;
lv_img_dsc_t control_margin_02;
lv_img_dsc_t control_btn01;
lv_img_dsc_t control_btn02;
lv_img_dsc_t control_btn03;
lv_img_dsc_t control_btn04;
lv_img_dsc_t bbbbb_bump;
lv_img_dsc_t arm_b0_v6c2;
lv_img_dsc_t arm_b1_v6c2;
lv_img_dsc_t arm_gh0_v6c2;
lv_img_dsc_t arm_gh1_v6c2;
lv_img_dsc_t arm_gX2_v6c2;
lv_img_dsc_t red_arrow_N;

lv_img_dsc_t menu_key01;
lv_img_dsc_t menu_key02;
lv_img_dsc_t xxzz;
lv_img_dsc_t arm_down;
lv_img_dsc_t arm_mid;
lv_img_dsc_t arm_up;

lv_img_dsc_t alert_bg;
lv_img_dsc_t alert_icon;


lv_img_dsc_t bump_down;
lv_img_dsc_t bump_stop;
lv_img_dsc_t bump_up;
lv_img_dsc_t bus;
lv_img_dsc_t bus_arm0;
lv_img_dsc_t bus_state_bg;
lv_img_dsc_t bus_state0;
lv_img_dsc_t bus_state1;
lv_img_dsc_t bus_state2;
lv_img_dsc_t bus_state3;
lv_img_dsc_t bus_state4;
lv_img_dsc_t bus_state5;
lv_img_dsc_t bus_state6;
lv_img_dsc_t bus_state7;
lv_img_dsc_t arms_bg;
lv_img_dsc_t arms_state1;
lv_img_dsc_t arms_state2;
lv_img_dsc_t arms_state3;
lv_img_dsc_t arms_state4;
lv_img_dsc_t arms_state5;
lv_img_dsc_t arms_state6;
lv_img_dsc_t arms_state7;
lv_img_dsc_t coord_bg;
lv_img_dsc_t danger0;
lv_img_dsc_t danger1;
lv_img_dsc_t danger2;
lv_img_dsc_t danger3;
lv_img_dsc_t danger4;
lv_img_dsc_t fan0;
lv_img_dsc_t fan1;
lv_img_dsc_t fan2;
lv_img_dsc_t highpress;
lv_img_dsc_t jieneng;
lv_img_dsc_t leg_long_black;
lv_img_dsc_t leg_long_red;
lv_img_dsc_t leg_short_black;
lv_img_dsc_t leg_short_red;
lv_img_dsc_t liao_common;
lv_img_dsc_t liao_err;
lv_img_dsc_t liao_good;
lv_img_dsc_t liao_none;
lv_img_dsc_t lowpress;
lv_img_dsc_t mode_icon0;
lv_img_dsc_t mode_icon1;
lv_img_dsc_t mode_icon2;
lv_img_dsc_t mode_icon3;
lv_img_dsc_t nonepress;
lv_img_dsc_t qiangli;
lv_img_dsc_t shutong;
lv_img_dsc_t watercold;
lv_img_dsc_t warning_icon;

lv_img_dsc_t redleg_1_long;
lv_img_dsc_t redleg_1_short;
lv_img_dsc_t redleg_2_long;
lv_img_dsc_t redleg_2_short;
lv_img_dsc_t redleg_3_long;
lv_img_dsc_t redleg_4_long;
lv_img_dsc_t redleg_5_long;

lv_img_dsc_t control_page_bg;
lv_img_dsc_t control_0c0;
lv_img_dsc_t control_0c1;
lv_img_dsc_t control_0d0;
lv_img_dsc_t control_0d1;
lv_img_dsc_t control_0i0;
lv_img_dsc_t control_0j0;
lv_img_dsc_t control_0f0;
lv_img_dsc_t control_0f1;
lv_img_dsc_t control_0g0;
lv_img_dsc_t control_0g1;
lv_img_dsc_t control_0h0;
lv_img_dsc_t control_0h1;

