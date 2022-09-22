/*
剑指 Offer 56 - I. 数组中数字出现的次数             难度：中等
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/

执行用时：12 ms, 在所有 C++ 提交中击败了90.02% 的用户
内存消耗：15.8 MB, 在所有 C++ 提交中击败了22.46% 的用户
通过测试用例：35 / 35
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int axorb = 0;
        for(auto &i :nums)
            axorb ^= i;

        int num = 0;
        //cout<<"axorb = "<<axorb<<endl;
        while((axorb & 1) == 0){
            num ++;
            axorb >>= 1;
        }
        //cout<<"num = "<<num<<endl;
        int a = 0, b = 0;
        for(auto &i : nums){
            //cout<<"a = "<<a<<", b = "<<b<<endl;
            //cout<<"i = "<<i<<", i>>num&1 = "<<(i>>num & 1)<<endl;
            if(i>>num & 1)a ^= i;
            else b ^= i;
        }
        //cout<<"a = "<<a<<", b = "<<b<<endl;
        vector<int> ans={a,b};
        return ans;
    }
};