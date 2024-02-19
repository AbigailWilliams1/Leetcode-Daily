/*
590. N 叉树的后序遍历               难度：简单
给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。
n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

链接：https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/
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
    vector<int> ans;
public:
    vector<int> postorder(Node* root) {
        function<void(Node*)> dfs = [&](Node* r){
            if(!r)return;
            for_each(root->children.begin(), root->children.end(), dfs);
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};