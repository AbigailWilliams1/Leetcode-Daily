/*
2641. 二叉树的堂兄弟节点 II             难度：中等
给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。
如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。
请你返回修改值之后，树的根 root 。
注意，一个节点的深度指的是从树根节点到这个节点经过的边数。

链接：https://leetcode.cn/problems/cousins-in-binary-tree-ii/description/
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
    int depth = 1;
    vector<int> sumOfLevel;
public:
    void BFS_1(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(), sum = 0;
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front();
                sum += top->val;
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            sumOfLevel.push_back(sum);
        }
        sumOfLevel.push_back(0);
    }

    void BFS_2(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(), sum;
            for (int i = 0; i < size; i++){
                TreeNode* top = q.front();
                sum = sumOfLevel[depth];
                q.pop();
                if(top->left)sum -= top->left->val;
                if(top->right)sum -= top->right->val;
                if(top->left){
                    q.push(top->left);
                    top->left->val = sum;
                }
                if(top->right){
                    q.push(top->right);
                    top->right->val = sum;
                }
            }
            depth ++;
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        BFS_1(root);
        BFS_2(root);
        return root;
    }
};
