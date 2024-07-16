//
// Created by zoomlion on 2024/4/29.
//
#ifndef LVGL_DTR1100PUI_H
#define LVGL_DTR1100PUI_H

#define SIZE_OF_DICT 50
#include <iostream>
using namespace std;

typedef struct {
    int min;
    int max;
} dt_r1100p_data_limit_t;

typedef struct {
    int id;
    void *ptr;
    float factor;//单位之间的转换系数，默认公制是1。
    int acc;//精度，如果实际值为999.99，那么精度值就是100，因为目前精度最大的也就100，为了节省空间用的uint8_类型，后续可根据实际情况更改
    dt_r1100p_data_limit_t *limit;
} dt_r1100p_idict_t;

typedef struct {
    dt_r1100p_idict_t idict[SIZE_OF_DICT];
    int size_cur;
    //log_add_handler data_change_hook;//有数据发生变化的时候就调用这个函数，若该指针为NULL时则不会执行
    int (*get_uint)(void);//获取当前单位
} dt_r1100p_dict_t;

class DtR1100PUi {
public:
    DtR1100PUi();
    ~DtR1100PUi();
public:
    void dtR1100PUiInit();
    bool setDtInt(uint32_t id, int32_t value);
    bool setDtInt(uint32_t id, uint32_t idx, int32_t value);
    //bool setString(int id, string *str, int len, bool en);
    //int getDtInt(int id);
    int getDtInt(uint32_t id);
    //string gtString(int id);
    bool dtR1100pDictAdd(uint32_t id, void *addr, uint8_t acc);
    int32_t dt_R1100P_dict_get_idx(uint32_t id);
    void * getDtIntAdress(uint32_t id);
private:
    dt_r1100p_dict_t g_dt;
};

extern DtR1100PUi dtR1100PUi;

#endif //LVGL_DTR1100PUI_H
