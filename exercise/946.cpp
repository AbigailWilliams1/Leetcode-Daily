/*
946. 验证栈序列             难度：中等
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复。
只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

链接：https://leetcode.cn/problems/validate-stack-sequences/

执行用时：8 ms, 在所有 C++ 提交中击败了70.24% 的用户
内存消耗：14.9 MB, 在所有 C++ 提交中击败了66.84% 的用户
通过测试用例：151 / 151
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pos = 0, n = pushed.size();
        for(int i = 0; i < n; i++){
            if(pushed[i] == popped[pos]){
                pos ++;
                while(!s.empty() && s.top() == popped[pos]){
                    s.pop();
                    pos ++;
                }
            }else
                s.push(pushed[i]);
        }
        return s.empty()?true:false;
    }
};