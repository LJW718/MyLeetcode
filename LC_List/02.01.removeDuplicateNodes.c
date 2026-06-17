/**
 *Created by liujingwen on 2020/6/26 0026.
 *Copyright (c) 2020 https://github.com/LJW718/MyLeetcode. All rights reserved.
 */

/**
面试题 02.01. 移除重复节点
        编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

输入：[1, 2, 3, 3, 2, 1]
输出：[1, 2, 3]
示例2:

输入：[1, 1, 1, 1, 2]
输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？
*/

#include <stdio.h>

#define FAIL -1
#define SUC  0

struct ListNode {
   int val;
   struct ListNode *next;
};

int FindCurVal(int *arr, int cnt, int cur)
{
    for (int i = 0; i < cnt; i++) {
        if (cur == arr[i]) {
            return SUC;
        }
    }
    return FAIL;
}

struct ListNode* removeDuplicateNodes(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *prev = head;
    struct ListNode *cur  = head->next;
    int arr[20001] = {0};
    int cnt = 0;
    arr[0] = head->val;
    cnt += 1;
    while (cur != NULL) {
        if (FAIL == FindCurVal(arr, cnt, cur->val)) {
            arr[cnt++] = cur->val;
            prev->next = cur;
            prev = cur;
        }
        cur = cur->next;
    }
    prev->next = NULL;
    return head;
}