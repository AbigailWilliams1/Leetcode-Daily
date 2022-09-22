/*
剑指 Offer 66. 构建乘积数组             难度：中等
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

链接：https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/

执行用时：16 ms, 在所有 C++ 提交中击败了86.62% 的用户
内存消耗：24.3 MB, 在所有 C++ 提交中击败了39.40% 的用户
通过测试用例：44 / 44
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        //vector<int> head(n);
        vector<int> tail(n);
        vector<int> ans(n);
        int multiply = 1;
        /*
        for(int i = 0; i < n ; i++){
            multiply *= a[i];
            head[i] = multiply;
        }
        multiply = 1;
        */
        for(int i = n-1; i >= 0 ; i--){
            tail[i] = multiply;
            multiply *= a[i];
        }
        multiply = 1;
        for(int i = 0; i < n; i++){
            ans[i] = tail[i] * multiply;
            multiply *= a[i]; 
        }
        return ans;
    }
};