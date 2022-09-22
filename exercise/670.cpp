/*
670. 最大交换               难度：中等
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

链接：https://leetcode.cn/problems/maximum-swap/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了33.82% 的用户
通过测试用例：111 / 111
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if(num<10)return num;
        int a[9] = {0};
        int n = num, i = -1;
        while(n){
            a[++i] = n % 10;
            n /= 10;
        }

        int pos = i;
        while(pos && a[pos] >= a[pos-1])
            pos--;
        if(pos == 0)return num;

        int maxindex = --pos;
        for(--pos;pos>=0;pos--){
            if(a[pos] >= a[maxindex])
                maxindex = pos;
        }

        pos = i;
        while(true){
            if(a[i] >= a[maxindex])i--;
            else {
                swap(a[i], a[maxindex]);
                break;
            }
        }

        for(;pos >= 0; pos--){
            n *= 10;
            n += a[pos];
        }
        return n;

    }
};