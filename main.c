
#include <stdio.h>
#include "PublicHeaderFile.h"

int main() {
    int nums[] = {2,7,11,15};
    int returnSize = 0;
    twoSum(nums, sizeof(nums)/sizeof(nums[0]), 9, &returnSize);
    return 0;
}
