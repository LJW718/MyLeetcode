/*
179. 最大数
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/



/* 思路：利用qsort函数，将数组元素排列起来,将数组元素拼接起来组成字符串
   难点：回调函数comp，不太好想，strcmp()函数是按字典序比较字符串的。
*/
int comp(const void* a, const void* b)
{
    char bufa[64] = {0};
    char bufb[64] = {0};
    sprintf(bufa, "%d%d", *(int*)a, *(int*)b);
    sprintf(bufb, "%d%d", *(int*)b, *(int*)a);
    return strcmp(bufb, bufa);
}

char * largestNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), comp);

    char* result = (char*)malloc(sizeof(char) * 1024);
    (void)memset(result, '\0', sizeof(char) * 1024);
    char tmp[12] = {0};
    for (int i = 0; i < numsSize; i++) {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%d", nums[i]);
        strcat(result, tmp);
    }
    /* 特殊处理，输入全为0 */
    while (*result == '0' && *(result+1) == '0') {
        result++;
    }
    return result;
}