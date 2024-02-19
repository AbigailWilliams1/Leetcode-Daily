#include "temp.h"

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int add = nums[0] +nums[1], ans = 1;
        for(int i = 2; i+1 < nums.size(); i+=2){
            if(nums[i]+nums[i+1]!=add)break;
            ans++;
        }
        return ans;
    }
};