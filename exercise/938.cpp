/*
938. 二叉搜索树的范围和             难度：简单
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

链接：https://leetcode.cn/problems/range-sum-of-bst/description/
*/
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        if(root->val < low)return rangeSumBST(root->right, low, high);
        if(root->val > high)return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high)
                         + rangeSumBST(root->right, low, high);
    }
};