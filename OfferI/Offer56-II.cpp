/*
剑指 Offer 56 - II. 数组中数字出现的次数 II             难度：中等
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/

执行用时：36 ms, 在所有 C++ 提交中击败了49.19% 的用户
内存消耗：15.7 MB, 在所有 C++ 提交中击败了58.87% 的用户
通过测试用例：32 / 32
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        bitset<32> n;
        int sum = 0;
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < nums.size(); j++){
                sum += (nums[j] & 1);
                nums[j] >>= 1;
            }
            n[i] = sum % 3;
            sum = 0;
        }
        return (int)n.to_ulong();
    }
};