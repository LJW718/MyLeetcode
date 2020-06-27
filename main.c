
#include <stdio.h>
#include <malloc.h>
#include "PublicHeaderFile.h"

#define ARRAY_SIZE(nums) ((sizeof(nums)) / (sizeof(nums[0])))

int main() {
    int nums[] = {2,7,11,15};
    int returnSize = 0;
    twoSum(nums, sizeof(nums)/sizeof(nums[0]), 9, &returnSize);
    arrayPairSum(nums, sizeof(nums)/sizeof(nums[0]));
    intToRoman(1234);
    generateParenthesis(5, &returnSize);
    int nums2[] = {5,7,7,8,8,10};
    searchRange(nums2, ARRAY_SIZE(nums2), 8, &returnSize);
    myPow(5.0, 6);
    letterCombinations("234", &returnSize);
    runningSum(nums, ARRAY_SIZE(nums),&returnSize);


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
    //minPathSum(grid, 3,&gridColSize);
    complexNumberMultiply("1+-1i", "1+-1i");

    return 0;
}
