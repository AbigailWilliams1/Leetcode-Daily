/*
2476. 二叉搜索树最近节点查询                难度：中等
给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。
请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：
mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替。
返回数组 answer 。

链接：https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/
*/
#include <bits/stdc++.h>
using namespace std;

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
    vector<int> inorder;
public:
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> ans;
        for(int query: queries){
            auto it = lower_bound(inorder.begin(), inorder.end(), query);
            if(it == inorder.end()){
                ans.push_back({inorder.back(), -1});
                continue;
            }
            if(*it == query){
                ans.push_back({query, query});
                continue;
            }
            if(it == inorder.begin()){
                ans.push_back({-1, inorder.front()});
                continue;
            }
            ans.push_back({*(--it), *(++it)});
        }    
        return ans;
    }
};