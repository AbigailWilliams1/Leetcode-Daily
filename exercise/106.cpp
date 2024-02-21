/*
106. 从中序与后序遍历序列构造二叉树             难度：中等
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
#include "temp.h"

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
    unordered_map<int, int> inorder_idx;
public:
    TreeNode* dfsBuild(vector<int>& inorder, vector<int>& postorder, int in_l, int in_r, int pos_l, int pos_r){
        if(in_l > in_r)return nullptr;
        int root_val = postorder[pos_r], root_idx = inorder_idx[root_val];
        TreeNode* root = new TreeNode(root_val);
        if(in_l == in_r)return root;
        root->left = dfsBuild(inorder, postorder, in_l, root_idx - 1, pos_l, root_idx + pos_l - in_l - 1);
        root->right = dfsBuild(inorder, postorder, root_idx + 1, in_r, root_idx + pos_r - in_r, pos_r - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            inorder_idx[inorder[i]] = i;
        return dfsBuild(inorder,  postorder, 0, n - 1, 0, n - 1);
    }
};