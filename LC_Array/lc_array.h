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

//34. 在排序数组中查找元素的第一个和最后一个位置
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

//64. 最小路径和
int minPathSum(int** grid, int gridSize, int* gridColSize);

//167. 两数之和 II - 输入有序数组
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);

//561. 数组拆分 I
int arrayPairSum(int* nums, int numsSize);

//1480. 一维数组的动态和
int* runningSum(int* nums, int numsSize, int* returnSize);

#endif //MYLEETCODE_ARRAYHEADERFILE_H
