/*
1460. 通过翻转子数组使两个数组相等              难度：简单
给你两个长度相同的整数数组 target 和 arr 。每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。你可以执行此过程任意次。
如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

链接：https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/

执行用时：12 ms, 在所有 C++ 提交中击败了56.89% 的用户
内存消耗：15.1 MB, 在所有 C++ 提交中击败了16.17% 的用户
通过测试用例：106 / 106
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mymap;
        for(auto &i : target){
            mymap[i]++;
        }
        for(auto &j: arr){
            if(mymap[j]>0)mymap[j]--;
            else return false;
        }
        return true;
    }
};