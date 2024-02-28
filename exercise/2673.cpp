/*
2673. 使二叉树所有路径值相等的最小代价              难度：中等
给你一个整数 n 表示一棵 满二叉树 里面节点的数目，节点编号从 1 到 n 。根节点编号为 1 ，树中每个非叶子节点 i 都有两个孩子，分别是左孩子 2 * i 和右孩子 2 * i + 1 。
树中每个节点都有一个值，用下标从 0 开始、长度为 n 的整数数组 cost 表示，其中 cost[i] 是第 i + 1 个节点的值。每次操作，你可以将树中 任意 节点的值 增加 1 。你可以执行操作 任意 次。
你的目标是让根到每一个 叶子结点 的路径值相等。请你返回 最少 需要执行增加操作多少次。
注意：
满二叉树 指的是一棵树，它满足树中除了叶子节点外每个节点都恰好有 2 个子节点，且所有叶子节点距离根节点距离相同。
路径值 指的是路径上所有节点的值之和。

链接：https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/description/
*/
#include "temp.h"

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int costs[n + 1], sumCosts[n + 1], adds[n + 1];
        costs[0] = sumCosts[0] = adds[0] = 0;
        for(int i = 1; i <= n; i++){
            costs[i] = cost[i-1];
            sumCosts[i] = costs[i] + sumCosts[i >> 1];
        }
        int left = n + 1 >> 1, right = n;
        int maxCost = *max_element(sumCosts+left, sumCosts+right+1);
        for(int i = left; i <= right; i++)
            adds[i] = maxCost - sumCosts[i];
        while(left < right){
            for(int i = left; i < right; i += 2){
                int minCost = min(adds[i], adds[i+1]);
                adds[i] -= minCost;
                adds[i+1] -= minCost;
                adds[i>>1] = minCost;
            }
            left >>= 1;
            right >>= 1;
        }
        return accumulate(adds, adds + n + 1, 0);
    }
};