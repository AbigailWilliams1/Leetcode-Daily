/*
94. 二叉树的中序遍历                难度：简单
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(!root)return;
            dfs(root->left);
            ans.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};