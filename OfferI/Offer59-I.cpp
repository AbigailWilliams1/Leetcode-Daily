/*
剑指 Offer 59 - I. 滑动窗口的最大值             难度：困难
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
示例:
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
提示：
你可以假设 k 总是有效的，在输入数组 不为空 的情况下，1 ≤ k ≤ nums.length。

链接：https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

执行用时：216 ms, 在所有 C++ 提交中击败了23.20% 的用户
内存消耗：125.1 MB, 在所有 C++ 提交中击败了21.36% 的用户
通过测试用例：51 / 51
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k <= 1)return nums;
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            while(dq.front() <= i-k)dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
/*
        if(k == 1)return nums;
        int n = nums.size(), maxindex = 0;
        if(n == 0)return {};
        vector<int> ans;
        int down = 1;
        while(down<k && nums[k-1-down] >= nums[k-down])
            down++;
        maxindex = k-down;
        for(int i = k-2-down; i >= 0; i--){
            if(nums[i] > nums[maxindex])maxindex = i;
        }
        //cout<<down;
        ans.push_back(nums[maxindex]);

        int right = k, left = right-k+1, mid = right-down;
        while(right < n){
            int tmp = mid;
            if(nums[right] <= nums[right-1])mid = max(left, mid);
            else mid = right;

            if(nums[right] >= nums[maxindex])maxindex = right;
            else if(maxindex < left){
                if(mid <= left+1)maxindex = mid;
                else if(mid < right){
                    int mm = max_element(nums.begin()+left, nums.begin()+mid-1) - nums.begin();
                    maxindex = (nums[mm] > nums[mid])?mm:mid;
                }else if(tmp <= left+1){
                    maxindex = (nums[tmp] > nums[right])?tmp:right;
                }else{
                    int mm = max_element(nums.begin()+left, nums.begin()+tmp-1) - nums.begin();
                    if(nums[mm] > nums[tmp] && nums[mm] > nums[right])maxindex = mm;
                    else if(nums[tmp] > nums[right])maxindex = tmp;
                    else maxindex = right;
                }
            }
            ans.push_back(nums[maxindex]);
            right++;
            left++;
        }

        return ans; 
        */
    }
    
};