/*
646. 最长数对链             难度：中等
给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。

链接：https://leetcode.cn/problems/maximum-length-of-pair-chain/

执行用时：56 ms, 在所有 C++ 提交中击败了82.13% 的用户
内存消耗：21.9 MB, 在所有 C++ 提交中击败了73.06% 的用户
通过测试用例：205 / 205
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int num = 1, start = 1, end = 0;
        while(start<pairs.size()){
            if(pairs[start][0] > pairs[end][1]){
                num ++;
                end = start;
            }
            start ++;
        }
        return num;
    }
};