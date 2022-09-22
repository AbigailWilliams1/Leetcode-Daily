/*
1470. 重新排列数组              难度：简单
给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。
请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。

链接：https://leetcode.cn/problems/shuffle-the-array/

执行用时：4 ms, 在所有 C++ 提交中击败了86.42% 的用户
内存消耗：9.4 MB, 在所有 C++ 提交中击败了72.66% 的用户
通过测试用例：53 / 53
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int MOD = 1024;
        for(int i = 1; i < (n<<1)-1; i++){
            if(i & 1)nums[i] += ((nums[(i>>1) + n] % MOD) << 10);
            else nums[i] += ((nums[i>>1] % MOD) << 10);
        }
        for(int i = 1; i < (n<<1)-1; i++){
            nums[i] >>= 10;
        }
        return nums;
    }
};