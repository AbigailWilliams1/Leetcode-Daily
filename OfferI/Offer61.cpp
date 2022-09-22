/*
剑指 Offer 61. 扑克牌中的顺子               难度：简单
从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

链接：https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了58.10% 的用户
通过测试用例：203 / 203
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(nums[i] == 0){i++;}
        if(nums[4]-nums[i]>4)return false;
        for(; i < 4; i++)
            if(nums[i+1]==nums[i])return false;
        return true;
    }
};