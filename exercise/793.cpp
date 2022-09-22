/*
793. 阶乘函数后 K 个零              难度：困难
f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。
例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。

链接：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了5.37% 的用户
通过测试用例：44 / 44
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(unsigned int k) {
        unsigned int MIN = k*4+1, MAX = k*4+55;
        vector<unsigned int> rest;
        vector<unsigned int> powFive;
        int five = 1, mink = 0;
        for(int i = 0; i < 12; i++){
            five *= 5;
            mink += MIN/five;
            rest.push_back(MIN%five);
            powFive.push_back(five);
        }
        while(mink < k){
            int tmp = 5-rest[0];
            for(int i = 0; i < 12; i++){
                rest[i] += tmp;
                if(rest[i] == powFive[i]){
                    mink ++;
                    rest[i] = 0;
                }
            }
        }
        if(mink == k)return 5;
        else return 0;
    }
};
