#include "../inc/working_page_faults.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../User/inc/UiRun.h"
#include "../inc/working_page_home.h"
#include "../../res/fonts/language_control.h"
#include "../../theme/inc/theme_R1100P_white.h"
#include "../../theme/inc/theme_style.h"


/// @brief 00：遥控器独立判断故障
static const char* _errs_00_0[] = {
        "0",
};

static const char* _errs_00_1[] = {
        "0",
};

static const char* _errs_00_2[] = {
        "0",
};

static const char* _errs_00_3[] = {
        "30000",
        "30001",
        "0",
        "30003",
};



/// @brief 01：电源/硬件
static const char* _errs_01_0[] = {
        "0",
};

static const char* _errs_01_1[] = {
        "0",
        "10101",
};

static const char* _errs_01_2[] = {
        "0",
        "20101",
};

static const char* _errs_01_3[] = {
        "0",
        "30101",
        "30102",
        "30103",
        "30104",
        "30105",
        "30106",
        "30107",
};

/// @brief 02：控制器输入
static const char* _errs_02_0[] = {
        "0",
};

static const char* _errs_02_1[] = {
        "0",
};

static const char* _errs_02_2[] = {
        "0",
        "20201",
};

static const char* _errs_02_3[] = {
        "0",
        "30201",
        "30202",
        "30203",
        "30204",
        "30205",
        "30206",
        "30207",
        "30208",
        "30209",
        "30210",
        "30211",
        "30212",
        "30213",
        "30214",
        "30215",
        "30216",
        "30217",
};

/// @brief 03：控制器输出
static const char* _errs_03_0[] = {
        "0",
};

static const char* _errs_03_1[] = {
        "0",
};

static const char* _errs_03_2[] = {
        "0",
        "20301",
        "20302",
        "20303",
        "20304",
        "20305",
        "20306",
        "20307",
        "20308",
        "20309",
        "20310",
        "20311",
        "20312",
        "20313",
        "20314",
};

static const char* _errs_03_3[] = {
        "0",
        "30301",
        "30302",
        "30303",
        "30304",
        "30305",
        "30306",
        "30307",
        "30308",
        "30309",
        "30310",
        "30311",
        "30312",
        "30313",
        "30314",
        "30315",
        "30316",
        "30317",
        "30318",
        "30319",
        "30320",
        "30321",
        "30322",
        "30323",
        "30324",
        "30325",
        "30326",
        "30327",
        "30328",
        "30329",
        "30330",
        "30331",
        "30332",
        "30333",
        "30334",
};

/// @brief 04：总线/通信

static const char* _errs_04_0[] = {
        "0",

};
static const char* _errs_04_1[] = {
        "0",
        "10401",

};

static const char* _errs_04_2[] = {
        "0",
        "20401",
        "20402",
        "20403",
        "20404",
        "20405",
        "20406",
        "20407",
        "20408",
        "20409",
};

static const char* _errs_04_3[] = {
        "0",
        "30401",
        "30402",
        "30403",
        "30404",
        "30405",
        "30406",
        "30407",
        "30408",
        "30409",
        "30410",
        "30411",
        "30412",
        "30413",
        "30414",
        "30415",
        "30416",
        "30417",
        "30418",
        "30419",
        "30420",
        "30421",
        "30422",
        "30423",
        "30424",
        "30425",
        "30426",
        "30427",
        "30428",
        "30429",
        "30430",
        "30431",
        "30432",
};

/// @brief 05：GPS/锁车
static const char* _errs_05_0[] = {
        "0",
};
static const char* _errs_05_1[] = {
        "0",
};

static const char* _errs_05_2[] = {
        "0",
        "20501",
};

static const char* _errs_05_3[] = {
        "0",
        "30501",
        "30502",
        "30503",
        "30504",
        "30505",
        "30506",
        "30507",
        "30508",
        "30509",
};

/// @brief 06：泵送
static const char* _errs_06_0[] = {
        "0",
        "00601",
};

static const char* _errs_06_1[] = {
        "0",
        "10601",
        "10602",
};

static const char* _errs_06_2[] = {
        "0",
        "20601",
        "20602",
        "20603",
        "20604",
        "20605",
};

static const char* _errs_06_3[] = {
        "0",
        "30601",
        "30602",
        "30603",
        "30604",
        "30605",
        "30606",
        "30607",
        "30608",
        "30609",
        "30610",
        "30611",
};


/// @brief 07：臂架/支腿
static const char* _errs_07_0[] = {
        "0",
        "00701",
        "00702",
        "00703",
        "00704",
        "00705",
        "00706",
        "00707",
        "00708",
        "00709",
        "00710",
        "00711",
        "00712",
        "00713",
        "00714",
        "00715",
        "00716",
        "00717",
        "00718",
        "00719",
        "00720",
        "00721",
        "00722",
        "00723",
        "00724",
        "00725",
        "00726",
        "00727",
        "00728",
        "00729",
        "00730",
        "00731",
        "00732",
        "00733",
        "00734",
        "00735",
        "00736",
        "00737",
        "00738",
        "00739",
        "00740",
        "00741",
        "00742",
        "00743",
        "00744",
};

static const char* _errs_07_1[] = {
        "0",
        "10701",
};

static const char* _errs_07_2[] = {
        "0",
        "20701",
        "20702",
        "20703",
        "20704",
        "20705",
};

static const char* _errs_07_3[] = {
        "0",
        "30701",
        "30702",
        "30703",
        "30704",
        "30705",
        "30706",
        "30707",
        "30708",
        "30709",
        "30710",
        "30711",
        "30712",
        "30713",
        "30714",
};

/// @brief 08：动力/发动机
static const char* _errs_08_0[] = {
        "0",
        "00801",
};

static const char* _errs_08_1[] = {
        "0",
        "10801",
        "10802",
};

static const char* _errs_08_2[] = {
        "0",
        "20801",
        "20802",
};

static const char* _errs_08_3[] = {
        "0",
        "30801",
        "30802",
        "30803",
        "30804",
        "30805",
        "30806",
        "30807",
        "30808",
        "30809",
        "30810",
};

/// @brief 09：动力/新能源
static const char* _errs_09_0[] = {
        "0",
};

static const char* _errs_09_1[] = {
        "0",
        "10901",
        "10902",
        "10903",
        "10904",
        "10905",
        "10906",
        "10907",
        "10908",
        "10909",
        "10910",
        "10911",
        "10912",
        "10913",
        "10914",
        "10915",
        "10916",
        "10917",
        "10918",
        "10919",
        "10920",
        "10921",
        "10922",
        "10923",
        "10924",
        "10925",
        "10926",
        "10927",
        "10928",
        "10929",
        "10930",
        "10931",
        "10932",
        "10933",
        "10934",
        "10935",
        "10936",
        "10937",
        "10938",
};

static const char* _errs_09_2[] = {
        "0",
        "20901",
        "20902",
        "20903",
        "20904",
        "20905",
        "20906",
        "20907",
        "20908",
        "20909",
        "20910",
        "20911",
        "20912",
        "20913",
        "20914",
        "20915",
        "20916",
        "20917",
        "20918",
        "20919",
        "20920",
        "20921",
        "20922",
        "20923",
        "20924",
        "20925",
        "20926",
        "20927",
        "20928",
};

static const char* _errs_09_3[] = {
        "0",
        "30901",
        "30902",
        "30903",
        "30904",
        "30905",
        "30906",
        "30907",
        "30908",
        "30909",
        "30910",
        "30911",
        "30912",
        "30913",
        "30914",
        "30915",
        "30916",
        "30917",
        "30918",
        "30919",
        "30920",
        "30921",
        "30922",
        "30923",
        "30924",
        "30925",
        "30926",
        "30927",
        "30928",
        "30929",
        "30930",
        "30931",
        "30932",
        "30933",
        "30934",
        "30935",
        "30936",
        "30937",
        "30938",
        "30939",
        "30940",
        "30941",
        "30942",
        "30943",
        "30944",
        "30945",
        "30946",
        "30947",
        "30948",
        "30949",
        "30950",
        "30951",
        "30952",
        "30953",
        "30954",
        "30955",
        "30956",
        "30957",
        "30958",
        "30959",
        "30960",
        "30961",
        "30962",
        "30963",
        "30964",
        "30965",
        "30966",
};

/// @brief 10：辅助系统
static const char* _errs_10_0[] = {
        "0",
};

static const char* _errs_10_1[] = {
        "0",
};

static const char* _errs_10_2[] = {
        "0",
        "21001",
        "21002",
        "21003",
        "21004",
};

static const char* _errs_10_3[] = {
        "",
        "31001",
        "31002",
};

/// @brief 11：防倾翻
static const char* _errs_11_0[] = {
        "0",
};

static const char* _errs_11_1[] = {
        "0",
};

static const char* _errs_11_2[] = {
        "0",
        "21101",
};

static const char* _errs_11_3[] = {
        "0",
        "31101",
        "31102",
        "31103",
        "31104",
        "31105",
        "31106",
        "31107",
        "31108",
        "31109",
        "31110",
        "31111",
        "31112",
        "31113",
        "31114",
        "31115",
        "31116",
        "31117",
        "0",
        "0",
        "0",
        "31121",
        "31122",
        "31123",
        "31124",
        "31125",
};

/// @brief 12：安全/防碰撞
static const char* _errs_12_0[] = {
        "0",
};

static const char* _errs_12_1[] = {
        "0",
};

static const char* _errs_12_2[] = {
        "0",
        "21201",
        "21202",
        "21203",
        "21204",
        "21205",
        "21206",
};

static const char* _errs_12_3[] = {
        "0",
        "31201",
        "31202",
        "31203",
        "31204",
        "31205",
        "31206",
        "31207",
        "31208",
};

/// @brief 13：自动布料
static const char* _errs_13_0[] = {
        "0",
};

static const char* _errs_13_1[] = {
        "0",
};

static const char* _errs_13_2[] = {
        "0",
};

static const char* _errs_13_3[] = {
        "0",
        "31301",
        "31302",
        "31303",
        "31304",
        "31305",
        "31306",
        "31307",
        "31308",
        "31309",
        "31310",
        "31311",
        "31312",
        "31313",
        "31314",
        "31315",
        "31316",
        "31317",
        "31318",
        "31319",
        "31320",
};

/// @brief 14：砼管
static const char* _errs_14_0[] = {
        "0",
};

static const char* _errs_14_1[] = {
        "0",
};

static const char* _errs_14_2[] = {
        "0",
        "21401",
        "21402",
        "21403",
        "21404",
        "21405",
        "21406",
        "21407",
        "21408",
        "21409",
        "21410",
        "21411",
        "21412",
        "21413",
        "21414",
        "21415",
        "21416",
        "21417",
        "21418",
        "21419",
        "21420",
        "21421",
        "21422",
        "21423",
        "21424",
        "21425",
};

static const char* _errs_14_3[] = {
        "0",
};

static void _set_data_8(lv_obj_t *label, uint8_t v)
{
    char temp[10];
    sprintf(temp, "%d", v);
    lv_label_set_text(label, temp);
}

static void _set_data_16(lv_obj_t *label, uint16_t v)
{
    char temp[10];
    sprintf(temp, "%05d", v);
    lv_label_set_text(label, temp);
}

lv_obj_t* working_page_faults_init(lv_obj_t *page)
{
    working_page_faults_t *p = lv_mem_alloc(sizeof (working_page_faults_t));
    uint16_t parent_width, parent_height;

    parent_width = lv_disp_get_hor_res(NULL);
    parent_height = lv_disp_get_ver_res(NULL);

    int i;

    static lv_style_t fault_style;
    lv_style_init(&fault_style);
    lv_style_set_text_color(&fault_style, lv_color_black());
    lv_style_set_text_font(&fault_style, &working_mode_36px);

    static lv_style_t fault_style1;
    lv_style_init(&fault_style1);
    lv_style_set_text_color(&fault_style1, lv_color_black());
    lv_style_set_text_align(&fault_style1, LV_TEXT_ALIGN_LEFT);
    lv_style_set_text_font(&fault_style1, &working_mode_36px);

    lv_obj_t *obj = lv_obj_create(page);
    lv_obj_set_size(obj, parent_width, parent_height - 60 - 60);
    lv_obj_set_pos(obj, 0, 60);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_center(page);

    lv_obj_t *temp = lv_label_create( obj );
    language_lv_label_set_text( temp, "label_41" );
    lv_obj_add_style(temp, &fault_style, 0);
    lv_obj_set_pos(temp, 20 , 8 );

    temp = lv_label_create( obj );
    language_lv_label_set_text( temp, "label_42" );
    lv_obj_add_style(temp, &fault_style, 0);
    lv_obj_set_pos(temp, 20 + 200 , 8 );

    temp = lv_label_create( obj );
    language_lv_label_set_text( temp, "label_43" );
    lv_obj_add_style(temp, &fault_style, 0);
    lv_obj_set_pos(temp, 500 , 8 );

    for(i = 0; i < 8; i++)
    {
        p->label_3[i] = lv_label_create( obj );
        language_lv_label_set_text( p->label_3[i], "" );
        lv_obj_add_style(p->label_3[i], &fault_style1, 0);
        lv_obj_set_size(p->label_3[i],490,40);
        lv_obj_set_pos(p->label_3[i], 500 , 60 + 60 *i );
        lv_label_set_long_mode(p->label_3[i],LV_LABEL_LONG_SCROLL_CIRCULAR);
    }

    for(i = 0; i < 8; i++)
    {
        p->label_1[i] = lv_label_create( obj );
        language_lv_label_set_text( p->label_1[i], "" );
        lv_obj_add_style(p->label_1[i], &fault_style1, 0);
        lv_obj_set_pos(p->label_1[i], 33 , 60 + 60 *i );
    }

    for(i = 0; i < 8; i++)
    {
        p->label_2[i] = lv_label_create( obj );
        language_lv_label_set_text( p->label_2[i], "" );
        lv_obj_add_style(p->label_2[i], &fault_style1, 0);
        lv_obj_set_pos(p->label_2[i], 220 , 60 + 60 *i );
    }

    return obj;
}

//static void faults_observer_list_cb(lv_observer_t *observer, lv_subject_t *subject)
//{
//    lv_obj_t *page_rc = lv_observer_get_target_obj(observer);
//    working_page_faults_t *p = (working_page_faults_t *) observer->user_data;
//    static bool _start = false;
//
//    temp_value_t temp_fault_id = lv_subject_get_int_from_type(subject, faults_id, 0, pageid_faults);
//    temp_value_t temp_fault_detail = lv_subject_get_int_from_type(subject, faults_detail, 0, pageid_faults);
//    temp_value_t temp_fault_total = lv_subject_get_int_from_type(subject, faults_total, 0, pageid_faults);
//    if(temp_fault_id.current_value == 1)
//    {
//        if ((temp_fault_detail.current_value / 100 % 100) == 0x00)
//        {
//            _start = false;
//            _set_data_8(p->label_1[(temp_fault_id.current_value - 1)],temp_fault_id.current_value);
//            _set_data_16(p->label_2[(temp_fault_id.current_value - 1)],temp_fault_detail.current_value);
//            switch (temp_fault_detail.current_value / 10000)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8 ], _errs_00_0[temp_fault_detail.current_value % 100] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_1[temp_fault_detail.current_value % 100] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_2[temp_fault_detail.current_value % 100] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_3[temp_fault_detail.current_value % 100] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else
//        {
//            _start = true;
//        }
//    }
//    else if (temp_fault_detail.current_value > 8 )
//    {
//        _start = false;
//    }
//
//    if (temp_fault_id.current_value != 0 && _start)
//    {
//        _set_data_8(p->label_1[(temp_fault_id.current_value  -1)],temp_fault_id.current_value);
//        _set_data_16(p->label_2[(temp_fault_id.current_value  -1)],temp_fault_detail.current_value);
//
//        uint8_t _level,_class,_id;
//        _level = temp_fault_detail.current_value / 10000;
//        _class = temp_fault_detail.current_value / 100 % 100;
//        _id = temp_fault_detail.current_value % 100;
//        if (_class == 0x00)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8 ], _errs_00_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_00_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x01)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_01_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_01_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_01_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_01_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x02)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_02_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_02_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_02_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_02_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x03)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_03_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_03_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_03_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_03_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x04)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_04_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_04_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_04_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_04_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x05)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_05_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_05_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_05_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_05_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x06)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_06_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_06_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_06_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_06_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x07)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_07_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_07_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_07_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_07_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x08)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_08_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_08_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_08_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_08_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x09)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_09_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_09_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_09_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_09_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x0A)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_10_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_10_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_10_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_10_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x0B)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_11_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_11_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_11_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_11_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x0C)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_12_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_12_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_12_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_12_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x0D)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_13_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_13_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_13_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_13_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//        else if (_class == 0x0E)
//        {
//            switch (_level)
//            {
//                case 0x00 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_14_0[_id] );
//                    break;
//                case 0x01 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_14_1[_id] );
//                    break;
//                case 0x02 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_14_2[_id] );
//                    break;
//                case 0x03 :
//                    lv_label_set_text_static( p->label_3[(temp_fault_id.current_value -1) % 8], _errs_14_3[_id] );
//                    break;
//                default:
//                    break;
//            }
//        }
//    }
//
//    //总数变化或者第一条报警变化则清零刷新
//    if (temp_fault_total.different_flag || (temp_fault_id.current_value == 1 && temp_fault_detail.different_flag))
//    {
//        for(int i = 1 ;i < 8; i++)
//        {
//            lv_label_set_text( p->label_1[i], "" );
//            lv_label_set_text( p->label_2[i], "" );
//            lv_label_set_text( p->label_3[i], "" );
//        }
//    }
//}


