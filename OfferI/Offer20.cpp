/*
剑指 Offer 20. 表示数值的字符串             难度：中等
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
数值（按顺序）可以分成以下几个部分：
    若干空格
    一个 小数 或者 整数
    （可选）一个 'e' 或 'E' ，后面跟着一个 整数
    若干空格
小数（按顺序）可以分成以下几个部分：
    （可选）一个符号字符（'+' 或 '-'）
    下述格式之一：
        至少一位数字，后面跟着一个点 '.'
        至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
        一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：
    （可选）一个符号字符（'+' 或 '-'）
    至少一位数字
部分数值列举如下：
    ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：
    ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

链接：https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了47.80% 的用户
通过测试用例：1480 / 1480
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInteger(string s){
        int n = s.size();
        if(n == 0)return false;
        if(n == 1){
            if(isdigit(s[0]))return true;
            else return false;
        }
        int i = 0;
        if(s[0] == '+' || s[0] == '-')i++;
        for(;i < n; i++){
            if(!isdigit(s[i]))return false;
        }
        return true;
    }

    bool isDecimal(string s){
        int n = s.size();
        if(n < 2)return false;
        if(n == 2 && !isdigit(s[0]) && s[0] != '.')return false;
        int i = 0, point = 0;
        if(s[0] == '+' || s[0] == '-')i++;
        for(;i < n; i++){
            if(s[i] == '.'){
                if(!point)point++;
                else return false;
            }else if(!isdigit(s[i]))
                return false;
        }
        if(point)return true;
        else return false;
    }

    bool isNumber(string s) {
        int left = 0, mid = 0, right = s.size()-1;
        while(left < s.size() && s[left] == ' '){left++;}
        while(right >= 0 && s[right] == ' '){right--;}
        if(left>right || left>= s.size() || right<0)return false;
        for(mid = left; mid<= right; mid++){
            if(s[mid] == 'e' || s[mid] == 'E')break;
        }
        if(mid > right)return isInteger(s.substr(left, right-left+1)) || isDecimal(s.substr(left, right-left+1));
        else return isInteger(s.substr(mid+1, right-mid)) && (isInteger(s.substr(left, mid-left)) || isDecimal(s.substr(left, mid-left))); 
    }
};