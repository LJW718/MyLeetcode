/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head) {
        struct ListNode *first = head;  //fist遍历指针
        struct ListNode *p1 = NULL;   
        struct ListNode *p2 = NULL;
        while(first)
        {
            p1 = first;
            p2 = first->next;
            if(p1 && p2) {  
                p1->val = (p1->val)^(p2->val);
                p2->val = (p1->val)^(p2->val);
                p1->val = (p1->val)^(p2->val);  //异或操作数据交换
                first = p2->next;
            } else {
                first = p2;
            }
        }
        return head;
    }
    return NULL;
}
