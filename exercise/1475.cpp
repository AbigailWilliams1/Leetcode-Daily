/*
1475. 商品折扣后的最终价格              难度：简单
给你一个数组 prices ，其中 prices[i] 是商店里第 i 件商品的价格。
商店里正在进行促销活动，如果你要买第 i 件商品，那么你可以得到与 prices[j] 相等的折扣，
其中 j 是满足 j > i 且 prices[j] <= prices[i] 的 最小下标 ，如果没有满足条件的 j ，你将没有任何折扣。
请你返回一个数组，数组中第 i 个元素是折扣后你购买商品 i 最终需要支付的价格。

链接：https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/

执行用时：4 ms, 在所有 C++ 提交中击败了81.96% 的用户
内存消耗：9.6 MB, 在所有 C++ 提交中击败了66.61% 的用户
通过测试用例：103 / 103
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i = 0; i < prices.size()-1; i++){
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};