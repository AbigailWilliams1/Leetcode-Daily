#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> choose(int n, int k){
        vector<vector<int>> ans;
        if(k == 1){
            for(int i = 0; i < n; i++){
                vector<int> tmp(n, 0);
                tmp[i] = 1;
                ans.push_back(tmp);
            }
            return ans;
        }else if(n == k-1){
            for(int i = 0; i < n; i++){
                vector<int> tmp(n, 1);
                tmp[i] = 0;
                ans.push_back(tmp);
            }
            return ans;
        }else{
            vector<vector<int>> t = choose(n-1, k-1);
            vector<vector<int>> u = choose(n-1, k);
            for(auto &i : t){
                i.push_back(1);
            }
            for(auto &j : u){
                j.push_back(0);
            }
            t.insert(t.end(), u.begin(), u.end());
            return t;
        }

    }

    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        if(cols == n)return m;
        vector<vector<int>> tmp = choose(n, cols);
        int ans = 0;
        for(auto &i : tmp){
            int sum = 0;
            for(int j = 0; j < m; j++){
                bool flag = true;
                for(int k = 0; k < n; k++){
                    if(mat[j][k] == 1 && i[k] == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag)sum++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};