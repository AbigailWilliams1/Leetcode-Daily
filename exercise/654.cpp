/*
654. 最大二叉树         难度：中等
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
    创建一个根节点，其值为 nums 中的最大值。
    递归地在最大值 左边 的 子数组前缀上 构建左子树。
    递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

链接：https://leetcode.cn/problems/maximum-binary-tree/

执行用时：68 ms, 在所有 C++ 提交中击败了91.44% 的用户
内存消耗：38.4 MB, 在所有 C++ 提交中击败了98.86% 的用户
通过测试用例：107 / 107
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int k) {
        if(k == 0){
            TreeNode* tmp = new TreeNode(nums[0]);
            return tmp;
        }
        TreeNode* tt = constructMaximumBinaryTree(nums, k-1);
        TreeNode* r = new TreeNode(nums[k]), *t = tt;
        if(nums[k] > t->val){
            r->left = t;
            return r;
        }
        while(t->right){
            if(nums[k] < t->right->val)t = t->right;
            else{
                r->left = t->right;
                t->right = r;
                return tt;
            }
        }
        t->right = r;
        return tt;
    }


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, nums.size()-1);
    }
};