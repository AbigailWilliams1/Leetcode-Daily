/*
剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

链接：https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/

执行用时：32 ms, 在所有 C++ 提交中击败了37.85% 的用户
内存消耗：19.3 MB, 在所有 C++ 提交中击败了13.98% 的用户
通过测试用例：39 / 39
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        for(int j = k; j < arr.size(); j++){
            pq.push(arr[j]);
            pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};