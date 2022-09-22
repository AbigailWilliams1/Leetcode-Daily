/*
剑指 Offer 33. 二叉搜索树的后序遍历序列             难度：中等
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
假设输入的数组的任意两个数字都互不相同。

链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了9.51% 的用户
通过测试用例：23 / 23
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mm;

    bool verifyPostorder(vector<int>& inorder, int inl, int inr, vector<int>& postorder, int postl, int postr){
        if(inr < inl)return true;
        if(inr == inl){
            if(inorder[inl] == postorder[postl])return true;
            else return false;
        }
        int pos = mm[postorder[postr]];
        return verifyPostorder(inorder, inl, pos-1, postorder, postl, postl+pos-inl-1) &&
            verifyPostorder(inorder, pos+1, inr, postorder, postr+pos-inr, postr-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        for(int i = 0; i < inorder.size(); i++)
            mm[inorder[i]] = i;
        return verifyPostorder(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};