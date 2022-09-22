/*
剑指 Offer 16. 数值的整数次方               难度：中等
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

链接：https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了24.98% 的用户
通过测试用例：304 / 304
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myEasyPow(double x, int n){
        double ans = 1;
        while(n){
            if(n & 1)ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        if(x == 1 || n == 0)
            return 1;
        else if(x == 0)
            return 0;
        else if(x == -1)
            return (n&1)?-1:1;
        else if(n>0){
            return myEasyPow(x,n);
        }else if(n < 0 && n != INT_MIN){
            return 1/myEasyPow(x,-n);
        }else{
            if(abs(x)>1)return 0;
            else return myEasyPow(1/x, -1-n)/x;
        }
    }
};