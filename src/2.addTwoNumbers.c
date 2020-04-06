
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int arr[1000]={0};  //临时存储 
    int jinwei = 0;     //进位
    int i = 0; 
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!head) {
        return head;
    }
    head->next = NULL;
    struct ListNode *tail = head;
    while (l1 || l2 ) {
        if (l1 && l2) {  //链表长度相等
            if (l1->val+l2->val+jinwei >= 10) {  //进位
                arr[i] = l1->val+l2->val + jinwei - 10;
                jinwei = 1;
            } else {
                arr[i] = l1->val+l2->val + jinwei;
                jinwei = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1) {
            if (l1->val+jinwei >= 10) {  //进位
                arr[i] = l1->val + jinwei - 10;
                jinwei = 1;
            } else {
                arr[i] = l1->val + jinwei;
                jinwei = 0;
            }
            l1 = l1->next;
        } else if (l2) {
            if (l2->val+jinwei >= 10) {  //进位
                arr[i] = l2->val + jinwei - 10;
                jinwei = 1;
            } else {
                arr[i] = l2->val + jinwei;
                jinwei = 0;
            }
            l2 = l2->next;
        }
        i++;   
    }
    if(jinwei == 1)
    {
        arr[i++] = 1;
    }
    //printf("%d",i);
    int j ;
    for (j = 0 ; j < i; j++) {
        //printf("%d",arr[j]);
        tail->next=(struct ListNode *)malloc(sizeof(struct ListNode));
        //尾指针创建一个新的结点以便将值插入
        tail=tail->next;//移动尾结点使其指向新链表的尾结点
        tail->val=arr[j];
    }
    tail->next = NULL;
    return head->next;
}