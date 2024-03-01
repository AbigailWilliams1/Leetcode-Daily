/*
2369. 检查数组是否存在有效划分              难度：中等
给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。
如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：
子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

链接：https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/description/
*/
#include "temp.h"

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        auto checkTriplet = [](int a, int b, int c)->bool{
            return ((a==b)&&(b==c))||((b-a==1)&&(c-b==1));
        };
        dp[0] = false; dp[1] = nums[1] == nums[0];
        if(n > 2)dp[2] = checkTriplet(nums[0], nums[1], nums[2]);
        for(int i = 3; i < n; i++){
            dp[i] = (dp[i-3] && checkTriplet(nums[i-2], nums[i-1], nums[i]))
                    || (dp[i-2] && (nums[i-1] == nums[i]));
        }
        return dp[n-1];
    }
};