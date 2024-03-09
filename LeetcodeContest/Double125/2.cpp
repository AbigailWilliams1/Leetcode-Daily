#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    using ll = long long;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        int ans = 0;
        while(pq.size() > 1 && pq.top() < k){
            ans ++;
            int a = pq.top(); pq.pop();
            int b  =pq.top(); pq.pop();
            pq.push(min(a, b)*2 + max(a,b));
        }
        return ans;
    }
};