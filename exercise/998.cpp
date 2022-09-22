/*
998. 最大二叉树 II              难度：中等
最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。
给你最大树的根节点 root 和一个整数 val 。
就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：
    如果 a 为空，返回 null 。
    否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
    root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
    root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
    返回 root 。
请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。
假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。
返回 Construct(b) 。

链接：https://leetcode.cn/problems/maximum-binary-tree-ii/

执行用时：4 ms, 在所有 C++ 提交中击败了76.26% 的用户
内存消耗：13 MB, 在所有 C++ 提交中击败了84.44% 的用户
通过测试用例：75 / 75
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
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int v) {
        vector<TreeNode*> rightNode;
        TreeNode* r = root;
        while(r){
            rightNode.push_back(r);
            r = r->right;
        }
        int n = rightNode.size() - 1;
        if(rightNode[n]->val > v){
            rightNode[n]->right = new TreeNode(v);
            return root;
        }
        while( n>=0 && rightNode[n]->val < v){
            n--;
        }
        if(n<0){
            TreeNode* t = new TreeNode(v);
            t->left = root;
            return t;
        }else{
            TreeNode* t = new TreeNode(v);
            t->left = rightNode[n+1];
            rightNode[n]->right = t;
            return root;
        }
        return nullptr;
    }
};