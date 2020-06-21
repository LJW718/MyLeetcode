//
// Created by Administrator on 2020/6/20 0020.
//

/*
 * 583. 两个字符串的删除操作
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。



示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"


提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。

 思路:
 1、先求出两个字符串的最长公共子序列长度
 2、字符串1 - 公共子序列 = 要删除的字符个数（即步数）
 3、字符串2同步骤2
 4、步骤2、3结果求和即为结果
 * */


#include <stdio.h>
#include <string.h>

//我自己计算机申请a[1000][1000]会报错，100不会，实际提交代码注意边界值，为1001

#define MAX_SIZE 100
#define MAX(a, b) ((a) > (b) ? (a) : (b))



static int longestCommonSubsequence(char * text1, char * text2) {
    if (text1 == NULL || text2 == NULL) {
        return 0;
    }

    int m = strlen(text1);
    int n = strlen(text2);
    int dp[MAX_SIZE][MAX_SIZE] = {0};

    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("longestCommonSubsequence  = %d\n", dp[m][n]);
    return dp[m][n];
}

int minDistance(char * word1, char * word2)
{
    if (word1 != NULL && word2 != NULL) {
        int maxComseq = longestCommonSubsequence(word1, word2);
        int word1Size = strlen(word1);
        int woed2Size = strlen(word2);
        printf("583.minDistance = %d\n", word1Size + woed2Size - 2 * maxComseq);
        return word1Size + woed2Size - 2 * maxComseq;
    } else if (word1 == NULL) {
        return strlen(word2);
    } else {
        return strlen(word1);
    }
}