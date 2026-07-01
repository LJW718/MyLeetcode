/*
7. 整数反转

给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。


示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0


提示：

-231 <= x <= 231 - 1
*/

#include "lc_math.h"

int reverse(int x)
{
    int sign = 1;
    long long tmp = (long long)x;
    if (x < 0)
    {
        sign = -1;
        tmp = -tmp;
    }
    if ((tmp > INT_MAX) || (tmp < INT_MIN))
    {
        return 0;
    }
    long long result = 0;
    while (tmp)
    {
        result = (result * 10) + (tmp % 10);
        if (result > INT_MAX)
        {
            return 0;
        }
        tmp /= 10;
    }

    result *= sign;
    LOG_DEBUG("x = %d, result = %d", x, (int)result);
    return result < INT_MIN ? 0 : (int)result;
}