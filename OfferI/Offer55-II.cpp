/*
剑指 Offer 55 - II. 平衡二叉树              难度：简单
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

链接：https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/

执行用时：4 ms, 在所有 C++ 提交中击败了98.17% 的用户
内存消耗：21.6 MB, 在所有 C++ 提交中击败了5.02% 的用户
通过测试用例：227 / 227
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
    pair<int, bool> isBalance(TreeNode* root){
        if(root == nullptr)return {0, true};
        pair<int, bool> ans;
        pair<int, bool> l = isBalance(root->left);
        pair<int, bool> r = isBalance(root->right); 
        ans.first = max(l.first, r.first)+1;
        if(l.second && r.second && abs(l.first - r.first)<=1)
            ans.second = true;
        else
            ans.second = false;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalance(root).second;
    }
};