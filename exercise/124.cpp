/*
124. 二叉树中的最大路径和               难度：困难
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。
同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。

链接：https://leetcode.cn/problems/binary-tree-maximum-path-sum/

执行用时：32 ms, 在所有 C++ 提交中击败了13.31% 的用户
内存消耗：26.8 MB, 在所有 C++ 提交中击败了90.02% 的用户
通过测试用例：94 / 94
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = INT_MIN;
public:
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left = (root->left)?max(0, dfs(root->left)):0;
        int right = (root->right)?max(0, dfs(root->right)):0;
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
};