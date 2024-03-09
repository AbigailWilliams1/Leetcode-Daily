#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> s(n);
        long long ans = accumulate(nums.begin(), nums.end(), 0ll);
        for(int i = 0; i < n; i++){
            s[i] = (nums[i] ^ k) - nums[i];
        }
        sort(s.begin(), s.end(), greater<int>());
        for(int i = 0; i < n; i+=2){
            if(i == n - 1 || s[i] + s[i+1] < 0)break;
            ans += s[i] + s[i+1];
        }
        return ans;
    }
};