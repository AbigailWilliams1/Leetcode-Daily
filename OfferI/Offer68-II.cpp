/*
剑指 Offer 68 - II. 二叉树的最近公共祖先                难度：简单
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/

执行用时：16 ms, 在所有 C++ 提交中击败了67.34% 的用户
内存消耗：16.6 MB, 在所有 C++ 提交中击败了14.13% 的用户
通过测试用例：31 / 31
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
private:
    vector<TreeNode*> path;
    bool flag = false;
public:
    void dfs(TreeNode* root, TreeNode* t){
        if(root == nullptr)return;
        path.push_back(root);
        if(root == t){
            flag = true;
            return;
        }
        dfs(root->left, t);
        dfs(root->right,t);
        if(!flag)path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p);
        int posp = 0, posq = path.size();
        flag = false;
        dfs(root, q);
        TreeNode* res;
        while(path[posp] == path[posq]){
            res = path[posq];
            posp++;
            posq++;
        }
        return res;
    }
};