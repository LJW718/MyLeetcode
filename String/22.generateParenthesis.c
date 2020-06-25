
//
// Created by Administrator on 2020/6/18 0018.
//
/*
 * 22. 括号生成
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



    示例：

    输入：n = 3
    输出：[
           "((()))",
           "(()())",
           "(())()",
           "()(())",
           "()()()"
         ]
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define  MAX_SIZE 1024
#define  SUC   0
#define  FAIL -1

#define  DEBUG  1

int CheckParentheses(char *stack, int size)
{
    int cnt = 0;
    int i = 0;
    while(i < size) {
        if (stack[i] == '(') {
            cnt += 1;
        } else {
            cnt -= 1;
        }
        if (cnt < 0) {
            return FAIL;
        }
        ++i;
    }
    return SUC;
}

static void DFS(char **result, char *stack, int size, char parentheses, int n, int leftSize, int rightSize, int *count)
{
    stack[size++] = parentheses;
    if (parentheses == '(') {
        leftSize++;
    } else {
        rightSize++;
    }
    if (size == n * 2) {
        if (leftSize == rightSize) {
            //checkparentheses
            if(SUC == CheckParentheses(stack, size))
            {
                //printf("%s\n  %d", stack, *count);
                result[(*count)] = (char *)malloc(sizeof(char) * size + 1); //考虑结束符
                strcpy(result[*count], stack);
                *count += 1;
            }
        }
        return;
    }
    if(leftSize <= n) {
        DFS(result, stack, size, '(', n, leftSize, rightSize, count);
    }
    DFS(result, stack, size, ')', n, leftSize, rightSize, count);
    return;
}

void FillResult(char **result, int n, int *count)
{
    int leftSize = 0;
    int rightSize = 0;
    char stack[MAX_SIZE] = {0};
    int size = 0;
    DFS(result, stack, size, '(', n, leftSize, rightSize, count);
    return;
}


char ** generateParenthesis(int n, int* returnSize){
    int count = 0;
    char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);
    if (n < 1 || result == NULL) {
        *returnSize = 0;
    } else {
        FillResult(result, n, &count);
    }
    *returnSize = count;
#ifdef DEBUG
    printf("22.generateParenthesis:\n");
    for (int i = 0; i < *returnSize; i++) {
        printf("%s\n", result[i]);
    }
#endif
    return result;
}
