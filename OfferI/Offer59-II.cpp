/*
面试题59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1

链接：https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/

执行用时：100 ms, 在所有 C++ 提交中击败了87.65% 的用户
内存消耗：47.6 MB, 在所有 C++ 提交中击败了41.59% 的用户
通过测试用例：34 / 34
*/
#include<bits/stdc++.h>
using namespace std;

class MaxQueue {
private:
    deque<int> dq;
    queue<int> data;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(data.empty())return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        data.push(value);
        while(!dq.empty() && dq.back() <= value)dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        if(data.empty())return -1;
        int tmp = data.front();
        data.pop();
        if(dq.front() == tmp)
            dq.pop_front();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */