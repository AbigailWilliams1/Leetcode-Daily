/*
857. 雇佣 K 名工人的最低成本                难度：困难
有 n 名工人。 给定两个数组 quality 和 wage ，其中，quality[i] 表示第 i 名工人的工作质量，其最低期望工资为 wage[i] 。
现在我们想雇佣 k 名工人组成一个工资组。在雇佣 一组 k 名工人时，我们必须按照下述规则向他们支付工资：
    对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
    工资组中的每名工人至少应当得到他们的最低期望工资。
给定整数 k ，返回 组成满足上述条件的付费群体所需的最小金额 。在实际答案的 10-5 以内的答案将被接受。。

链接：https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/

执行用时：28 ms, 在所有 C++ 提交中击败了92.55% 的用户
内存消耗：22.1 MB, 在所有 C++ 提交中击败了27.66% 的用户
通过测试用例：46 / 46
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> wagequality;
        for(int i = 0; i < n; i++){
            wagequality.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(wagequality.begin(), wagequality.end());

        double ans;
        int sum = 0;
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            pq.push(wagequality[i].second);
            sum += wagequality[i].second;
        }

        ans = wagequality[k-1].first * sum;

        for(int i = k; i < n; i++){
            if(pq.top() > wagequality[i].second){
                sum -= pq.top();
                sum += wagequality[i].second;
                pq.pop();
                pq.push(wagequality[i].second);
            }
            ans = min(ans, sum * wagequality[i].first);
        }
        return ans;
    }
};