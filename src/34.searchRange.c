/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    if (!nums) {
        return NULL;
    }
    int *result = (int *)malloc(sizeof(int)*2);
    if (!result) {
        return NULL;
    }
    memset(result,0,sizeof(int)*2);
    result[0] = -1;
    result[1] = -1;
    int i,j ;
    for (i = 0; i<numsSize; i++) {
        if (nums[i] == target) {
            result[0] = i;
            break;
        }
    }
    for(j = numsSize-1; j >= i; j--) {
        if (nums[j] == target) {
            result[1] = j;
            break;
        }
    }
    * returnSize = 2;
    return result;
}
