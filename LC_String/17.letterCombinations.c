//
// Created by Administrator on 2020/6/25 0025.
//
/**
 * 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define  MAX_SIZE  1024
#define  STACK_SIZE 10


void DFS(char * digits, int* returnSize, char **result, char **letters, char *stack, int digitSize)
{
    if (digitSize == strlen(digits)) {
        result[(*returnSize)] = (char *)malloc(sizeof(char) * STACK_SIZE);
        strcpy(result[(*returnSize)], stack);
        (*returnSize) += 1;
        return;
    } else {
        for (int j = 0; j < strlen(letters[digits[digitSize] - '0' - 2]); j++) {
            stack[digitSize] = letters[digits[digitSize] - '0' - 2][j];
            DFS(digits, returnSize, result, letters, stack, digitSize + 1);
        }
    }
    return;
}


char **letterCombinations(char * digits, int* returnSize)
{
    (*returnSize) = 0;
    if (strlen(digits) == 0) {
        return NULL;
    }
    char *letterCom[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char stack[STACK_SIZE - 1] = {0};
    char **result = (char **)malloc(sizeof(char*) * MAX_SIZE);
    DFS(digits, returnSize, result, letterCom, stack, 0);
    printf("17.letterCombinations :\n");
    for (int i = 0; i < *returnSize; i++) {
        printf("%s\n", result[i]);
    }
    return result;
}
