/*
1592. 重新排列单词间的空格              难度：简单
给你一个字符串 text ，该字符串由若干被空格包围的单词组成。
每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。
题目测试用例保证 text 至少包含一个单词 。
请你重新排列空格，使每对相邻单词之间的空格数目都相等 ，并尽可能 最大化 该数目。
如果不能重新平均分配所有空格，请多余的空格放置在字符串末尾 ，这也意味着返回的字符串应当与原text符串的长度相等。
返回 重新排列空格后的字符串 。

链接：https://leetcode.cn/problems/rearrange-spaces-between-words/submissions/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了20.72% 的用户
通过测试用例：89 / 89
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        istringstream iss(text);
        vector<string> a;
        string tmp;
        int n = text.size();
        while(iss >> tmp){
            n -= tmp.size();
            a.push_back(tmp);
        }

        string ans = "";
        if(a.size() == 1)return a[0] + string(n, ' ');
        else{
            int k = n/(a.size() - 1);
            for(int i = 0; i < a.size()-1; i++){
                ans += a[i];
                ans += string(k, ' ');
            }
            ans += a[a.size()-1];
            ans += string(n % (a.size() - 1), ' ');
        }
        return ans;
    }
};