/*
94. 二叉树的中序遍历
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void OrderTraversal(struct TreeNode* root, int *output, int *i) 
{
    if (root) {
        OrderTraversal(root->left, output, i);
        output[*i] = root->val; 
        *i += 1;
        OrderTraversal(root->right, output, i);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *output = (int *)malloc(sizeof(int) * 1024);
    int i = 0;
    OrderTraversal(root, output, &i);
    *returnSize = i;
    return output;
}
