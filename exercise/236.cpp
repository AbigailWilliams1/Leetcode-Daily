/*
236. 二叉树的最近公共祖先               难度：中等
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
    “对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/
#include "temp.h"


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int i = -1;
    unordered_map<TreeNode*, int> depth, first, last;
    TreeNode* sequence[200005] = {0};
public:
    void dfs(TreeNode* root, int d){
        depth[root] = d;
        sequence[++i] = root;
        first[root] = i;
        if(root->left){
            dfs(root->left, d+1);
            sequence[++i] = root;
        }
        if(root->right){
            dfs(root->right, d+1);
            sequence[++i] = root;
        }
        last[root] = i;
    }

    TreeNode* findLCA(TreeNode* a, TreeNode* b){
        if(first[a] > first[b])swap(a, b);
        if(last[a] > last[b])return a;
        return *min_element(sequence + last[a] + 1, sequence + first[b], 
            [&](TreeNode* j, TreeNode* k){return depth[j] < depth[k];});
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0);
        return findLCA(p, q);
    }
};