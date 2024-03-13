/*
2864. 最大二进制奇数                难度：简单
给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。
你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。
以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。
注意 返回的结果字符串 可以 含前导零。

链接：https://leetcode.cn/problems/maximum-odd-binary-number/description/
*/
#include <string>
#include <algorithm>
// #include <utility>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end(), greater<char>());
        auto it = find(s.rbegin(), s.rend(), '1');
        *it = '0'; 
        s.back() = '1';
        return s;
    }
};