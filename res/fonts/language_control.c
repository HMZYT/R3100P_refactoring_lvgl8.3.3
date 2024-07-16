#include "language_control.h"
#include "lv_i18n.h"

#define SIZE_OF_INFO_DETAIL 100

uint8_t selected_language = 0;

const char *language_type_info[End_Flag] = {
        "zh-cn",
        "en-GB",
};

typedef struct
{
    lv_obj_t *obj;
    char *obj_txt;
} language_obj_info;

const char *language_current = "zh-cn";
int16_t nindex = 0;
static language_obj_info info_detail[SIZE_OF_INFO_DETAIL];

void language_set_current_lang(int32_t num)
{
    if (num < End_Flag)
    {
        language_current = language_type_info[num];
    }
}

void language_lv_label_set_text(lv_obj_t *obj_label, char *info_label)
{

    lv_label_set_text(obj_label, _(info_label));
    info_detail[nindex].obj = obj_label;
    info_detail[nindex].obj_txt = info_label;
    nindex++;
}


void language_lv_label_set_text_static(lv_obj_t *obj_label, const char *info_label)
{
    if(info_label)
    {
        uint32_t len = strlen(info_label);
        char * temp_char = (char*)lv_mem_alloc(len);
        strcpy(temp_char,info_label);
        lv_label_set_text(obj_label,_(temp_char));
        lv_mem_free(temp_char);
    }
}

void language_clear_label_list(void)
{
    lv_memset(&info_detail, 0, sizeof(info_detail));
    nindex = 0;
}

void language_change_callback(void)
{
    if (language_current == NULL)
    {
        return;
    }

    lv_i18n_set_locale(language_current);
    for (int obj_index = 0; obj_index < nindex; obj_index++)
    {
        language_obj_info temp_obj_info = info_detail[obj_index];

        // language_lv_label_set_text
        if (temp_obj_info.obj_txt != NULL)
        {
            const char *temp_txt = _(temp_obj_info.obj_txt);
            if (lv_obj_check_type(temp_obj_info.obj, &lv_label_class))
            {
                lv_label_set_text(temp_obj_info.obj, temp_txt);
            }
        }
    }
}
