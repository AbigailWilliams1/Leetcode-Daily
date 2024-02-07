/*
993. 二叉树的堂兄弟节点             难度：简单
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。

链接：https://leetcode.cn/problems/cousins-in-binary-tree/description/
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
    int parent[101], depth[101];
public:
    void dfs(TreeNode* root, int k){
        if(!root)return;
        depth[root->val] = k;
        if(root->left)parent[root->left->val] = root->val;
        if(root->right)parent[root->right->val] = root->val;
        dfs(root->left, k+1);
        dfs(root->right, k+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0);
        return parent[x] != parent[y] && depth[x] == depth[y];
    }
};