/**
 *Created by liujingwen on 2021/8/22 0027.
 *Copyright (c) 2021 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

/*
18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。



示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<malloc.h>
#include <string.h>

#define MAX_SIZE 100000


int Cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);
    memset((*returnColumnSizes), 0, sizeof(int) * MAX_SIZE);
    if (nums == NULL || numsSize < 4) {
        return NULL;
    }

    int** res = (int**)malloc(sizeof(int*) * MAX_SIZE);
    memset(res, 0, sizeof(int*) * MAX_SIZE);
    qsort(nums, numsSize, sizeof(int), Cmp);
    if (target >= 0 && nums[0] > target) {
        return NULL;
    }
    int a, b, c, d;
    for (a = 0; a <= numsSize - 4; a++) {
        // printf("a = %d\n", a);
        if (a > 0 && nums[a - 1] == nums[a]) {
            continue;	// 去重复
        }
        for (b = a + 1; b <= numsSize - 3; b++) {
            if (b > a + 1 && nums[b] == nums[b - 1]) {
                continue; // 去重复
            }
            c = b + 1;
            d = numsSize - 1;
            while (c < d) {
                if (nums[a] + nums[b] + nums[c] + nums[d] < target) {
                    c++;
                }
                else if (nums[a] + nums[b] + nums[c] + nums[d] > target) {
                    d--;
                }
                else {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[a];
                    res[*returnSize][1] = nums[b];
                    res[*returnSize][2] = nums[c];
                    res[*returnSize][3] = nums[d];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize) += 1;
                    while (c < d && nums[c] == nums[c + 1]) {
                        c++;
                    }
                    while (c < d && nums[d - 1] == nums[d]) {
                        d--;
                    }
                    c++;
                    d--;
                }
            }
        }
    }
    return res;
}