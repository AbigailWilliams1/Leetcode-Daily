/*
剑指 Offer 14- I. 剪绳子                难度：中等
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

链接：https://leetcode.cn/problems/jian-sheng-zi-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了19.67% 的用户
通过测试用例：50 / 50
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n, int m){
        if(m == 0)return -1;
        if(n % m == 0)return pow(n/m, m);
        int unit = n/m, len = n % m;
        return pow(unit+1, len)*pow(unit, m-len);
    }

    int cuttingRope(int n) {
        if(n < 4)return n-1;
        int k = n/2.71828;
        return max(max(cuttingRope(n, k), cuttingRope(n, k-1)), cuttingRope(n, k+1));
    }
};