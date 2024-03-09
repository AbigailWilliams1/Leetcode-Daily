#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int mod;
public:
    void dfs(int cur, int prev, int len, int& res, vector<unordered_map<int, int>>& G){
        if((len%mod) == 0)res++;
        for(auto& [adj, weight] : G[cur]){
            if(adj != prev){
                dfs(adj, cur, len+weight, res, G);
            }
        }
    }
    int Solve(int root, vector<unordered_map<int, int>>& G){
        vector<int> son;
        for(auto& [adj, weight] : G[root]){
            int res = 0;
            dfs(adj, root, weight, res, G);
            if(res)son.push_back(res);
        }
        int sol = 0, size = son.size(), sum = 0;
        for(int i = 0; i < size; i++){
            sol += son[i] * sum;
            sum += son[i];
        }
        return sol;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        mod = signalSpeed;
        vector<int> ans(n);
        vector<unordered_map<int, int>> G(n);
        for(auto& edge : edges) {
            G[edge[0]][edge[1]] = edge[2];
            G[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++)
            ans[i] = Solve(i, G);
        return ans;
    }
};