/*
剑指 Offer 34. 二叉树中和为某一值的路径             难度：中等
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
树中节点总数在范围 [0, 5000] 内
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000

链接：https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/

执行用时：16 ms, 在所有 C++ 提交中击败了15.85% 的用户
内存消耗：26.2 MB, 在所有 C++ 提交中击败了16.25% 的用户
通过测试用例：114 / 114
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
    vector<vector<int>> rpathSum(TreeNode* root, int target) {
        if(root == nullptr)return {{}};
        if(!root->left && !root->right){
            if(root->val == target)return {{target}};
            else return {{}};
        }
        vector<vector<int>> ans = rpathSum(root->left, target-root->val);
        vector<vector<int>> r = rpathSum(root->right, target-root->val);
        ans.insert(ans.end(), r.begin(), r.end());
        for(auto &i : ans)
            if(i.size()!=0)i.push_back(root->val);
        return ans;
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<vector<int>> tmp = rpathSum(root, target);
        for(auto &i: tmp){
            reverse(i.begin(), i.end());
            if(i.size() != 0)res.push_back(i);
        }
        return res;

        /*
        vector<vector<int>> res;
        vector<int> path;
        int sumOfPath = 0;
        stack<TreeNode*> mystack;
        TreeNode* r = root;
        mystack.push(r);
        TreeNode* parentOfTop;
        //path.push_back(r->val);
        //sumOfPath += r->val;

        while(!mystack.empty()){
            TreeNode* tmp = mystack.top();
            mystack.pop();
            path.push_back(tmp->val);
            sumOfPath += tmp->val;
            if(tmp->right)mystack.push(tmp->right);
            if(tmp->left)mystack.push(tmp->left);
            if(!tmp->right && !tmp->left && sumOfPath == target){
                res.push_back(path);

            }
        }
        */
    }
};