/*
1608. 特殊数组的特征值              难度：简单
给你一个非负整数数组 nums。如果存在一个数 x ，使得 nums 中恰好有 x 个元素大于或者等于x ，
那么就称 nums 是一个 特殊数组 ，而 x 是该数组的 特征值 。注意： x 不必 是 nums 的中的元素。
如果数组 nums 是一个 特殊数组 ，请返回它的特征值 x 。否则，返回 -1 。可以证明的是，如果 nums 是特殊数组，那么其特征值 x 是 唯一的 。

链接：https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/submissions/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8 MB, 在所有 C++ 提交中击败了64.90% 的用户
通过测试用例：98 / 98
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 1, right = nums.size(), mid;
        while(right >= left){
            mid = (right + left)/2;
            int tmp = lower_bound(nums.begin(), nums.end(), mid) - nums.begin() + mid;
            if(nums.size() == tmp)return mid;
            else if(nums.size() > tmp)left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};