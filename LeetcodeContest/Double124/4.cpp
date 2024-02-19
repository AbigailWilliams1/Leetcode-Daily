#include "temp.h"

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, cur = nums[0], ans = 0;
        while(l < n){
            int length, d = 0, old_l = l;
            cur = nums[l];
            while(r+1 < n && (nums[r+1]-cur<=1)){
                if(nums[r+1]-cur >= 0)cur++;
                else d++;
                r++;
            }
            // pr(l);pr(r);
            //if(l > 0 && (nums[l-1]+2==nums[l] || nums[l-1]+1==nums[l]))
                //length ++;
            cur = nums[l];
            while(l > 0 && cur-nums[l-1]<=2){
                if(cur-nums[l-1]>0)cur--;
                else d++;
                l--;
            }
            length = r-l+1 - d;
            ans = max(ans, length);
            if(r == old_l)l = ++r;
            else l = r;
        }
        return ans;
    }
};

int main()
{
    vector<int> t1 = {8,10,6,12,9,12,2,3,13,19,11,18,10,16};
    vector<int> t2 = {12,11,8,7,2,10,18,12};
    auto t = t1;
    sort(t.begin(), t.end());
    show(t);
    Solution A;
    int ret = A.maxSelectedElements(t);
    pr(ret);
    return 0;
}