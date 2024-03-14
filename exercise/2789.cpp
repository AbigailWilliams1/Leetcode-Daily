/*
2789. 合并后数组中的最大元素                难度：中等
给你一个下标从 0 开始、由正整数组成的数组 nums 。
你可以在数组上执行下述操作 任意 次：
    选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。
    将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
返回你可以从最终数组中获得的 最大 元素的值。

链接：https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/description/
*/
#include <vector>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size(), r = n-1;
        long long ans = 0, sum;
        while(r >= 0){
            int l = r - 1;
            sum = nums[r];
            while(l >= 0 && nums[l] <= sum)sum += nums[l--];
            ans = max(ans, sum);
            r = l;
        }
        return ans;
    }
};