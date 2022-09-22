/*
687. 最长同值路径               难度：中等
给定一个二叉树的 root，返回最长的路径的长度，这个路径中的 每个节点具有相同值。这条路径可以经过也可以不经过根节点。
两个节点之间的路径长度由它们之间的边数表示。

链接：https://leetcode.cn/problems/longest-univalue-path/

执行用时：260 ms, 在所有 C++ 提交中击败了5.06% 的用户
内存消耗：106.6 MB, 在所有 C++ 提交中击败了5.06% 的用户
通过测试用例：71 / 71
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
    unordered_map<TreeNode*, int> lmap;
    int ans = -1;
public:
    int longestPath(TreeNode* root){
        if(!root)return 0;
        if(!root->left || root->left->val != root->val){
            if(!root->right || root->right->val != root->val)lmap[root] = 1;
            else lmap[root] = 1 + longestPath(root->right);
        }else{
            if(!root->right || root->right->val != root->val)lmap[root] = 1 + longestPath(root->left);
            else lmap[root] = 1 + max(longestPath(root->left), longestPath(root->right));
        }
        return lmap[root];
    }

    void bfs(TreeNode* root){
        if(root == nullptr)return;
        if(!lmap[root])
            longestPath(root);
        bfs(root->left);
        bfs(root->right);
        return;
    }

    void bfs2(TreeNode* root){
        if(root == nullptr)return;
        if(root->left && root->right && root->val == root->left->val && root->val == root->right->val)
            ans = max(ans, 1+lmap[root->left]+lmap[root->right]);
        else
            ans = max(ans, lmap[root]);
        bfs2(root->left);
        bfs2(root->right);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        bfs(root);
        bfs2(root);
        return ans-1;
    }
};