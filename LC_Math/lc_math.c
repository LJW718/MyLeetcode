#include "lc_math.h"

void LC_Math_Demo(void)
{
    FUNC_ENTRY();
    LOG_INFO("LC_MATH_DEBUG = %d", LC_MATH_DEBUG);
    if (!LC_MATH_DEBUG)
    {
        FUNC_EXIT();
        return;
    }

    myPow(5.0, 6);

    reverse(-14562);
    reverse(12345);

    FUNC_EXIT();
}