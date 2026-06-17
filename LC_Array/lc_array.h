/**
 *Created by liujingwen on 2020/6/29 0029.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

#ifndef __LC_ARRAY_H__
#define __LC_ARRAY_H__

#include <stdio.h>
#include <search.h>
#include <stdbool.h>
#include "pub_def.h"

//665. 非递减数列
bool checkPossibility(int* nums, int numsSize);

//3. 无重复字符的最长子串
int lengthOfLongestSubstring(char * s);

//34. 在排序数组中查找元素的第一个和最后一个位置
int* searchRange(const int* nums, int numsSize, int target, int* returnSize);

//64. 最小路径和
int minPathSum(int** grid, int gridSize, const int* gridColSize);

//167. 两数之和 II - 输入有序数组
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);

//561. 数组拆分 I
int arrayPairSum(int* nums, int numsSize);

//1480. 一维数组的动态和
int* runningSum(int* nums, int numsSize, int* returnSize);

void LC_Array_Demo(void);

#endif //MYLEETCODE_ARRAYHEADERFILE_H
