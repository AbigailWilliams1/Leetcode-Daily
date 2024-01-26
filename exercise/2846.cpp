/*
2846. 边权重均等查询                难度：困难
现有一棵由 n 个节点组成的无向树，节点按从 0 到 n - 1 编号。
给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi, wi] 表示树中存在一条位于节点 ui 和节点 vi 之间、权重为 wi 的边。
另给你一个长度为 m 的二维整数数组 queries ，其中 queries[i] = [ai, bi] 。
对于每条查询，请你找出使从 ai 到 bi 路径上每条边的权重相等所需的 最小操作次数 。在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。
注意：
查询之间 相互独立 的，这意味着每条新的查询时，树都会回到 初始状态 。
从 ai 到 bi的路径是一个由 不同 节点组成的序列，从节点 ai 开始，到节点 bi 结束，且序列中相邻的两个节点在树中共享一条边。
返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 条查询的答案。

链接：https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/

执行用时：654 ms, 在所有 C++ 提交中击败了53.89% 的用户
内存消耗：227.47 MB, 在所有 C++ 提交中击败了83.77% 的用户
通过测试用例：733 / 733
*/

#include "temp.h"

class Solution {
private:
    int n, idx = -1;
    int visit_bfs[10000] = {0}, visit_dfs[10000] = {0};
    int parent[10000], weights[10000][26] = {0}, deep[10000] = {0};
    int dfn[20000], first[10000], last[10000], f[20000][16];
    unordered_map<int, unordered_map<int, int>> eds;
public:
    vector<int> minOperationsQueries(int _n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = _n;
        int num_of_visit = 1;
        for(auto& edge : edges){
            eds[edge[0]][edge[1]] = edge[2];
            eds[edge[1]][edge[0]] = edge[2];
        }
        BFS(0);
        DFS(0);
        INIT();
        int size = queries.size();
        vector<int> ans(size, 0);
        for(int i = 0; i < size; i++){
            int a = queries[i][0], b = queries[i][1];
            if(a == b)continue;
            if(first[a] > first[b])swap(a, b);
            int tmp[26] = {0}, sum = 0;
            if(last[a] > last[b]){
                for(int j = 0; j < 26; j++){
                    tmp[j] = weights[b][j] - weights[a][j];
                    sum += tmp[j];
                }
                ans[i] = sum - *max_element(tmp, tmp+26);
            }else{
                int l = last[a], r = first[b], d = log2(r - l + 1);
                int p1 = f[l][d], p2 = f[r-(1<<d)+1][d];
                int lcp = deep[p1] < deep[p2] ? p1 : p2;
                for(int j = 0; j < 26; j++){
                    tmp[j] = weights[b][j] + weights[a][j] - 2 * weights[lcp][j];
                    sum += tmp[j];
                }
                ans[i] = sum - *max_element(tmp, tmp+26);
            }
        }
        return ans;
    }

    void BFS(int root){
        int layer = 0;
        queue<int> q;
        q.push(root);
        deep[root] = layer ++;
        while(!q.empty()){
            int len = q.size();
            for(int j = 0; j < len; j++){
                int t = q.front();
                q.pop();
                visit_bfs[t] = 1;
                for(auto& p : eds[t]){
                    int v = p.first, w = p.second;
                    if(visit_bfs[v])continue;
                    parent[v] = t;
                    for(int i = 0; i < 26; i++)
                        weights[v][i] = weights[t][i];
                    weights[v][w - 1] ++;
                    q.push(v);
                    deep[v] = layer;
                }
            }
            layer ++;
        }
    }

    void DFS(int k){
        dfn[++idx] = k;
        first[k] = idx;
        visit_dfs[k] = 1;
        for(auto& p : eds[k]){
            int v = p.first;
            if(visit_dfs[v])continue;
            DFS(v);
            dfn[++idx] = k;
        }
        last[k] = idx;
    }

    void INIT(){
        int m = idx + 1;
        for(int i = 0; i < m; i++)
            f[i][0] = dfn[i];
        for(int j = 1; (1 << j) <= m; j++){
            for(int i = 0; i+(1<<j) <= m; i++){
                int p1 = f[i][j-1], p2 = f[i+(1<<(j-1))][j-1];
                f[i][j] = deep[p1] < deep[p2] ? p1 : p2;
            }
        }
    }
};