
#ifndef __LC_LIST_H__
#define __LC_LIST_H__

#include "pub_def.h"

//02.01. 移除重复节点
struct ListNode* removeDuplicateNodes(struct ListNode* head);
//19. 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
//24. 两两交换链表中的节点
struct ListNode* swapPairs(struct ListNode* head);

void LC_List_Demo(void);

#endif