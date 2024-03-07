/*
2575. 找出字符串的可整除数组                难度：中等
给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。
word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：
如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。

链接：https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/description/
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int len = word.length();
        long long cur = 0;
        vector<int> div(len);
        for(int i = 0; i < len; i++){
            cur *= 10;
            cur += word[i] - '0';
            while(cur >= m)cur -= m;
            div[i] = cur == 0 ? 1 : 0;
        }
        return div;
    }
};