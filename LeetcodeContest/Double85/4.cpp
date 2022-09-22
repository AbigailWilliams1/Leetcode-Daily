#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int LIMIT = 100000;

    int pos(int left, int right){
        return LIMIT*left + right;
    }
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        long long maxm = 0;
        int left = 0, right = n-1;

        vector<long long> ans(n);
        unordered_map<int, long long> m;
        //list<int> index;

        for(int i = 0; i < n; i++)
            maxm += nums[i];
        //index.push_back(left-1);
        //index.push_back(right+1);
        m[pos(left, right)] = maxm;
        //ans[0] = maxm;
        for(int i = 0; i < n; i++){
            int tmp = removeQueries[i];
            maxm = 0;
            for(auto [k,v]: m){
                int l = k/LIMIT, r = k%LIMIT, mid;
                if(l<=tmp && r>=tmp){
                    mid = (l+r)/2;
                    long long sum = 0;
                    if(tmp == l)
                        m[pos(tmp+1, right)] = v-nums[tmp];
                    else if(tmp<=mid){
                        for(int j = l; j < tmp; j++){
                            sum += nums[j];
                        }
                        m[pos(l,tmp-1)] = sum;
                        m[pos(tmp+1, r)] = v-sum;
                    }else if(tmp == r)
                        m[pos(l, tmp-1)] = v-nums[tmp];
                    else{
                        for(int j = tmp+1;j <= r; j++){
                            sum += nums[j];
                        }
                        m[pos(tmp+1,r)] = sum;
                        m[pos(l,tmp-1)] = v-sum;
                    }
                    m.erase(k);
                    break;
                }
            }
            for(auto i = m.begin(); i < m.end(); i++){
                maxm = max(maxm, i->second);
            }
            ans[i] = maxm; 
        }
        return ans;
    }
};