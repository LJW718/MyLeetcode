/**
 *Created by liujingwen on 2020/6/27 0027.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

#ifndef __LC_STRING_H__
#define __LC_STRING_H__

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "pub_def.h"

//890. 查找和替换模式
char ** findAndReplacePattern(char words[][10], int wordsSize, char * pattern, UINT32* returnSize);

//12. 整数转罗马数字
char * intToRoman(int num);

//17. 电话号码的字母组合
char **letterCombinations(char * digits, UINT32* returnSize);

//22. 括号生成
char ** generateParenthesis(UINT32 n, UINT32* returnSize);

//537. 复数乘法
char * complexNumberMultiply(char * a, char * b);

// 8. 字符串转换整数 (atoi)
int myAtoi(char* s);

void LC_String_Demo(void);

#endif //MYLEETCODE_STRINGHEADERFILE_H
