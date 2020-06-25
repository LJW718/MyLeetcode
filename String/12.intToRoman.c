//
// Created by Administrator on 2020/6/21 0021.
//

/*
 * 12. 整数转罗马数字
 ： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define ROMAN_MAXSIZE 5  //最大长度DCCC   加上末位'\0'

#define MAX_SIZE 100

char * intToRoman(int num)
{
    char romanCh[][ROMAN_MAXSIZE] = {"I","II","III","IV","V","VI","VII","VIII","IX",
                                     "X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                                     "C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M","MM","MMM"};
    int  romanNum[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,2000,3000};
    char *result = (char *)malloc(sizeof(char) * MAX_SIZE);
    memset(result, 0, MAX_SIZE);
    int i = sizeof(romanNum) / sizeof(romanNum[0]) - 1;
    int tmpNum = num;
    while (i >= 0) {
        if (tmpNum / romanNum[i] > 0) {
            int tmp = tmpNum / romanNum[i];
            //printf("tmpNum=%d,tmp=%d, roman[%d]=%s, romanNum=%d\n", tmpNum,tmp,i,romanCh[i],romanNum[i]);
            strcat(result,romanCh[i]);
            tmpNum %= romanNum[i];
        }
        --i;
    }
    printf("12.intToRoman num = %d, Roman = %s\n", num, result);
    return result;
}

