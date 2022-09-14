/**
 *Created by liujingwen on 2020/6/27 0027.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */


/**
 * 1480. 一维数组的动态和
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

示例 1：

输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
示例 3：

输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]


提示：

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>


int FillResultWithNums(int *result, const int *nums, int numsSize)
{
    int tmp = 0;
    for (int i = 0; i < numsSize; i++) {
        tmp += nums[i];
        result[i] = tmp;
    }
    return 0;
}

int* runningSum(int* nums, int numsSize, int* returnSize){
    if (nums == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) * numsSize);
    if (result != NULL) {
        memset(result, 0, sizeof(int) * numsSize);
        FillResultWithNums(result, nums, numsSize);
    }
    *returnSize = numsSize;
    printf("1480.runningSum:\n");
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", result[i]);
    }
    return result;
}

