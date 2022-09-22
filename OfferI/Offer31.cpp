/*
剑指 Offer 31. 栈的压入、弹出序列               难度：中等
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，
序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

链接：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

执行用时：16 ms, 在所有 C++ 提交中击败了5.86% 的用户
内存消耗：15.8 MB, 在所有 C++ 提交中击败了5.11% 的用户
通过测试用例：151 / 151
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> mm;
public:
    bool validateStackSequences(vector<int>& pushed, int pushl, int pushr, vector<int>& popped, int popl, int popr){
        if(popl>popr)return true;
        if(popl == popr)return (pushed[pushl] == popped[popl])? true: false;
        int pos = mm[pushed[pushl]];
        if(pos < popl || pos > popr)return false;
        return validateStackSequences(pushed, pushl+1, pos+pushl-popl, popped, popl, pos-1) && 
            validateStackSequences(pushed, pos+1+pushr-popr, pushr, popped, pos+1, popr);
    }

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        for(int i = 0; i < n; i++)
            mm[popped[i]] = i;
        return validateStackSequences(pushed, 0, n-1, popped, 0, n-1);
    }
};