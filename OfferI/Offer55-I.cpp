/*
剑指 Offer 55 - I. 二叉树的深度             难度：简单
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

链接：https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/

执行用时：4 ms, 在所有 C++ 提交中击败了90.34% 的用户
内存消耗：18.2 MB, 在所有 C++ 提交中击败了93.74% 的用户
通过测试用例：39 / 39
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return (root == nullptr)?0:max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};