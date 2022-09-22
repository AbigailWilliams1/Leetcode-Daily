/*
剑指 Offer 54. 二叉搜索树的第k大节点        难度：简单
给定一棵二叉搜索树，请找出其中第 k 大的节点的值.
限制：1 ≤ k ≤ 二叉搜索树元素个数

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof

执行用时：16 ms, 在所有 C++ 提交中击败了68.66% 的用户
内存消耗：23.5 MB, 在所有 C++ 提交中击败了49.77% 的用户
通过测试用例：91 / 91
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
public:
    struct StNode{
        TreeNode* node;
        int times;
        StNode(TreeNode* n = nullptr):times(0), node(n){}
    };

    int kthLargest(TreeNode* root, int k) {
        TreeNode* r = root;
        stack<StNode> s;
        s.emplace(r);
        while(!s.empty()){
            StNode tmp = s.top();
            s.pop();
            if(tmp.times == 0){
                tmp.times ++;
                if(tmp.node->left)s.emplace(tmp.node->left);
                s.emplace(tmp);
                if(tmp.node->right)s.emplace(tmp.node->right);
            }else{
                k--;
                if(!k)return tmp.node->val;
            }
        }
        return -1;
    }
};