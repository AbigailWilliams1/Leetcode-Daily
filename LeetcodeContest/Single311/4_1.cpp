#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

class Solution {
private:
    const unsigned long long MOD = 4294967291;
    umii a;

    void rolling_hash(string str)
    {
            unsigned long long hash = 0;
            size_t str_len = str.size();
            for(int i = 0, k = str_len -1; i < str_len; i++, k--) {
                    hash = hash * 257 + str[i];
                    hash = hash % MOD;
                    a[hash] ++;
            }
            return;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        for(auto & w : words)
            rolling_hash(w);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            unsigned long long hash = 0;
            size_t str_len = words[i].size();
            for(int j = 0, k = str_len -1; j < str_len; j++, k--) {
                    hash = hash * 257 + words[i][j];
                    hash = hash % MOD;
                    ans[i] += a[hash];
            }
        }
        return ans;
    }
};