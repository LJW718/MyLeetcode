//
// Created by Administrator on 2020/6/25 0025.
//

/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

//方法：快速幂法
//1,当n为偶数时，x(n) = (x * x)(n / 2)
//2,当n为奇数时，x(n) = (x * x)((n - 1) / 2) * x

#include <math.h>
#include <stdio.h>

double pow_quick(double x, int n){
    double  dRet = 1.0;
    if (n == 0) {
        return dRet;
    }
    if (n == 1) {
        return x;
    }
    if (n == -1) {
        return 1 / x;
    }
    if (fabs(x - 0.0) < 0.000001) {
        return x;
    }
    if (fabs(x - 1.0) < 0.000001) {
        return x;
    }
    if (fabs(x + 1.0) < 0.000001) {
        if (0 == (n % 2)) {
            return dRet;
        } else {
            return x;
        }
    }
    if (0 == (n % 2)) {
        dRet = pow_quick(x * x, n / 2);
    } else {
        dRet = pow_quick(x * x, (n - 1) / 2) * x;
    }
    return dRet;
}

double myPow(double x, int n){
    double tmp = 0;
    tmp = pow_quick(x, n);
    printf("50.myPow: x = %f, n = %d, myPow = %f\n", x, n, tmp);
    return tmp;
}



