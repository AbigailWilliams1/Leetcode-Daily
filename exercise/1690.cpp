/*
1690. 石子游戏 VII              难度：中等
石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。
有 n 块石子排成一排。每个玩家的回合中，可以从行中 移除 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 和 相等的得分。当没有石头可移除时，得分较高者获胜。
鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 减小得分的差值 。爱丽丝的目标是最大限度地 扩大得分的差值 。
给你一个整数数组 stones ，其中 stones[i] 表示 从左边开始 的第 i 个石头的值，如果爱丽丝和鲍勃都 发挥出最佳水平 ，请返回他们 得分的差值 。

链接：https://leetcode.cn/problems/stone-game-vii/description/
*/
#include "temp.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n - 1; i++)
            dp[i][i+1] = max(stones[i], stones[i+1]);
        for(int i = 2; i < n; i++){
            for(int j = 0; j < n - i; j++){
                int ans_l = min(stones[j+1] + dp[j+2][j+i], stones[j+i] + dp[j+1][j+i-1]);
                int ans_r = min(stones[j] + dp[j+1][j+i-1], stones[j+i-1] + dp[j][j+i-2]);
                dp[j][j+i] = max(ans_l, ans_r);
            }
        }
        return dp[0][n-1];
    }
};