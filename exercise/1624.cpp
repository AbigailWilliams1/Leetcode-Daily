/*
1624. 两个相同字符之间的最长子字符串                难度：简单
给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。
子字符串 是字符串中的一个连续字符序列。

链接：https://leetcode.cn/problems/largest-substring-between-two-equal-characters/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了92.05% 的用户
通过测试用例：54 / 54
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int size = s.size()-2, left = 0, right = size+1;
        for(;size>=0;size--){
            for(left=0, right=left+size+1;right<s.size();left++, right++){
                if(s[left] == s[right])return size;
            }
        }
        return -1;
    }
};