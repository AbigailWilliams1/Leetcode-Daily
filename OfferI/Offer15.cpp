/*
剑指 Offer 15. 二进制中1的个数              难度：简单
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
提示：
    请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
    在 Java 中，编译器使用 二进制补码 记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。

链接：https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了23.54% 的用户
通过测试用例：601 / 601
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            if(n & 1)ans++;
            n >>= 1;
        }
        return ans;
    }
};