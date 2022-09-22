/*
669. 修剪二叉搜索树             难度：中等
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

链接：https://leetcode.cn/problems/trim-a-binary-search-tree/

执行用时：16 ms, 在所有 C++ 提交中击败了53.06% 的用户
内存消耗：24 MB, 在所有 C++ 提交中击败了5.45% 的用户
通过测试用例：78 / 78
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
private:
    unordered_map<int, int> mm;
public:
    TreeNode* reback(vector<int>& preOrder, int prel, int prer, vector<int>& midOrder, int midl, int midr){
        if(prel > prer)return nullptr;
        if(prel == prer)return new TreeNode(preOrder[prel]);
        TreeNode* root = new TreeNode(preOrder[prel]);
        int pos = mm[root->val];
        root->left = reback(preOrder, prel+1, pos+prel-midl, midOrder, midl, pos-1);
        root->right = reback(preOrder, prer+pos+1-midr, prer, midOrder, pos+1, midr);
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int> preOrder;
        vector<int> midOrder;

        //midOrder traverse
        TreeNode* r = root;
        stack<TreeNode*> s;
        while(r || !s.empty()){
            for(;r;r=r->left){
                s.push(r);
            }
            r = s.top();
            if(r){
                int tmp = r->val;
                if(tmp>=low && tmp<=high)
                    midOrder.push_back(tmp);
                s.pop();
                r = r->right;
            }
        }

        //preOrder traverse
        r = root;
        s = stack<TreeNode*>();
        s.push(r);
        while(!s.empty()){
            TreeNode* t = s.top();
            int tmp = t->val;
            if(tmp>=low && tmp<=high)
                preOrder.push_back(tmp);
            s.pop();
            if(t->right)s.push(t->right);
            if(t->left)s.push(t->left);
        }

        int n = midOrder.size();
        for(int i = 0; i < n; i++){
            mm[midOrder[i]] = i;
        }

        return reback(preOrder, 0, n-1, midOrder, 0, n-1);
    }
};