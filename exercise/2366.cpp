/*
2366. 将数组排序的最少替换次数              难度：困难
给你一个下表从 0 开始的整数数组 nums 。每次操作中，你可以将数组中任何一个元素替换为 任意两个 和为该元素的数字。
    比方说，nums = [5,6,7] 。一次操作中，我们可以将 nums[1] 替换成 2 和 4 ，将 nums 转变成 [5,2,4,7] 。
请你执行上述操作，将数组变成元素按 非递减 顺序排列的数组，并返回所需的最少操作次数。

链接：https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/

执行用时：100 ms, 在所有 C++ 提交中击败了39.95% 的用户
内存消耗：53.2 MB, 在所有 C++ 提交中击败了94.28% 的用户
通过测试用例：47 / 47
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int lower = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= lower){
                ans ++;
                lower = nums[i];
            }else if(nums[i] % lower){
                int tmp = nums[i]/lower + 1;
                ans += tmp;
                lower = nums[i]/tmp;
            }else{
                ans += nums[i]/lower;
            }
        }
        return ans - n;
    }
};