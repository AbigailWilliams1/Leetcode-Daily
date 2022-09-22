/*
剑指 Offer 39. 数组中出现次数超过一半的数字             难度：简单
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。

链接：https://leetcode.cn/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/

执行用时：20 ms, 在所有 C++ 提交中击败了31.48% 的用户
内存消耗：18.3 MB, 在所有 C++ 提交中击败了27.43% 的用户
通过测试用例：45 / 45
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};