#include "lc_list.h"

void LC_List_Demo(void)
{
    FUNC_ENTRY();
    LOG_INFO("LC_LIST_DEBUG = %d", LC_LIST_DEBUG);
    if (!LC_LIST_DEBUG)
    {
        FUNC_EXIT();
        return;
    }
}