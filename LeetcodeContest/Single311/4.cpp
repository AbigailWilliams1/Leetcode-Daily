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
public:
    unordered_map<string, int> umsi;
    vector<int> ans;

    void loop(string& s){
        string tmp = "";
        for(auto & i: s){
            tmp += i;
            umsi[tmp]++;
        }
        return;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        for(auto & w : words)
            loop(w);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            string tmp = "";
            for(auto &j : words[i]){
                tmp += j;
                ans[i] += umsi[tmp];
            }
        }
        return ans;
    }
};