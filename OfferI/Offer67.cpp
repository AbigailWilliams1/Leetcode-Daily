/*
剑指 Offer 67. 把字符串转换成整数
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。
说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

链接：https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了76.13% 的用户
通过测试用例：1079 / 1079
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int left = 0;
        while(left < str.size() && str[left] == ' ')left++;
        if(left >= str.size())return 0;

        bool positive = true;
        if(str[left] == '+')left++;
        else if(str[left] == '-'){
            positive = false;
            left++;
        }
        if(!isdigit(str[left]))return 0;

        int right = left+1;
        while(right < str.size() && isdigit(str[right]))right ++;
        right --;

        long ans = 0;
        while(right >= left){
            ans *= 10;
            ans += (long)str[left] - '0';
            left ++;
            if(positive && ans >= (long)INT_MAX)return INT_MAX;
            else if(!positive && ans > (long)INT_MAX)return INT_MIN;
        }
        if(positive)return (int)ans;
        else return (int)ans*(-1);
    }
};