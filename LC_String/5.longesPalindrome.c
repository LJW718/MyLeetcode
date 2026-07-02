/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

#include "lc_string.h"

int expand_around_center(char *s, int left, int right)
{
    /* 从中心向两端扩展，返回当前回文串的长度 */
    while((left >= 0) && (right < (int)strlen(s)) && (s[left] == s[right]))
    {
        left--;
        right++;
    }
    return right -left - 1;
}

char *longestPalindrome(char *s)
{
    if (s == NULL || strlen(s) < 1)
    {
        return "";
    }

    int start = 0, end = 0;  // 记录最长回文子串的起始和结束索引
    int len1 = 0, len2 = 0, max_len = 0;

    for (int i = 0; i < (int)strlen(s); i++)
    {
        // 1. 奇数长度扩展（中心为 s[i]）
        len1 = expand_around_center(s, i, i);

        // 2. 偶数长度扩展（中心为 s[i] 和 s[i+1]）
        len2 = expand_around_center(s, i, i + 1);

        max_len = MAX(len1, len2);
        // 如果找到了更长的，更新全局边界
        if (max_len > end - start + 1)
        {
            //  根据中心 i 和长度计算左边界
            //  奇数：i - max_len / 2；偶数：i - (max_len / 2 - 1)
            //  统一公式如下：
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }

    int resLen = end - start + 1;
    char *res = (char *)malloc(resLen + 1);
    memset(res, 0, resLen);
    strncpy(res, s + start, resLen);
    res[resLen] = '\0';
    LOG_DEBUG("str = %s, res = %s, len = %d", s, res, resLen);
    return res;
}
