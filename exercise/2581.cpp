/*
2581. 统计可能的树根数目                难度：困难
Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中 edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。
Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：
选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
Bob 猜测树中 u 是 v 的 父节点 。
Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。
Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。
给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。

链接：https://leetcode.cn/problems/count-number-of-possible-root-nodes/description/
*/
#include "temp.h"

class Solution {
public:
    using Graph = vector<unordered_set<int>>;
    void DFS_Init(int cur, int prev, const Graph& G, Graph& son){
        for(int adj : G[cur]){
            if(adj != prev){
                son[cur].insert(adj);
                DFS_Init(adj, cur, G, son);
            }
        }
    }

    void DFS_Check(int cur, int prev, int k, int& correct, int& ans, Graph& G, set<pair<int, int>>& Guess){
        if(correct >= k)ans ++;
        for(int adj : G[cur]){
            if(adj != prev){
                int change = Guess.count({adj, cur}) - Guess.count({cur, adj});
                correct += change;
                DFS_Check(adj, cur, k, correct, ans, G, Guess);
                correct -= change;
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1, m = guesses.size();
        Graph G(n), Son(n);
        set<pair<int, int>> Guess;
        for(auto& edge: edges){
            G[edge[0]].insert(edge[1]);
            G[edge[1]].insert(edge[0]);
        }
        DFS_Init(0, n, G, Son);

        int correct = 0, ans = 0;
        for(auto &guess: guesses){
            Guess.emplace(guess[0], guess[1]);
            correct += Son[guess[0]].count(guess[1]);
        }
        DFS_Check(0, n, k, correct, ans, G, Guess);
        return ans;
    }
};