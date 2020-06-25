//
// Created by Administrator on 2020/6/25 0025.
//
/*
 * 167. 两数之和 II - 输入有序数组
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int FileResultWithNumbers(int *result, int *numbers, int numbersSize, int target)
{
    int i = 0;
    int j = numbersSize - 1;

    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            result[0] = i + 1;
            result[1] = j + 1;
            break;
        } else if (numbers[i] + numbers[j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return 0;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    if(numbers == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) * 2);
    if (result != NULL) {
        memset(result, 0, sizeof(int) * 2);
        FileResultWithNumbers(result, numbers, numbersSize, target);
    }
    *returnSize = 2;
    printf("167.twoSum: index1 = %d, index2 = %d\n", result[0], result[1]);
    return result;
}