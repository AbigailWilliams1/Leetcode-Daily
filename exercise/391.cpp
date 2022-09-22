/*
391. 完美矩形               难度：困难
给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形、
这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。

链接：https://leetcode.cn/problems/perfect-rectangle/

执行用时：100 ms, 在所有 C++ 提交中击败了91.93% 的用户
内存消耗：30.5 MB, 在所有 C++ 提交中击败了91.93% 的用户
通过测试用例：49 / 49
*/
#include "temp.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<tuple<int, int, int>> vtiii;
        for(int i = 0; i < n; i++){
            vtiii.push_back(make_tuple(rectangles[i][1], i, 1));
            vtiii.push_back(make_tuple(rectangles[i][3], i, 0));
        }
        sort(vtiii.begin(), vtiii.end());
        n >>= 1;
        int i = 0;
        while(i < n){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> enter;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> out;
            int j = i+1, index;
            while(j < n && get<0>(vtiii[j]) == get<0>(vtiii[i]))j++;
            for(int k = i; k < j; k++){
                index = get<1>(vtiii[k]);
                if(get<2>(vtiii[k]))enter.emplace(rectangles[index][0],rectangles[index][2]);
                else out.emplace(rectangles[index][0], rectangles[index][2]);
            }
            int right, r;
            if(!i){
                right = enter.top().first;
                while(!enter.empty()){
                    if(enter.top().first != right)return false;
                    right = enter.top().second;
                    enter.pop();
                }
            }else if(i == n-1){
                r = out.top().first;
                while(!out.empty()){
                    if(out.top().first != r)return false;
                    r = out.top().second;
                    out.pop();
                }
            }else{
                if(enter.empty())return false;
                while(!enter.empty()){
                    if(out.empty())return false;
                    right = enter.top().first;
                    r = out.top().first;
                    if(right != r)return false;
                    while(!enter.empty() && enter.top().first == right){
                        right = enter.top().second;
                        enter.pop();
                    }
                    while (!out.empty() && out.top().first == r){
                        r = out.top().second;
                        out.pop();
                    }
                    if(r != right)return false;
                }
                if(!out.empty())return false;
            }
            i = j;
        }
        return true;
    }
};