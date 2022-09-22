/*
667. 优美的排列 II              难度：中等
给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：
    假设该列表是 answer = [a1, a2, a3, ... , an] ，
    那么列表 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。

链接：https://leetcode.cn/problems/beautiful-arrangement-ii/

执行用时：4 ms, 在所有 C++ 提交中击败了56.90% 的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了67.24% 的用户
通过测试用例：70 / 70
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        for(int i = 0; i < n-k; i++)
            ans[i] = i+1;
        int tmp = n;
        for(int i = n-k; i < n; i+=2){
            ans[i] = tmp;
            tmp --;
        }
        tmp = n-k+1;
        for(int i = n-k+1; i < n; i+=2){
            ans[i] = tmp;
            tmp ++;
        }
        return ans;
    }
};