/*230. 二叉搜索树中第K小的元素
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void GetKthSmallestValue(struct TreeNode* root, int *k, int *value)
{
    if (root == NULL || *k <= 0 || *value != 0) {
        return;
    }
    GetKthSmallestValue(root->left, k, value);
    (*k)--;

    if (*k == 0) {
        *value = root->val;
        return;
    }
    GetKthSmallestValue(root->right, k, value);
}

int kthSmallest(struct TreeNode* root, int k) {
    if (root == NULL) {
        return -1;
    }
    int value = 0;
    GetKthSmallestValue(root, &k, &value);
    return value;
}