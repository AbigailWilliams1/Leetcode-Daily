/*
850. 矩形面积 II                难度：困难
我们给出了一个（轴对齐的）二维矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2, y2]，
其中（x1，y1）是矩形 i 左下角的坐标， (xi1, yi1) 是该矩形 左下角 的坐标， (xi2, yi2) 是该矩形 右上角 的坐标。
计算平面中所有 rectangles 所覆盖的 总面积 。任何被两个或多个矩形覆盖的区域应只计算 一次 。
返回 总面积 。因为答案可能太大，返回 109 + 7 的 模 。

链接：https://leetcode.cn/problems/rectangle-area-ii/submissions/

执行用时：4 ms, 在所有 C++ 提交中击败了97.85% 的用户
内存消耗：8.3 MB, 在所有 C++ 提交中击败了87.12% 的用户
通过测试用例：78 / 78
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int MOD = pow(10, 9) + 7;
public:
    int calculateLength(multiset<pair<int, int>>& mspii){
        if(mspii.empty())return 0;
        int length = 0;
        auto it = mspii.begin();
        int right = it->second;
        length += right - it->first;
        it ++;

        for(;it != mspii.end(); it++){
            if(it->second <= right)continue;
            if(it->first >= right)length += (it->second - it->first);
            else length += (it->second - right);
            right = it->second;
        }

        return length;
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        if(n == 1)return (long long)(rectangles[0][2] - rectangles[0][0]) * (rectangles[0][3] - rectangles[0][1])%MOD;

        set<int> viy;
        multiset<pair<int, int>> intervals;

        /*
        sort(rectangles.begin(), rectangles.end(), [](vector<int>&a, vector<int>&b){
            return a[3] > b[3];
        });
        */

        for(int i = 0; i < n; i++){
            if(rectangles[i][1] < rectangles[i][3]){
                viy.insert(rectangles[i][1]);
                viy.insert(rectangles[i][3]);
            }
        }

        long long ans = 0;
        int prev = 0;
        for(auto it = viy.begin(); it != viy.end(); it++){
            int line = *it;

            //calculate the total length of all intervals:
            int length = calculateLength(intervals);

            ans += (long long)(line - prev) * length;
            for(int i = 0; i < n; i++){
                if(rectangles[i][1] == line)intervals.emplace(rectangles[i][0], rectangles[i][2]);
                if(rectangles[i][3] == line)intervals.erase(intervals.find({rectangles[i][0], rectangles[i][2]}));
            }

            prev = line;
        }

        return ans % MOD;
    }
};