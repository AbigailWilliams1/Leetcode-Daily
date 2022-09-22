/*
剑指 Offer 29. 顺时针打印矩阵               难度：简单
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

链接：https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

执行用时：8 ms, 在所有 C++ 提交中击败了84.64% 的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了5.02% 的用户
通过测试用例：27 / 27
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    void spiralOrder(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2){
        if(x1 > x2 || y1 > y2)return;
        for(int i = y1; i <= y2; i++)
            ans.push_back(matrix[x1][i]);
        for(int i = x1+1; i <= x2; i++)
            ans.push_back(matrix[i][y2]);
        if(x2 > x1)for(int i = y2-1; i >= y1; i--)
            ans.push_back(matrix[x2][i]);
        if(y2 > y1)for(int i = x2-1; i > x1; i--)
            ans.push_back(matrix[i][y1]);
        spiralOrder(matrix, x1+1, y1+1, x2-1, y2-1);
        return;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)return {};
        if(n == 1)return matrix[0];
        int m = matrix[0].size();
        if(m == 0)return {};
        if(m == 1){
            for(auto &i : matrix)
                ans.push_back(i[0]);
            return ans;
        }
        spiralOrder(matrix, 0, 0, n-1, m-1);
        return ans;
    }
};