/*
105. 从前序与中序遍历序列构造二叉树             难度：中等
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

// example: preorder: [3,9,20,15,7], inorder: [9,3,15,20,7]

class Solution {
    unordered_map<int, int> inorder_idx;
public:
    TreeNode* dfsBuild(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r){
        if(pre_l > pre_r)return nullptr;
        int root_val = preorder[pre_l], root_idx = inorder_idx[root_val];
        TreeNode* root = new TreeNode(root_val);
        if(pre_l == pre_r)return root;
        root->left = dfsBuild(preorder, inorder, pre_l + 1, root_idx - in_l + pre_l, in_l, root_idx - 1);
        root->right = dfsBuild(preorder, inorder, pre_r + root_idx + 1 - in_r, pre_r, root_idx + 1, in_r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            inorder_idx[inorder[i]] = i;
        return dfsBuild(preorder,  inorder, 0, n - 1, 0, n - 1);
    }
};