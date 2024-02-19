/*
589. N 叉树的前序遍历               难度：简单
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。
n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

链接：https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description
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
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root)return ans;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* node = s.top();
            s.pop();
            ans.push_back(node->val);
            for_each(node->children.rbegin(), node->children.rend(), 
                bind((void(stack<Node*>::*)(Node* const&))&stack<Node*>::push, &s, placeholders::_1));
        }
        return ans;
    }
};