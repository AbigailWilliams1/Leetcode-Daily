/*
2368. 受限条件下可到达节点的数目                难度：中等
现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。
给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。
在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。
注意，节点 0 不 会标记为受限节点。

链接：https://leetcode.cn/problems/reachable-nodes-with-restrictions/
*/
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int ans = 0;
        vector<vector<int>> G(n);
        unordered_set<int> vertices(restricted.begin(), restricted.end());
        for(auto edge : edges){
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        auto&& dfs = [&](auto &&self, int root, int prev)->void{
            ans ++;
            for(auto vertex : G[root]){
                if(vertex != prev && !vertices.count((vertex))){
                    self(self, vertex, root);
                }
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};