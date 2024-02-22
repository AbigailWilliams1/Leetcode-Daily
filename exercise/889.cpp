/*
889. 根据前序和后序遍历构造二叉树               难度：中等
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。
如果存在多个答案，您可以返回其中 任何 一个。

链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    int n, pre[32][32] = {0}, post[32][32] = {0};
public:
    TreeNode* dfsBuild(const vector<int>& preorder, const vector<int>& postorder,
                        int pre_l, int pre_r, int post_l, int post_r)
    {
        if(pre_l > pre_r)return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_l]);
        if(pre_l == pre_r)return root;
        int mid = 0;
        for(; mid < pre_r - pre_l; mid ++){
            if(pre[pre_l + 1][pre_l + 1 + mid] == post[post_l][post_l + mid])
                break;
        }
        root->left = dfsBuild(preorder, postorder, pre_l+1, pre_l+mid+1, post_l, post_l+mid);
        root->right = dfsBuild(preorder, postorder, pre_l+mid+2, pre_r, post_l+mid+1, post_r-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // preorder: [1,2,4,5,3,6,7], posorder: [4,5,2,6,7,3,1]
        n = preorder.size();
        auto init = [&](const vector<int>& order, int arr[32][32]){
            for(int i = 0; i < n; i++){
                int num = 0;
                for(int j = i; j < n; j++){
                    num |= 1 << order[j];
                    arr[i][j] = num;
                }
            }
        };
        init(preorder, pre);
        init(postorder, post);
        // for(int i = 0; i < n ; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<bitset<32>(pre[i][j])<<' ';
        //     }
        //     cout<<'\n';
        // }
        return dfsBuild(preorder, postorder, 0, n-1, 0, n-1);
    }
};

// int main()
// {
//     vi a = {1,2,4,5,3,6,7}, b = {4,5,2,6,7,3,1};
//     Solution A;
//     A.constructFromPrePost(a, b);
//     return 0;
// }