//
// Created by Administrator on 2020/6/21 0021.
//
/*
 * 791. 自定义字符串排序
字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。

S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。

返回任意一种符合条件的字符串T。

示例:
输入:
S = "cba"
T = "abcd"
输出: "cbad"
解释:
S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a".
由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
注意:

S的最大长度为26，其中没有重复的字符。
T的最大长度为200。
S和T只包含小写字符。
 */

#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define  LETTER_SIZE 26
#define  MAX_SIZE 201

void CountFrequencyOfLettersInT(char *T, char *letterStr)
{
    int tSize = strlen(T);
    for (int i = 0; i < tSize; i++) {
        letterStr[(T[i] - 'a')] += 1;  //统计字母出现的次数
    }
    return;
}

void FillResultsWithLetterStrAndS(char *result, char *letterStr, char *S, int *cnt)
{
    for (int i = 0; i < strlen(S); i++) {
        int j = S[i] - 'a';
        for (; letterStr[j] > 0; letterStr[j]--) {
            result[*cnt] = S[i];
            (*cnt) += 1;
        }
    }
    return;
}

void FillResultWithTheRestOfLetterStr(char *result, char *letterStr, int *cnt)
{
    for (int i = 0; i < LETTER_SIZE; i++) {
        for (; letterStr[i] > 0; letterStr[i]--) {
            result[*cnt] = i + 'a';
            (*cnt) += 1;
        }
    }
}

char * customSortString(char * S, char * T){
    if (S == NULL || T == NULL) {
        return NULL;
    }
    char letterStr[LETTER_SIZE] = {0};
    CountFrequencyOfLettersInT(T, letterStr);

    int cnt = 0;
    char *result = (char *)malloc(sizeof(char) * MAX_SIZE);
    memset(result, 0, MAX_SIZE);
    FillResultsWithLetterStrAndS(result, letterStr, S, &cnt);

    FillResultWithTheRestOfLetterStr(result, letterStr, &cnt);

    printf("791.customSortString = %s\n", result);
    return result;
}