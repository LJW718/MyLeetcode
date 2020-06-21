/*
//
// Created by Administrator on 2020/6/10 0010.
//
1365. 有多少小于当前数字的数字
        给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。


示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释：
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。
对于 nums[3]=2 存在一个比它小的数字：（1）。
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]
*/

#include <stdio.h>
#include <malloc.h>

int Find(int *nums, int start, int end, int dest)
{
    int count = 0;
    for (int i = start; i < end; i++) {
        if (nums[i] < dest) {
            count++;
        }
    }
    return count;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize < 1) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numsSize;
    int *result = (int *)malloc(sizeof(int) * numsSize);
    if (result) {
        // 1、计算当前数左边比他小的数
        // 2、计算当前数右边比他小的数
        // 3、求和
        for (int i = 0; i < numsSize; i++) {
            int left = Find(nums,0, i, nums[i]);
            int right = Find(nums,i+1, numsSize,nums[i]);
            result[i] = left +right;
        }
    }
    printf("1365.smallerNumbersThanCurrent:\n");
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return result;
}
