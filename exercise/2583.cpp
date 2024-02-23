/*
2583. 二叉树中的第 K 大层和             难度：中等
给你一棵二叉树的根节点 root 和一个正整数 k 。
树中的 层和 是指 同一层 上节点值的总和。
返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。
注意，如果两个节点与根节点的距离相同，则认为它们在同一层。

链接：https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/
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
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);
        while(!q.empty()){
            long long sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(pq.size() < k || pq.top() < sum)pq.push(sum);
            if(pq.size() > k)pq.pop();
        }
        return pq.size() == k ? pq.top() : -1;
    }
};