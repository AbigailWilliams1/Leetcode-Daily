/*
1455. 检查单词是否为句中其他单词的前缀              难度：简单
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。
请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。
如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。
如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。
字符串 s 的 前缀 是 s 的任何前导连续子字符串。

链接：https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了83.47% 的用户
通过测试用例：40 / 40
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int num = 0;
        istringstream str(sentence);
        while(str >> word){
            num ++;
            bool flag = true;
            if(word.length() < searchWord.length())continue;
            for(int i = 0; i < searchWord.length(); i++){
                if(searchWord[i] != word[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)return num;
        }
        return -1;
    }
};