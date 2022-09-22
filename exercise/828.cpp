/*
828. 统计子串中的唯一字符               难度：困难
我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。
例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。
本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。输入用例保证返回值为 32 位整数。
注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。

链接：https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

执行用时：52 ms, 在所有 C++ 提交中击败了40.38% 的用户
内存消耗：24.4 MB, 在所有 C++ 提交中击败了17.89% 的用户
通过测试用例：76 / 76
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
// private:
//     vector<int> pow2;
public:
    // Solution(){
    //     int tmp = 1;
    //     for(int i = 0; i < 31; i++){
    //         pow2.push_back(tmp);
    //         tmp <<= 1;
    //     }
    // }

    int uniqueLetterString(string s) {
        int n = s.size(), sum = 0;
        vector<vector<int>> index(26,{-1});
        for(int i = 0; i < n; i++){
            int t = s[i] - 'A', k = index[t].size();
            if(k > 1)sum += (i - index[t][k-1]) * (index[t][k-1] - index[t][k-2]);
            index[t].push_back(i);
        }
        for(int i = 0; i < 26; i++){
            int k = index[i].size();
            if(k > 1)
                sum += (n - index[i][k-1]) * (index[i][k-1] - index[i][k-2]);
        }
        return sum;
        
        /*
        int n = s.size(), sum = 0;
        vector<char> alphabet(26);
        for(int i = 0; i < 26; i++){
            alphabet[i] = 'A' + i;
        }
        for(int i = 0; i < n; i++){
            unordered_set<char> zero(alphabet.begin(), alphabet.end());
            unordered_set<char> one;
            for(int j = i; j < n; j++){
                if(zero.find(s[j]) != zero.end()){
                    zero.erase(s[j]);
                    one.insert(s[j]);
                }else if(one.find(s[j]) != one.end()){
                    one.erase(s[j]);
                }
                sum += one.size();
            }
        }
        return sum;
        */
    }
};