/*
19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <malloc.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    struct ListNode* p1  = head; //慢指针
    struct ListNode* p2  = head; //快指针
    struct ListNode* pre = NULL; //指向删除节点的前一个节点指针

    int i = 0;
    while (i < n) {
        p2 = p2->next;  //快指针先走n步
        ++i;
    }
    /* 找到被删除节点p1和它的前一个节点pre */
    while (p2) {
        pre = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (pre) {
        // pre节点存在
        pre->next = p1->next;
        free(p1);
        p1 = NULL;
    } else {
        // pre节点不存在，即删除倒数第n个节点是头节点
        head = p1->next;
        free(p1);
        p1 = NULL;
    }
    return head;
}