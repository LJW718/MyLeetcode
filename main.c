#include "lc_string.h"
#include "lc_array.h"
#include "ut_hash_test.h"
#include "cbase.h"
#include "lc_list.h"
#include "lc_math.h"

int main(void) {
    FUNC_ENTRY();

    LOG_INFO("-------------------- CHECK --------------------");
    LOG_INFO("LC_ARRAY_DEBUG   : %d", LC_ARRAY_DEBUG);
    LOG_INFO("LC_CBASE_DEBUG   : %d", LC_CBASE_DEBUG);
    LOG_INFO("LC_LIST_DEBUG    : %d", LC_LIST_DEBUG);
    LOG_INFO("LC_MATH_DEBUG    : %d", LC_MATH_DEBUG);
    LOG_INFO("LC_STRING_DEBUG  : %d", LC_STRING_DEBUG);
    LOG_INFO("LC_UTHASH_DEBUG  : %d", LC_UTHASH_DEBUG);
    LOG_INFO("-------------------- CHECK --------------------\n");

    if (LC_ARRAY_DEBUG)
    {
        LOG_INFO("----------------LC_Array----------------");
        LC_Array_Demo();
        LOG_INFO("----------------LC_Array----------------\n");
    }

    if (LC_CBASE_DEBUG)
    {
        LOG_INFO("----------------LC_CBase----------------");
        LC_CBase_Demo();
        LOG_INFO("----------------LC_CBase----------------\n");
    }

    if (LC_LIST_DEBUG)
    {
        LOG_INFO("----------------LC_List----------------");
        LC_List_Demo();
        LOG_INFO("----------------LC_List----------------\n");
    }

    if (LC_MATH_DEBUG)
    {
        LOG_INFO("----------------LC_Math----------------");
        LC_Math_Demo();
        LOG_INFO("----------------LC_Math----------------\n");
    }

    if (LC_STRING_DEBUG)
    {
        LOG_INFO("----------------LC_String----------------");
        LC_String_Demo();
        LOG_INFO("----------------LC_String----------------\n");
    }

    if (LC_UTHASH_DEBUG)
    {
        LOG_INFO("----------------LC_UT_Hash----------------");
        LC_UT_Hash_Demo();
        LOG_INFO("----------------LC_UT_Hash----------------\n");
    }

    FUNC_EXIT();
    return 0;
}
