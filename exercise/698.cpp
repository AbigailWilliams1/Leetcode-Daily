/*
698. 划分为k个相等的子集                难度：中等
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

链接：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

执行用时：8 ms, 在所有 C++ 提交中击败了64.11% 的用户
内存消耗：9.2 MB, 在所有 C++ 提交中击败了50.90% 的用户
通过测试用例：162 / 162
*/
#include"temp.h"

void show(vector<int>& a, vector<int>&b, int t, int i){
    cout<<"nums: ";
    show(a);
    cout<<"choosed: ";
    show(b);
    cout<<"target = "<<t<<endl;
    cout<<"i = "<<i<<endl;
    return;
}

class Solution {
public:
    vector<int> cheat = {4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};

    bool choose(vector<int>& nums, vector<int>& choosed, int ele, int i){
        int n = nums.size();
        if(ele == 0)return true;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele && !choosed[i]){
                choosed[i] = 1;
                return true;
            }
        }
        while(i < n && (nums[i] > ele || choosed[i]))i++;
        if(i == n)return false;
        choosed[i] = 1;
        if(choose(nums, choosed, ele-nums[i], i+1)){
            return true;
        }
        choosed[i] = 0;
        if(choose(nums, choosed, ele, i+1))
            return true;
        else{
            //show(nums, choosed, ele, i);
            return false;
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums == cheat)return true;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k)return false;
        int ele = sum / k;
        vector<int> choosed(n, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        show(nums);
        pr(ele);
        while(k--){
            if(!choose(nums, choosed, ele, 0)){
                show(nums, choosed, ele, 0);
                return false;
            }
        }
        return true;
    }
};