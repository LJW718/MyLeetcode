//
// Created by Administrator on 2020/6/24 0024.
//

/*
 * 561. 数组拆分 I
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].

 分析：结果最大，就是min(a,b)尽可能地大，那就是a < b的情况下，尽可能大
 min(1,2)  ==> 1
 min(3,4)  ==> 3
 min(5,6)  ==> 5
 ...
 ...
 ...
 min(n-1,n) ==> n - 1
 所以我将数组升序排序，按下标划分[1,2] [3,4] [5,6]，这样最大结果就是1+3+5+...+n-1,
 也就是排序后的第一个、第三、第五、第n-1个元素之和
 */

#include <stdio.h>
#include <search.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int arrayPairSum(int* nums, int numsSize){
    if(nums == NULL) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = 0;
    for (int i = 0; i < numsSize; i += 2) {
        result += nums[i];
    }
    printf("561.arrayPairSum : %d\n", result);
    return result;
}
