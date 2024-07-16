//
// Created by wpl on 2024/4/25.
//
#include "../inc/UiRun.h"
#include "../inc/ModeManage.h"
#include "../../UI/inc/working_page_antipping.h"
#include "../../UI/inc/working_page_home.h"
#include "../../UI/inc/working_page_faults.h"
#include "../../UI/inc/working_page_rc.h"
#include "../../UI/inc/working_page_note.h"
#include "../../UI/inc/working_page_light.h"
#include "../../UI/inc/working_page_setting.h"
#include "../../UI/inc/working_page_arms.h"
#include "../../UI/inc/idle_page_black.h"
#include "../../UI/inc/fact_page_version.h"
#include "../../UI/inc/fact_page_align.h"
#include "../../UI/inc/fact_page_align_displacement.h"
#include "../../UI/inc/fact_page_full_color.h"
#include "../../UI/inc/fact_page_touch.h"
#include "../../UI/inc/off_charging_page_charging.h"
#include "../../UI/inc/prepared_page_rc.h"
#include "../../../Model/inc/DtR1100PUi.h"
#include "../inc/sysparas_defs.h"
#include "../res/fonts/language_control.h"

irc_lcd_widget_t working_widget;
PAGE working_home_page;
ModeManage modeManage = ModeManage(&working_widget, working_widget_init);
PageManage pageManage = PageManage(&working_home_page, working_page_home_init);

void uiRun()
{
    //创建窗口
    rc_lcd_mode_t modeIndex = e_rc_lcd_working;
    int  pageIndex = working_page_note;

    irc_lcd_widget_t idle_widget;
    irc_lcd_widget_t factory_widget;
    irc_lcd_widget_t offChargint_widget;
    irc_lcd_widget_t prepared_widget;
    modeManage.mode_manage_add_widget(&working_widget, working_widget_init);
    modeManage.mode_manage_add_widget(&factory_widget, rc_lcd_factory_widget_init);
    modeManage.mode_manage_add_widget(&offChargint_widget, rc_lcd_off_charging_widget_init);
    modeManage.mode_manage_add_widget(&prepared_widget, prepared_widget_init);

    PAGE* working_antipping_page = new PAGE;
    PAGE* working_faults_page = new PAGE;
    PAGE* working_rc_page = new PAGE;
    PAGE* working_note_page = new PAGE;
    PAGE* working_setting_page = new PAGE;
    PAGE* working_light_page = new PAGE;
    PAGE* working_arm_page = new PAGE;
    PAGE* idle_black_page = new PAGE;
    PAGE* fact_version_page = new PAGE;
    PAGE* fact_algin_page = new PAGE;
    PAGE* fact_algin_displacement_page = new PAGE;
    PAGE* fact_page_full_color_page = new PAGE;
    PAGE* fact_page_touch_page = new PAGE;
    PAGE* off_charging_page = new PAGE;
    PAGE* prepared_page = new PAGE;
    pageManage.page_manage_add_page(working_antipping_page, working_page_antipping, working_page_antipping_init);
    pageManage.page_manage_add_page(working_faults_page, working_page_faults, working_page_faults_init);
    pageManage.page_manage_add_page(working_rc_page, working_page_rc, working_page_rc_init);
    pageManage.page_manage_add_page(working_note_page, working_page_note, working_page_note_init);
    pageManage.page_manage_add_page(working_setting_page, working_page_setting, working_page_setting_init);
    //pageManage.page_manage_add_page(working_light_page, working_page_light, working_page_light_init);
    pageManage.page_manage_add_page(working_arm_page, working_page_arm, working_page_arms_init);
    pageManage.page_manage_add_page(idle_black_page, idle_page_black, idle_page_black_init);
    pageManage.page_manage_add_page(fact_version_page, fact_page_version, fact_page_version_init);
    pageManage.page_manage_add_page(fact_algin_page, fact_page_algin, fact_page_algin_init);
    pageManage.page_manage_add_page(fact_algin_displacement_page, fact_page_algin_displacement, fact_page_algin_displacement_init);
    pageManage.page_manage_add_page(fact_page_full_color_page, fact_page_full_color, fact_page_full_color_init);
    pageManage.page_manage_add_page(fact_page_touch_page, fact_page_touch, fact_page_touch_init);
    pageManage.page_manage_add_page(off_charging_page, off_charging_page_charging, off_charging_page_charging_init);
    pageManage.page_manage_add_page(prepared_page, prepared_page_rc, prepared_page_rc_create);

    lv_obj_t * obj_temp = working_widget_init();
    lv_obj_clear_flag(obj_temp, LV_OBJ_FLAG_HIDDEN);
    pageManage.page_manage_init_pages(obj_temp);
    pageManage.page_manage_switch_page(working_page_home);
}

//static void system_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject)
//{
//#pragma region 语言
//    temp_value_t temp_v = lv_subject_get_int_from_type(subject, system_paras_language, 0, pageid_system);
//    if (temp_v.different_flag)
//    {
//        language_set_current_lang(temp_v.current_value);
//        language_change_callback();
//    }
//#pragma endregion 语言
//
//#pragma region 模式
//    temp_v = lv_subject_get_int_from_type(subject, system_paras_mode, 0, pageid_system);
//    //lv_obj_t *temp_widget = modeManage.mode_manage_switch_widget(temp_v.current_value);//选择模式
//#pragma endregion 模式
//
//#pragma region 页面
//    temp_v = lv_subject_get_int_from_type(subject, system_paras_page, 0, pageid_system);
//    language_clear_label_list();
//    pageManage.page_manage_switch_page(temp_v.current_value);
//#pragma endregion 页面
//}