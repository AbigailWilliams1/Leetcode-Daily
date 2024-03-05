/*
1976. 到达目的地的方案数                难度：中等
你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。
给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。
你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。
请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 109 + 7 取余 后返回。

链接：https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/description/
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

class Solution {
    const long long MOD = 1e9+7;
    int visit[200]={0}, idx[200];
    int weights[200][200];
    long long minLength[200], dp[200];

    void Dijkstra(int n){
        minLength[0] = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;
            long long cur_length = __LONG_LONG_MAX__;
            for(int i = 0; i < n; i++){
                if(minLength[i] == -1 || visit[i])continue;
                if(minLength[i] < cur_length){
                    cur = i;
                    cur_length = minLength[i];
                }
            }
            for(int i = 0; i < n; i++){
                if(weights[cur][i] == -1 || visit[i])continue;
                if(minLength[i] == -1 || minLength[cur] + weights[cur][i] < minLength[i]){
                    minLength[i] = minLength[cur] + weights[cur][i];
                }
                
            }
            visit[cur] = 1;
        }
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        memset(weights, -1, sizeof(weights));
        memset(minLength, -1, sizeof(minLength));
        for(vector<int>& road : roads){
            weights[road[0]][road[1]] = road[2];
            weights[road[1]][road[0]] = road[2];
        }
        Dijkstra(n);

        iota(idx, idx+n, 0);
        sort(idx, idx+n, [this](int a, int b){
            return minLength[a] < minLength[b];
        });
        dp[idx[0]] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(minLength[idx[i]] == minLength[idx[j]] + weights[idx[i]][idx[j]]){
                    dp[idx[i]] += dp[idx[j]];
                }
            }
            dp[idx[i]] %= MOD;
        }

        return dp[n-1];
    }
};