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
    int longestContinuousSubstring(string s) {
        int left = 0, right = 0, n = s.size(), ans = 0;
        while(right < n){
            while(right+1 < n && s[right+1] == s[right] + 1)right++;
            ans = max(right-left+1, ans);
            left = right+1;
            right ++;
        }
        return ans;
    }
};