/**
 *Created by liujingwen on 2020/6/29 0029.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

#ifndef MYLEETCODE_ARRAYHEADERFILE_H
#define MYLEETCODE_ARRAYHEADERFILE_H

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include <stdbool.h>

//665. 非递减数列
bool checkPossibility(int* nums, int numsSize);

//3. 无重复字符的最长子串
int lengthOfLongestSubstring(char * s);

#endif //MYLEETCODE_ARRAYHEADERFILE_H
