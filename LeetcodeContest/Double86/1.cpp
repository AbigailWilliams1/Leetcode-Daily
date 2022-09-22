#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)return 0;
        unordered_map<int, int> mm;
        for(int i = 0; i < n-1; i++){
            int tmp = nums[i]+nums[i+1];
            if(!mm[tmp])mm[tmp]++;
            else return true;
        }
        return false;
    }
};