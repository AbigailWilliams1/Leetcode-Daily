/*
2867. 统计树中的合法路径数目                难度：困难
给你一棵 n 个节点的无向树，节点编号为 1 到 n 。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示节点 ui 和 vi 在树中有一条边。
请你返回树中的 合法路径数目 。
如果在节点 a 到节点 b 之间 恰好有一个 节点的编号是质数，那么我们称路径 (a, b) 是 合法的 。
注意：
路径 (a, b) 指的是一条从节点 a 开始到节点 b 结束的一个节点序列，序列中的节点 互不相同 ，且相邻节点之间在树上有一条边。
路径 (a, b) 和路径 (b, a) 视为 同一条 路径，且只计入答案 一次 。

链接：https://leetcode.cn/problems/count-valid-paths-in-a-tree/description/
*/
#include "temp.h"

class Solution {
    unordered_map<int, unordered_set<int>> v;
public:
    void dfs(int root, const vector<int>& isPrime, unordered_set<int>& subTree){
        if(isPrime[root])return;
        subTree.insert(root);
        for(auto adj : v[root]){
            if(!isPrime[adj] && subTree.count(adj) == 0){
                dfs(adj, isPrime, subTree);
            }
        }
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<int> isPrime(n+1, 1);
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                for(int j = 2; i * j <= n; j++)
                    isPrime[i * j] = 0;
            }
        }

        for(auto edge : edges){
            v[edge[0]].insert(edge[1]);
            v[edge[1]].insert(edge[0]);
        }

        vector<int> adjs(n+1, 0);
        for(int i = 1; i <= n; i++){
            if(isPrime[i] || adjs[i] > 0)continue;
            unordered_set<int> subTree;
            dfs(i, isPrime, subTree);
            for(auto i : subTree)
                adjs[i] = subTree.size();
        }

        long long ans = 0;
        for(int i = 0; i <= n; i++){
            if(!isPrime[i])continue;
            long long sum = 0, squareSum = 0;
            for(auto adj : v[i]){
                sum += adjs[adj];
                squareSum += (long long)adjs[adj] * adjs[adj];
            }
            ans += (sum * sum - squareSum) / 2 + sum;
        }
        return ans;
    }
};