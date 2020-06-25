
#include <stdio.h>
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
    return 0;
}
