/*
剑指 Offer 45. 把数组排成最小的数               难度：中等
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

链接：https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/

执行用时：16 ms, 在所有 C++ 提交中击败了16.11% 的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了76.95% 的用户
通过测试用例：222 / 222
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const int& x1, const int& x2){
        if(x1 == 0)return true;
        if(x2 == 0)return false;
        string a = to_string(x1), b = to_string(x2);
        return a+b<b+a;
    }

/*
    void mapsort(vector<int>& nums){
        map<int, int, cmp> mymap;
        for(auto i:nums)mymap[i]++;
        int j = 0;
        for(auto [k,v]:mymap){
            while(v){
                nums[j++]=k;
                v--;
            }
        }
    }
*/
    string minNumber(vector<int>& nums) {
        string s = "";
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)s+="0";
            else tmp.push_back(nums[i]);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        //cout<<nums.size()<<endl;
        for(auto i : tmp)
            s+=to_string(i);
        return s;
    }
};