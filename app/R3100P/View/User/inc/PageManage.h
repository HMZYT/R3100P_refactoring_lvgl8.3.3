//
// Created by wpl on 2024/4/24.
//

#ifndef LVGL_PAGEMANAGE_H
#define LVGL_PAGEMANAGE_H

#include "lvgl/lvgl.h"
#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    working_page_home,
    working_page_antipping,
    working_page_faults,
    working_page_rc,
    working_page_note,
    working_page_setting,
    working_page_light,
    working_page_arm,
    idle_page_black,
    fact_page_version,
    fact_page_algin,
    fact_page_algin_displacement,
    fact_page_full_color,
    fact_page_touch,
    off_charging_page_charging,
    prepared_page_rc,
    page_end_flag,
} page_ID_t;

typedef struct
{
    int  pageID;                    //pageID 每个页面有唯一的ID
    lv_obj_t* (*init)(lv_obj_t* page);   //页面初始化
}PAGE;

class PageManage {
public:
    PageManage(PAGE* home_page, lv_obj_t* (*init)(lv_obj_t* page));
    ~PageManage();

public:
    void page_manage_add_page(PAGE* page, int  id, lv_obj_t*(*init)(lv_obj_t* page));
    void page_manage_init_pages(lv_obj_t *iPage);
    void page_manage_switch_page(int id);

private:
    lv_obj_t * curr_page;
    vector<PAGE *> pageList;
    vector<lv_obj_t*> pageListInit;
};

#endif //LVGL_PAGEMANAGE_H
