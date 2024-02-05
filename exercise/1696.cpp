/*
1696. 跳跃游戏 VI               难度：中等
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1, i + k)] 包含 两个端点的任意位置。
你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。
请你返回你能得到的 最大得分 。

链接：https://leetcode.cn/problems/jump-game-vi/
*/
#include "temp.h"

class Solution {
    deque<int> deq;
    vector<int> dp;
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n);
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i --){
            if(deq.front() > i + k) deq.pop_front();
            while(!deq.empty() && dp[deq.back()] <= dp[i + 1])
                deq.pop_back();
            deq.push_back(i + 1);
            dp[i] = nums[i] + dp[deq.front()];
        }
        return dp[0];
    }
};
