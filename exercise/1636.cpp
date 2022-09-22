/*
1636. 按照频率将数组升序排序                难度：简单
给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 
请你返回排序后的数组。

链接：https://leetcode.cn/problems/sort-array-by-increasing-frequency/

执行用时：8 ms, 在所有 C++ 提交中击败了76.17% 的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了45.80% 的用户
通过测试用例：180 / 180
*/
#include"temp.h"

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umii;
        for(auto i : nums)umii[i]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){return umii[a]<umii[b] || (umii[a]==umii[b] && a > b);});
        return nums;
    }
};