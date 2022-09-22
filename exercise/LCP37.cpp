/*
LCP 37. 最小矩形面积                难度：困难
二维平面上有 NNN 条直线，形式为 y = kx + b，其中 k、b为整数 且 k > 0。
所有直线以 [k,b] 的形式存于二维数组 lines 中，不存在重合的两条直线。
两两直线之间可能存在一个交点，最多会有 CN2C_N^2CN2​ 个交点。
我们用一个平行于坐标轴的矩形覆盖所有的交点，请问这个矩形最小面积是多少。
若直线之间无交点、仅有一个交点或所有交点均在同一条平行坐标轴的直线上，则返回0。
注意：返回结果是浮点数，与标准答案 绝对误差或相对误差 在 10^-4 以内的结果都被视为正确结果

链接：https://leetcode.cn/problems/zui-xiao-ju-xing-mian-ji/

执行用时：304 ms, 在所有 C++ 提交中击败了35.29% 的用户
内存消耗：68.4 MB, 在所有 C++ 提交中击败了29.41% 的用户
通过测试用例：49 / 49
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<double, double> minmaxx(vector<vector<int>>& lines, int ileft, int iright, int jleft, int jright){
        vector<double> minmax(4);
        minmax[0] = static_cast<double>(lines[jright][1]-lines[iright][1])/(lines[jright][0]-lines[iright][0]);
        minmax[1] = static_cast<double>(lines[jright][1]-lines[ileft][1])/(lines[jright][0]-lines[ileft][0]);
        minmax[2] = static_cast<double>(lines[jleft][1]-lines[iright][1])/(lines[jleft][0]-lines[iright][0]);
        minmax[3] = static_cast<double>(lines[jleft][1]-lines[ileft][1])/(lines[jleft][0]-lines[ileft][0]);
        return make_pair(*min_element(minmax.begin(), minmax.end()), *max_element(minmax.begin(), minmax.end()));
    }

    pair<double, double> minmaxy(vector<vector<int>>& lines, int ileft, int iright, int jleft, int jright){
        vector<double> minmax(4);
        minmax[0] = static_cast<double>(lines[iright][0]*lines[jright][1]-lines[jright][0]*lines[iright][1])/(lines[jright][0]-lines[iright][0]);
        minmax[1] = static_cast<double>(lines[iright][0]*lines[jleft][1]-lines[jleft][0]*lines[iright][1])/(lines[jleft][0]-lines[iright][0]);
        minmax[2] = static_cast<double>(lines[ileft][0]*lines[jright][1]-lines[jright][0]*lines[ileft][1])/(lines[jright][0]-lines[ileft][0]);
        minmax[3] = static_cast<double>(lines[ileft][0]*lines[jleft][1]-lines[jleft][0]*lines[ileft][1])/(lines[jleft][0]-lines[ileft][0]);
        return make_pair(*min_element(minmax.begin(), minmax.end()), *max_element(minmax.begin(), minmax.end()));
    }

    double minRecSize(vector<vector<int>>& lines) {
        sort(lines.begin(), lines.end(), [](vector<int>&a, vector<int>&b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
        });
        int n = lines.size();
        if(n == 1)return 0;
        double minx = 2e4, maxx = -2e4, miny = 2e4, maxy = -2e4;

        int ileft = 0, iright = 0, jleft = 1, jright = 1;
        while(jright < n){
            while(iright+1<n && lines[iright+1][0] == lines[ileft][0])iright++;
            if(iright+1 == n)break;
            jleft = iright+1;
            jright = jleft;
            while(jright+1<n && lines[jright+1][0] == lines[jleft][0])jright++;

            auto tmpx = minmaxx(lines, ileft, iright, jleft, jright);
            minx = min(minx, tmpx.first);
            maxx = max(maxx, tmpx.second);

            auto tmpy = minmaxy(lines, ileft, iright, jleft, jright);
            miny = min(miny, tmpy.first);
            maxy = max(maxy, tmpy.second);

            ileft = jleft;
            iright = jright;
        }
        if(minx == 2e4 || miny == 2e4)return 0;
        return (maxx-minx)*(maxy-miny);
    }
};