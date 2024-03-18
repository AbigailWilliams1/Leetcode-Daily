/*
303. 区域和检索 - 数组不可变                难度：简单
给定一个整数数组  nums，处理以下类型的多个查询:
计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )

链接：https://leetcode.cn/problems/range-sum-query-immutable/description/
*/
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> sum_v;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        sum_v.push_back(sum);
        for(auto num : nums){
            sum += num;
            sum_v.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return sum_v[right + 1] - sum_v[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */