/*
剑指 Offer 57 - II. 和为s的连续正数序列             难度：简单
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/

执行用时：4 ms, 在所有 C++ 提交中击败了64.62% 的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了92.64% 的用户
通过测试用例：32 / 32
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildVector(int start, int d){
        vector<int> ans;
        for(int i = start; i < start + d; i++)
            ans.push_back(i);
        return ans;
    }
    vector<vector<int>> findContinuousSequence(int target) {
        target <<= 1;
        int d = sqrt(target);
        int tmp = target - d * (d-1);
        vector<vector<int>> res;
        for(; d>=2; d--){
            if(tmp > 0 && tmp % (d<<1) == 0)
                res.push_back(buildVector(tmp/(d<<1), d));
            tmp += ((d - 1)<<1);
        }
        return res;
    }
};