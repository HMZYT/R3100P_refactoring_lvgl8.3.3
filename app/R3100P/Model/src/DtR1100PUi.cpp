//
// Created by zoomlion on 2024/4/29.
//

#include "../inc/DtR1100PUi.h"

DtR1100PUi::DtR1100PUi()
{
}

DtR1100PUi::~DtR1100PUi()
{

}

void DtR1100PUi::dtR1100PUiInit()
{

}

int32_t DtR1100PUi::dt_R1100P_dict_get_idx(uint32_t id)
{
    dt_r1100p_dict_t *s = &g_dt;
    if (NULL == s) {
        return -2;
    }

    uint32_t low = 0;
    uint32_t high = s->size_cur - 1;

    while (low <= high) {
        uint32_t mid = low + (high - low) / 2;

        if (s->idict[mid].id == id) {
            return mid;
        } else if (s->idict[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int32_t DtR1100PUi::getDtInt(uint32_t id)
{
    int32_t _dict_idx = dt_R1100P_dict_get_idx(id);
    if (_dict_idx != -1 && _dict_idx != -2) {
        int32_t value = *(int32_t *) g_dt.idict[_dict_idx].ptr;
        return value;
    } else {// 没有找到对应的ID
        return 0;
    }
}

void * DtR1100PUi::getDtIntAdress(uint32_t id)
{
    int32_t _dict_idx = dt_R1100P_dict_get_idx(id);
    if (_dict_idx != -1 && _dict_idx != -2) {
        return g_dt.idict[_dict_idx].ptr;
    }else {
        return NULL;
    }
}

bool DtR1100PUi::setDtInt(uint32_t id, int32_t value)
{
    int32_t _dict_idx = dt_R1100P_dict_get_idx(id);
    if (_dict_idx != -1 && _dict_idx != -2) {
        if (NULL != g_dt.idict[_dict_idx].limit) {
            if (value > g_dt.idict[_dict_idx].limit->max) {
                value = g_dt.idict[_dict_idx].limit->max;
            } else if (value < g_dt.idict[_dict_idx].limit->min) {
                value = g_dt.idict[_dict_idx].limit->min;
            }
        }

        int32_t *_temp_ptr = (int32_t *) g_dt.idict[_dict_idx].ptr;
        *_temp_ptr = value;

        return true;
    } else {// 没有找到对应的ID
        return false;
    }
}

bool DtR1100PUi::setDtInt(uint32_t id, uint32_t idx, int32_t value)
{
    int32_t _dict_idx = dt_R1100P_dict_get_idx(id);
    if (_dict_idx != -1 && _dict_idx != -2) {
        if (NULL != g_dt.idict[_dict_idx].limit) {
            if (value > g_dt.idict[_dict_idx].limit->max) {
                value = g_dt.idict[_dict_idx].limit->max;
            } else if (value < g_dt.idict[_dict_idx].limit->min) {
                value = g_dt.idict[_dict_idx].limit->min;
            }
        }

        int32_t *_temp_ptr = (int32_t *) g_dt.idict[_dict_idx].ptr;
        _temp_ptr = _temp_ptr + idx;
        *_temp_ptr = value;
        return true;
    } else {// 没有找到对应的ID
        return false;
    }
}

bool DtR1100PUi::dtR1100pDictAdd(uint32_t id, void *addr, uint8_t acc)
{
    dt_r1100p_dict_t *s = &g_dt;
    if (s->size_cur >= SIZE_OF_DICT)
    {
        // 字典已满，无法添加更多项
        return false;
    }

    //查找插入位置
    uint32_t i;
    for (i = 0; i < s->size_cur; i++) {
        if (s->idict[i].id > id) {
            break;
        }
    }

    // 向后移动元素以便插入新元素
    for (uint32_t j = s->size_cur; j > i; j--) {
        s->idict[j] = s->idict[j - 1];
    }

    // 插入新元素
    s->idict[i].id = id;
    s->idict[i].ptr = addr;
    //dt->idict[i].limit = limit;
    s->idict[i].acc = acc;
    //dt->idict[i].factor = factor;
    s->size_cur++;

    return true;
}

DtR1100PUi dtR1100PUi;