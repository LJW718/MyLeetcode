/**
 *Created by liujingwen on 2021/8/22 0027.
 *Copyright (c) 2021 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

/*
18. ����֮��
����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] ��

0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰� ����˳�� ���ش� ��



ʾ�� 1��

���룺nums = [1,0,-1,0,-2,2], target = 0
�����[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
ʾ�� 2��

���룺nums = [2,2,2,2,2], target = 8
�����[[2,2,2,2]]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<malloc.h>
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
			continue;	// ȥ�ظ�
		}
		for (b = a + 1; b <= numsSize - 3; b++) {
			if (b > a + 1 && nums[b] == nums[b - 1]) {
				continue; // ȥ�ظ�
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