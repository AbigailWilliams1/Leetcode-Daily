/*
1598. 文件夹操作日志搜集器              难度：简单
每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。
下面给出对变更操作的说明：
    "../" ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 继续停留在当前文件夹 。
    "./" ：继续停留在当前文件夹。
    "x/" ：移动到名为 x 的子文件夹中。题目数据 保证总是存在文件夹 x 。
给你一个字符串列表 logs ，其中 logs[i] 是用户在 ith 步执行的操作。
文件系统启动时位于主文件夹，然后执行 logs 中的操作。
执行完所有变更文件夹操作后，请你找出 返回主文件夹所需的最小步数 。

链接：https://leetcode.cn/problems/crawler-log-folder/

执行用时：4 ms, 在所有 C++ 提交中击败了89.21% 的用户
内存消耗：10.5 MB, 在所有 C++ 提交中击败了8.99% 的用户
通过测试用例：99 / 99
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(auto &i : logs){
            if(i == "./" || (i == "../" && s.empty()))continue;
            else if(i == "../")s.pop();
            else s.push(i);
        }
        return s.size();
    }
};