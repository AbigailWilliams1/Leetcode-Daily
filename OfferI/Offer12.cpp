/*
剑指 Offer 12. 矩阵中的路径            难度：中等
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof

执行用时：336 ms, 在所有 C++ 提交中击败了25.78% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了86.64% 的用户
通过测试用例：83 / 83
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool existGrid(vector<vector<char>>& board, vector<vector<int>> &used, string word, int x, int y, int k){
        int l = word.length();
        if(board[x][y] != word[k])return false;
        if(k == l-1)return true;
        used[x][y] = 1;
        if(x > 0 && !used[x-1][y] && existGrid(board, used, word, x-1, y, k+1))return true;
        if(x < board.size()-1 && !used[x+1][y] && existGrid(board, used, word, x+1, y, k+1))return true;
        if(y > 0 && !used[x][y-1] && existGrid(board, used, word, x, y-1, k+1))return true;
        if(y < board[0].size()-1 && !used[x][y+1] && existGrid(board, used, word, x, y+1, k+1))return true;
        used[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(existGrid(board, used, word, i, j, 0))return true;
            }
        }
        return false;
    }
};