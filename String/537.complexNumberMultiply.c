/**
 *Created by liujingwen on 2020/6/27 0027.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

/*
 * 537. 复数乘法
给定两个表示复数的字符串。

返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:

输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2:

输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
注意:

输入字符串不包含额外的空格。
输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。

思路：1、sscanf函数的使用
     2、复数乘法公式
 */


#include <stdio.h>
#include <malloc.h>

#define  MAX_SIZE 1024

char * complexNumberMultiply(char * a, char * b)
{
    if (a == NULL || b == NULL) {
        return NULL;
    }
    // (a + bi) * (c + di) = (ac－bd)+(bc+ad)i
    char *result = (char *)malloc(sizeof(char) * MAX_SIZE);
    int realNuma, realNumb, realNumc, realNumd;  //实数a,b,c,d
    sscanf(a,"%d+%di",&realNuma, &realNumb);
    sscanf(b,"%d+%di",&realNumc, &realNumd);
    snprintf(result, 1024,"%d+%di",(realNuma * realNumc - realNumb * realNumd),
                                             (realNumb * realNumc + realNuma * realNumd));
    printf("\n537.complexNumberMultiply = %s\n", result);
    return result;
}