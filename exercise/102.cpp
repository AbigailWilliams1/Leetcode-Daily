/*
102. 二叉树的层序遍历               难度：中等
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                level.push_back(top->val);
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};