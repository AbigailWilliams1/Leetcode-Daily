/*
223. 矩形面积               难度：中等
给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
每个矩形由其 左下 顶点和 右上 顶点坐标表示：
    第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
    第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。

链接：https://leetcode.cn/problems/rectangle-area/

执行用时：8 ms, 在所有 C++ 提交中击败了53.17% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了5.06% 的用户
通过测试用例：3080 / 3080
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = (ax2 - ax1)*(ay2 - ay1), b = (bx2 - bx1)*(by2 - by1);
        if(ax1 >= bx2 || ax2 <= bx1 || ay1 >= by2 || ay2 <= by1)return a+b;
        vector<int> x{ax1, ax2, bx1, bx2};
        vector<int> y{ay1, ay2, by1, by2};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int shared = (x[2] - x[1]) * (y[2] - y[1]);
        return a+b-shared;
    }
};