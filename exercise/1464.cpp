/*
1464. 数组中两元素的最大乘积                难度：简单
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。
请你计算并返回该式的最大值。

链接：https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/

执行用时：8 ms, 在所有 C++ 提交中击败了32.13% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了97.88% 的用户
通过测试用例：104 / 104
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= max1){
                max2 = max1;
                max1 = nums[i];
            }else if(nums[i] > max2)
                max2 = nums[i];
            else
                continue;
        }
        return (max1-1)*(max2-1);
    }
};