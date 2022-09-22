/*
1619. 删除某些元素后的数组均值              难度：简单
给你一个整数数组 arr ，请你删除最小 5% 的数字和最大 5% 的数字后，剩余数字的平均值。
与 标准答案 误差在 10-5 的结果都被视为正确结果。

链接：https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/

执行用时：4 ms, 在所有 C++ 提交中击败了94.02% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了5.65% 的用户
通过测试用例：50 / 50
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int sum = 0, n = arr.size(), m = n/20;
        for(int i = 0; i < m; i++){
            sum += arr[i];
        }
        priority_queue<int, vector<int>, less<int>> pql(arr.begin(), arr.begin()+m);
        priority_queue<int, vector<int>, greater<int>> pqg(arr.begin(), arr.begin()+m);
        for(int i = m; i < n; i++){
            sum += arr[i];
            if(arr[i] < pql.top()){
                pql.pop();
                pql.push(arr[i]);
            }
            if(arr[i] > pqg.top()){
                pqg.pop();
                pqg.push(arr[i]);
            }
        }
        while(!pql.empty()){
            sum -= pql.top();
            pql.pop();
        }
        while(!pqg.empty()){
            sum -= pqg.top();
            pqg.pop();
        }
        return (double) sum / (n - 2 * m);
    }
};