#include "../inc/working_page_light.h"
#include "../../User/inc/images_v4_0.h"
#include "../../res/fonts/language_control.h"
#include "../../User/inc/UiRun.h"
#include "../../theme/inc/theme_R1100P_white.h"
#include "../../theme/inc/theme_style.h"

static lights_lcd_button_t *_create_button(lv_obj_t *parent);
static void _button_set_v(lights_lcd_button_t *btn, uint8_t v);                //二选一或三选一开关设置

lv_obj_t* working_page_light_init(lv_obj_t *page)
{
    working_page_light_t *p = lv_mem_alloc(sizeof (working_page_light_t));

    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    //背景
    lv_obj_t *temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_page_bg);
    lv_obj_set_pos(temp_state, 0,60);

    //on
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0f0);
    lv_obj_set_pos(temp_state, 461,182 - 60);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0g0);
    lv_obj_set_pos(temp_state, 601,182 - 60);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0h0);
    lv_obj_set_pos(temp_state, 762,182 - 60);

    //off
    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0f1);
    lv_obj_set_pos(temp_state, 461,392 - 60);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0g1);
    lv_obj_set_pos(temp_state, 601,392 - 60);

    temp_state = lv_img_create(obj);
    lv_img_set_src(temp_state, &control_0h1);
    lv_obj_set_pos(temp_state, 762,392 - 60);

    for (int i = 0; i < 3; ++i)
    {
        p->btns[i] = _create_button(obj);
        lv_obj_set_size(p->btns[i]->ibase, 88, 82);
        lv_obj_set_pos(p->btns[i]->ibase, 457 + 146 * i, 291 - 60);
        _button_set_v(p->btns[i], 0);
    }

    //观察者模式
    //lv_subject_add_observer_obj(&subject_note_all, note_observer_list_cb, page, NULL);

    return obj;
}

static lights_lcd_button_t *_create_button(lv_obj_t *parent)
{
    lights_lcd_button_t *btn = (lights_lcd_button_t *)lv_mem_alloc(sizeof(lights_lcd_button_t));
    if (!btn)
    {
        return NULL;
    }

    btn->ibase = lv_label_create(parent);
    lv_label_set_text(btn->ibase, "");
    btn->v = lv_img_create(btn->ibase);
    lv_img_set_src(btn->v, &control_s_btn02);
    lv_obj_set_pos(btn->v, 0, 0);
    lv_obj_set_size(btn->v, 88, 82);
    lv_obj_clear_flag(btn->ibase, LV_OBJ_FLAG_SCROLLABLE);

    return btn;
}

//二选一或三选一开关设置
static void _button_set_v(lights_lcd_button_t *btn, uint8_t v)
{
    if (v == 0)
    { //中间
        lv_img_set_src(btn->v, &control_s_btn02);
    }
    else if (v == 1)
    { //上
        lv_img_set_src(btn->v, &control_s_btn01);
    }
    else if (v == 2)
    { //下
        lv_img_set_src(btn->v, &control_s_btn03);
    }
    else
    {
        lv_img_set_src(btn->v, &control_s_btn02);
    }
}
