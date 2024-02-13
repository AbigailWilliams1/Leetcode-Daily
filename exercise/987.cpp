/*
987. 二叉树的垂序遍历               难度：困难
给你二叉树的根结点 root ，请你设计算法计算二叉树的 垂序遍历 序列。
对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col - 1) 和 (row + 1, col + 1) 。树的根结点位于 (0, 0) 。
二叉树的 垂序遍历 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。
如果同行同列上有多个结点，则按结点的值从小到大进行排序。
返回二叉树的 垂序遍历 序列。

链接：https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/
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
    map<int, multiset<pair<int, int>>> m;
public:
    void dfs(TreeNode* root, int row, int col){
        if(!root)return;
        m[col].insert({row, root->val});
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        for(auto& [col, s] : m){
            vector<int> res;
            for(auto& [row, val] : s)
                res.push_back(val);
            ans.push_back(res);
        }
        return ans;
    }
};