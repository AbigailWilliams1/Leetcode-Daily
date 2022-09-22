#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<long long, int> budg(vector<pair<int, int>>& s, int k, int end){
        pair<long long, int> ans;
        if(k==1){
            ans.first = s[0].first + s[0].second;
            ans.second = 0;
            for(int i = 0; i <= end; i++){
                long long tmp = s[i].first + s[i].second;
                if(tmp < ans.first){
                    ans.first = tmp;
                    ans.second = i;
                }
            }
            return ans;
        }
        else if(k == end){
            ans.first = 0;
            for(int i = 0; i < end; i++){
                ans.first += s[i].first;
                if(s[i].second > s[ans.second].second)ans.second = i;
            }
            ans.first = ans.first * k + s[ans.second].second;
            return ans;
        }
        pair<long long, int> tmp1 = budg(s, k-1, end-1), tmp2 = budg(s, k, end-1);
        //long long cost1 = (s[end].second + tmp1);

    }

    bool isReady(vector<pair<int, int>>& s, long long budget, int k){
        //if(budg(s, k, s.size()-1)<=budget)return true;
        //else return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left = 0, right = chargeTimes.size(), mid;
        int m = *max_element(chargeTimes.begin(), chargeTimes.end());
        vector<pair<int, int>> s;
        for(int i = 0; i < right; i++){
            s.push_back(make_pair(runningCosts[i], chargeTimes[i]));
        }
        sort(s.begin(), s.end());

        while(left < right){
            mid = (left+right+1)/2;
            if(isReady(s, budget, mid))left = mid;
            else right = mid-1;
        }
        return left;
    }
};