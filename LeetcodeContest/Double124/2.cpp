#include "temp.h"
class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length(), op = 0;
        // vector<int> v(n, 0);
        vector<int> index[26];
        int p[26] = {0};
        for(int i =0; i < n; i++){
            index[s[i]-'a'].push_back(i);
        }
        set<int> opset;
        while(op < n){
            opset.clear();
            for(int i = 0; i < 26; i++){
                if(p[i] < index[i].size()){
                    int tmp = index[i][p[i]++];
                    op++;
                    opset.insert(tmp);
                }
            }
        }
        string ans;
        for(auto i : opset)
            ans.push_back(s[i]);
        return ans;
    }
};