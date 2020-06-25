//
// Created by Administrator on 2020/6/25 0025.
//公共头文件，所有.c里面的主要函数需要在此声明，才可以在main函数里调用

#ifndef MYLEETCODE_PUBLICHEADERFILE_H
#define MYLEETCODE_PUBLICHEADERFILE_H

//167. 两数之和 II - 输入有序数组
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);
//561. 数组拆分 I
int arrayPairSum(int* nums, int numsSize);
//12. 整数转罗马数字
char * intToRoman(int num);
//22. 括号生成
char ** generateParenthesis(int n, int* returnSize);
//19. 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
//24. 两两交换链表中的节点
struct ListNode* swapPairs(struct ListNode* head);

#endif
