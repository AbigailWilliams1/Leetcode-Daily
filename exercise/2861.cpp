/*
2861. 最大合金数                难度：中等
假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。
现在共有 n 种不同类型的金属可以使用，并且你可以使用 k 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。
对于第 i 台机器而言，创建合金需要 composition[i][j] 份 j 类型金属。
最初，你拥有 stock[i] 份 i 类型金属，而每购入一份 i 类型金属需要花费 cost[i] 的金钱。
给你整数 n、k、budget，下标从 1 开始的二维数组 composition，两个下标从 1 开始的数组 stock 和 cost，请你在预算不超过 budget 金钱的前提下，最大化 公司制造合金的数量。
所有合金都需要由同一台机器制造。
返回公司可以制造的最大合金数。

链接：https://leetcode.cn/problems/maximum-number-of-alloys/

执行用时：47 ms, 在所有 C++ 提交中击败了82.87% 的用户
内存消耗：57.7 MB, 在所有 C++ 提交中击败了11.11% 的用户
通过测试用例：
*/
#include "temp.h"

class Solution {
    const int _max = 200000001;
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for(int i = 0; i < k; i++){
            int l = 0, r = _max, mid;
            while(l < r){
                long sum = 0;
                mid = (r + l)/2;
                for(int j = 0; j < n; j++)
                    sum += (long)cost[j] * max(0l, (long)mid * composition[i][j] - stock[j]);
                // cout<<"i = "<<i<<", mid = " <<mid<< ", sum = "<<sum<<endl;
                if(budget >= sum)l = mid + 1;
                else r = mid;
            }
            ans = max(ans, r-1);
        }
        return ans;
    }
};