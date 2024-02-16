/*
103. 二叉树的锯齿形层序遍历             难度：中等
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

链接：https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* top = q.front();
                level.push_back(top->val);
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            ans.push_back(level);
        }
        int index = 0;
        for_each(ans.begin(), ans.end(), [&index](vector<int>& v){
            if(index++ & 1)reverse(v.begin(), v.end());
        });
        return ans;
    }
};