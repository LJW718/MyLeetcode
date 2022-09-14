/**
 *Created by liujingwen on 2020/12/20 0020.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
 * */

#include <stdio.h>
#include <string.h>
#include "ArrayHeaderFile.h"

int lengthOfLongestSubstring(char * s)
{
    if (s == NULL) {
        return 0;
    }
    size_t sSize = strlen(s);
    int start = 0;
    int end = 0;
    int windowSize = 0;
    int result = 0;
    while (end < sSize) {
        char tmpChar = s[end];
        for (int index = start; index < end; index++) {
            if (tmpChar == s[index]) {
                start = index + 1;
                windowSize = end - start;
                break;
            }
        }
        end++;
        windowSize++;
        result = MAX(windowSize, result);
    }
    printf("3.lengthOfLongestSubstring = %d \n", result);
    return result;

}