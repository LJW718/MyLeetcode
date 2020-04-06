/*
238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize < 1) {
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int) *numsSize);
    if (result) {
        memset(result, 0, sizeof(int) * numsSize);
        int i, j;
        int left = 1;
        int right = 1;
        *returnSize = numsSize;
        // 结果 = 当前下标左边的值 * 当前下标右边的值；
        // 计算当前下标左边的值
        for (i = 0; i < numsSize; i++) {
            result[i] = left;
            left *= nums[i];
        }

        for (j = numsSize - 1; j >= 0; j--) {
            result[j] *= right;
            right *= nums[j];
        }
    }
    return result;
}
