/*
2834. 找出美丽数组的最小和              难度：中等
给你两个正整数：n 和 target 。
如果数组 nums 满足下述条件，则称其为 美丽数组 。
nums.length == n.
nums 由两两互不相同的正整数组成。
在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和，并对结果进行取模 109 + 7。

链接：https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/
*/
#include <vector>
using namespace std;

class Solution {
public:
    using LL = long long;
    const int mod = 1e9+7;
    int minimumPossibleSum(int n, int target) {
        auto sum = [=](int begin, int len)->int{
            return ((LL)len * ((LL)begin * 2 + len - 1) / 2 ) % mod;
        };
        if(target >= n * 2)
            return sum(1, n);
        else
            return (sum(1, target/2) + sum(target, n-target/2)) % mod;
    }
};