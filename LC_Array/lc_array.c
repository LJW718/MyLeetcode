
#include "lc_array.h"

void LC_Array_Demo(void)
{
    FUNC_ENTRY();
    LOG_INFO("LC_ARRAY_DEBUG = %d", LC_ARRAY_DEBUG);
    if (!LC_ARRAY_DEBUG)
    {
        FUNC_EXIT();
        return;
    }
    int nums[] = {2,7,11,15};
    int returnSize = 0;
    twoSum(nums, sizeof(nums)/sizeof(nums[0]), 9, &returnSize);

    arrayPairSum(nums, sizeof(nums)/sizeof(nums[0]));

    int nums2[] = {5,7,7,8,8,10};
    searchRange(nums2, ARRAY_SIZE(nums2), 8, &returnSize);

    runningSum(nums, ARRAY_SIZE(nums), &returnSize);

    int gridColSize = 3;
    int **grid = (int **)malloc(sizeof(int *) * 3);
    if (grid != NULL) {
        for (int i = 0; i < 3; i++) {
            grid[i] = (int *)malloc(sizeof(int) * 3);
            for (int j = 0; j < 3; j++) {
                grid[i][j] = i + j;
            }
        }
    }
    minPathSum(grid, 3,&gridColSize);

    int nums3[] = {3,4,2,3};
    checkPossibility(nums3, ARRAY_SIZE(nums));

    lengthOfLongestSubstring("abcabcbb");

    int nums4[] = {1,0,-1,0,-2,2};
    INT32 target = 0;
    INT32 *retColSize = NULL;
    int **res = fourSum(nums4, ARRAY_SIZE(nums4), target, &returnSize, &retColSize);
    for (UINT8 i = 0; i < returnSize; i++)
    {
        // 分段分配（int ** 类型，每行单独 malloc）, 正确释放顺序（先释放行，再释放列指针）
        free(res[i]);
    }
    free(res);
    free(retColSize);
    FUNC_EXIT();
    return;
}