/*
84. 柱状图中最大的矩形              难度：困难
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

链接：https://leetcode.cn/problems/largest-rectangle-in-histogram/

执行用时：160 ms, 在所有 C++ 提交中击败了22.47% 的用户
内存消耗：79.5 MB, 在所有 C++ 提交中击败了22.31% 的用户
通过测试用例：98 / 98
*/
#include"temp.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> less, greater;
        vector<int> left(n), right(n);
        for(int i = 0; i < n; i++){
            while(!greater.empty() && heights[greater.top()] >= heights[i])greater.pop();
            left[i] = greater.empty()?-1:greater.top();
            greater.push(i);
        }
        for(int i = n-1; i >= 0; i--){
            while(!less.empty() && heights[less.top()] >= heights[i])less.pop();
            right[i] = less.empty()?n:less.top();
            less.push(i);
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};