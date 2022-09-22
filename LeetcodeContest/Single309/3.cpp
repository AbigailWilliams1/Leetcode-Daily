#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ans(n);
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left>0 && !(nums[left-1]&nums[i]))
                left--;
            while(right<n-1 && !(nums[right+1]&nums[i]))
                right++;
            ans[i] = make_pair(left, right);
        }

        int res = 1, l = 0, r = n-1;
        for(int i = 0; i < n; i++){
            int maxlength = 0;
            int end = ans[i].second;
            for(int j = i; j <= end; j++){
                end = min(end, ans[j].second);
                if(ans[j].first > i)break;
                else maxlength ++;
            }
            res = max(res, maxlength);
        }
        return res;
    }
};