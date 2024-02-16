/*
429. N 叉树的层序遍历               难度：中等
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

链接：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
*/
#include "temp.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* top = q.front();
                level.push_back(top->val);
                q.pop();
                for(Node* node : top->children)
                    if(node)q.push(node);
            }
            ans.push_back(level);
        }
        return ans;
    }
};