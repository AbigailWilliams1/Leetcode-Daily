/*
1582. 二进制矩阵中的特殊位置                难度：简单
给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat 中特殊位置的数目 。
特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ），则位置 (i, j) 被称为特殊位置。

链接：https://leetcode.cn/problems/special-positions-in-a-binary-matrix/

执行用时：24 ms, 在所有 C++ 提交中击败了20.95% 的用户
内存消耗：12.4 MB, 在所有 C++ 提交中击败了94.07% 的用户
通过测试用例：95 / 95
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pos(vector<int>& s){
        int ans = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 1 && ans == -1)ans = i;
            else if(s[i] == 1 && ans != -1){
                ans = -1;
                break;
            }
        }
        return ans;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size(); i++){
            int tmp = pos(mat[i]);
            if(tmp == -1)continue;
            else{
                int numOfOne = 0;
                for(int j = 0; j < mat.size(); j++){
                    if(mat[j][tmp] == 1)numOfOne ++;
                    if(numOfOne > 1)break;
                }
                if(numOfOne == 1)sum ++;
            }
        }
        return sum;
    }
};