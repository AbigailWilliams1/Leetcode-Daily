/*
6187. 完成所有交易的初始最少钱数                难度：困难
给你一个下标从 0 开始的二维整数数组 transactions，其中transactions[i] = [costi, cashbacki] 。
数组描述了若干笔交易。其中每笔交易必须以 某种顺序 恰好完成一次。
在任意一个时刻，你有一定数目的钱 money ，为了完成交易 i ，money >= costi 这个条件必须为真。
执行交易后，你的钱数 money 变成 money - costi + cashbacki 。
请你返回 任意一种 交易顺序下，你都能完成所有交易的最少钱数 money 是多少。

链接：https://leetcode.cn/problems/minimum-money-required-before-transactions/

执行用时：268 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：108 MB, 在所有 C++ 提交中击败了100.00% 的用户
通过测试用例：55 / 55
*/
#include<temp.h>

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long ans = 0;
        int maxend = 0;
        for(auto &i : transactions){
            ans += max(0, i[0]-i[1]);
            maxend = max(maxend, min(i[1], i[0]));
        }
        return ans + maxend;
    }
};

