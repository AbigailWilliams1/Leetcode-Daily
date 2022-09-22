/*
剑指 Offer 17. 打印从1到最大的n位数             难度：简单
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

链接：https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

执行用时：4 ms, 在所有 C++ 提交中击败了94.33% 的用户
内存消耗：11.1 MB, 在所有 C++ 提交中击败了42.08% 的用户
通过测试用例：5 / 5
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        int k = pow(10, n);
        for(int i = 1; i < k; i++)
            ans.push_back(i);
        return ans;
    }
};