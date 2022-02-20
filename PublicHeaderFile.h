//
// Created by Administrator on 2020/6/25 0025.
//公共头文件，所有.c里面的主要函数需要在此声明，才可以在main函数里调用

#ifndef MYLEETCODE_PUBLICHEADERFILE_H
#define MYLEETCODE_PUBLICHEADERFILE_H

//Arrays
//34. 在排序数组中查找元素的第一个和最后一个位置
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
//64. 最小路径和
int minPathSum(int** grid, int gridSize, int* gridColSize);
//167. 两数之和 II - 输入有序数组
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);
//561. 数组拆分 I
int arrayPairSum(int* nums, int numsSize);
//1480. 一维数组的动态和
int* runningSum(int* nums, int numsSize, int* returnSize);

//Strings
//12. 整数转罗马数字
char * intToRoman(int num);
//17. 电话号码的字母组合
char ** letterCombinations(char * digits, int* returnSize);
//22. 括号生成
char ** generateParenthesis(int n, int* returnSize);
//537. 复数乘法
char * complexNumberMultiply(char * a, char * b);

//List
//02.01. 移除重复节点
struct ListNode* removeDuplicateNodes(struct ListNode* head);
//19. 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
//24. 两两交换链表中的节点
struct ListNode* swapPairs(struct ListNode* head);

//Math
//50. Pow(x, n)
double myPow(double x, int n);
int Test1();

#endif
