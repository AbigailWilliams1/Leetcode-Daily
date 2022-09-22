/*
1640. 能否连接形成数组              难度：简单
给你一个整数数组 arr ，数组中的每个整数 互不相同 。另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同 。
请你以 任意顺序 连接 pieces 中的数组以形成 arr 。但是，不允许 对每个数组 pieces[i] 中的整数重新排序。
如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false 。

链接：https://leetcode.cn/problems/check-array-formation-through-concatenation/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了62.28% 的用户
通过测试用例：84 / 84
*/
#include "temp.h"

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int a[101] = {0};
        for(int i = 0; i < arr.size(); i++)
            a[arr[i]] = i+1;
        sort(pieces.begin(), pieces.end(), [&](vector<int>& s, vector<int>& t){
            return a[s[0]] < a[t[0]];
        });
        int i = 0, k = 0;
        while(i < pieces.size()){
            for(int j = 0; j < pieces[i].size(); j++){
                if(pieces[i][j] != arr[k])return false;
                k++;
            }
            i++;
        }
        return true;
    }
};