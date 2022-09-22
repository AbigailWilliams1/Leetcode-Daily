#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, length = 0, index = -1;
        while(right < nums.size()){
            while (right < nums.size() && nums[right] == nums[left])right++;
            if(nums[left] % 2 == 0 && right-left>length){
                length = right-left;
                index = nums[left];
            }
            left = right;
        }
        return (length>=0)?index:-1;
    }
};