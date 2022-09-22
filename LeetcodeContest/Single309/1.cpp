#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> mm;
        for(int i = 0; i < s.size(); i++){
            mm[s[i]] = i-mm[s[i]];
        }
        for(auto &i : mm){
            int tmp = i.first-'a';
            if(distance[tmp] != i.second-1)
                return false;
        }
        return true;
    }
};