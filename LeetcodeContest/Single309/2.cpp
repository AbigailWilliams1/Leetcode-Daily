#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Mod = 1000000007;
public:
    int numberOfWays(int d, int k){
        d = abs(d);
        if(d == k)return 1;
        if(d > k)return 0;
        vector<vector<int>> ans((k<<1)+1, vector<int>(k+1, 0));
        ans[k][0] = 1;
        for(int i = 1; i <= k; i++){
            for(int j = 0; j <= (k<<1); j++){
                if(j == 0)ans[j][i] = ans[j+1][i-1];
                else if(j == (k<<1))ans[j][i] = ans[j-1][i-1];
                else ans[j][i] = (ans[j-1][i-1] + ans[j+1][i-1])%Mod;
            }
        }
        return ans[k+d][k];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        return numberOfWays(abs(startPos - endPos), k);
    }
};