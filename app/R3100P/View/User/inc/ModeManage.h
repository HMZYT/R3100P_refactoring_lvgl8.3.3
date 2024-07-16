#ifndef MODEMANAGE_H
#define MODEMANAGE_H

#include "lvgl/lvgl.h"
#include "../../UI/inc/irc_lcd_header.h"
#include "../../UI/inc/irc_lcd_footer.h"
#include <iostream>
#include <vector>
#include "../../UI/inc/rc_lcd_working_widget.h"
#include "../../UI/inc/rc_lcd_prepared_widget.h"
#include "../../UI/inc/rc_lcd_idle_widget.h"
#include "../../UI/inc/rc_lcd_factory_widget.h"
#include "../../UI/inc/rc_lcd_off_charging_widget.h"
#include "../inc/PageManage.h"

using namespace std;

typedef struct {
    lv_obj_t * (*init)();
}irc_lcd_widget_t;


typedef enum{
    e_rc_lcd_idle,
    e_rc_lcd_working,
    e_rc_lcd_factory,
    e_rc_lcd_off_charging,
    e_rc_lcd_preparation,
    e_rc_lcd_flag_end,
}rc_lcd_mode_t;

class ModeManage {
public:
    ModeManage(irc_lcd_widget_t *modeWidget, lv_obj_t* (*init)());
    ~ModeManage();

public:
    void mode_manage_add_widget(irc_lcd_widget_t *modeWidget, lv_obj_t* (*init)());
    lv_obj_t *mode_manage_switch_widget(int modeIndex);
    void mode_manage_init_widgets();
private:
    lv_obj_t *currentModeWidget;
    vector<irc_lcd_widget_t *> widgetsList;
    vector<lv_obj_t *> widgetsListInit;
};

#endif //MODEMANAGE_H
