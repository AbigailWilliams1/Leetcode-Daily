/*
剑指 Offer 41. 数据流中的中位数             难度：困难
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
例如，[2,3,4] 的中位数是 3[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
    void addNum(int num) - 从数据流中添加一个整数到数据结构中。
    double findMedian() - 返回目前所有元素的中位数。

链接：https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/

执行用时：160 ms, 在所有 C++ 提交中击败了11.78% 的用户
内存消耗：40.7 MB, 在所有 C++ 提交中击败了30.52% 的用户
通过测试用例：18 / 18
*/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int, vector<int>, less<int>> small;
    int length;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        length = 0;
    }
    
    void addNum(int num) {
        if(length == 0)big.push(num);
        else if(length & 1){
            if(big.top() >= num)small.push(num);
            else{
                small.push(big.top());
                big.pop();
                big.push(num);
            }
        }else{
            if(small.top() <= num)big.push(num);
            else{
                big.push(small.top());
                small.pop();
                small.push(num);
            }
        }
        length ++;
    }
    
    double findMedian() {
        if(length & 1)return big.top();
        else return (double)(big.top()+small.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */