#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_set<char> us;
        int right = 0;
        while(right < s.size()){
            while(right < s.size() && us.find(s[right]) == us.end()){
                us.insert(s[right]);
                right ++;
            }
            if(right == s.size())break;
            ans++;
            us.clear();
        }
        return ans;
    }
};