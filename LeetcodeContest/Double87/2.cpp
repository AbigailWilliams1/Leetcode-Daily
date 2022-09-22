#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int, int> usii;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int p = players.size(), t = trainers.size();
        int ans = 0, pcur = 0, tcur = 0;
        while (pcur < p && tcur < t){
            while(tcur<t && trainers[tcur] < players[pcur])tcur++;
            if(tcur == t)break;
            pcur++;
            tcur++;
            ans++;
        }
        return ans;
    }
};