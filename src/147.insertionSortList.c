/*
147. 对链表进行插入排序
对链表进行插入排序。

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode  *pre, *cur, *next;
    struct ListNode  dummy = {0};
    cur = head->next;
    dummy.next = head;
    head->next = NULL;  //从第二个节点开始取元素，往新链表上插入
    while (cur) {
        next = cur->next;
        pre = &dummy;
        while (pre->next && pre->next->val <= cur->val) {
            pre = pre->next;
        }
        cur->next = pre->next;
        pre->next = cur;
        cur = next;
    }
    return dummy.next;
}