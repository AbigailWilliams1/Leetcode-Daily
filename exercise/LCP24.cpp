/*
LCP 24. 数字游戏                难度：困难
小扣在秋日市集入口处发现了一个数字游戏。主办方共有 N 个计数器，计数器编号为 0 ~ N-1。每个计数器上分别显示了一个数字，小扣按计数器编号升序将所显示的数字记于数组 nums。
每个计数器上有两个按钮，分别可以实现将显示数字加一或减一。小扣每一次操作可以选择一个计数器，按下加一或减一按钮。
主办方请小扣回答出一个长度为 N 的数组，第 i 个元素(0 <= i < N)表示将 0~i 号计数器 初始 所示数字操作成满足所有条件 nums[a]+1 == nums[a+1],(0 <= a < i) 的最小操作数。回答正确方可进入秋日市集。
由于答案可能很大，请将每个最小操作数对 1,000,000,007 取余。

链接：https://leetcode.cn/problems/5TxKeK/
*/

#include "temp.h"

class Solution {
    const int mod = 1e9 + 7;
    long long sum_g = 0, sum_l = 0;
    priority_queue<int, vector<int>, std::greater<int>> pq_g;
    priority_queue<int, vector<int>, std::less<int>> pq_l;
public:
    void push(int i, int num){
        if(i & 1){
            if(num > pq_g.top()){
                pq_g.push(num); sum_g += num;
                pq_l.push(pq_g.top()); sum_l += pq_g.top();
                sum_g -= pq_g.top(); pq_g.pop();
            }else{
                pq_l.push(num); sum_l += num;
            }
        }else{
            if(num >= pq_l.top()){
                pq_g.push(num); sum_g += num;
            }else{
                pq_l.push(num); sum_l += num;
                pq_g.push(pq_l.top()); sum_g += pq_l.top();
                sum_l -= pq_l.top(); pq_l.pop(); 
            }
        }
    }

    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        pq_g.push(nums[0]); sum_g += nums[0];
        for(int i = 1; i < n; i++){
            push(i, nums[i] - i);
            ans[i] = (sum_g - sum_l - pq_g.top() * (i + 1 & 1)) % mod;
        }
        return ans;
    }
};