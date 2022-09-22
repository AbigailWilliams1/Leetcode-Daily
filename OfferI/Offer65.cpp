/*
剑指 Offer 65. 不用加减乘除做加法               难度：简单
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

链接：https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了88.65% 的用户
通过测试用例：51 / 51
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while(b!=0){
            int tmp = a^b;
            b = (unsigned)(a&b)<<1;
            a = tmp;
        }
        return a;
    }
};