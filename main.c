#include "lc_string.h"
#include "lc_array.h"
#include "ut_hash_test.h"
#include "cbase.h"
#include "lc_list.h"
#include "lc_math.h"

// 日志等级默认LOG_LVL_DEBUG
static UINT8 g_log_lvl = LOG_LVL_INVAILD;

UINT8 get_loglevel(void)
{
    return g_log_lvl;
}

void set_loglevel(E_LOG_LVL lvl)
{
    g_log_lvl = lvl;
}

int main(void)
{
    // 设置LOG等级
    set_loglevel(LOG_LVL_DEBUG);
    FUNC_ENTRY();
    LOG_INFO("log lvl : %d, [1:ERROR, 2:WARN, 3:INFO, 4:DEBUG]", get_loglevel());

    LC_Array_Demo();

    LC_CBase_Demo();

    LC_List_Demo();

    LC_Math_Demo();

    LC_String_Demo();

    LC_UT_Hash_Demo();

    FUNC_EXIT();
    return 0;
}
