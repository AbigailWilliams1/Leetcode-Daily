/*
658. 找到 K 个最接近的元素              难度：中等
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
整数 a 比整数 b 更接近 x 需要满足：
    |a - x| < |b - x| 或者
    |a - x| == |b - x| 且 a < b

链接：https://leetcode.cn/problems/find-k-closest-elements/

执行用时：36 ms, 在所有 C++ 提交中击败了50.35% 的用户
内存消耗：32.2 MB, 在所有 C++ 提交中击败了8.19% 的用户
通过测试用例：66 / 66
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1, mid;
        while(l<r){
            mid = (r-l)/2+l;
            if(arr[mid] == x){l=mid;r=mid;}
            else if(arr[mid] < x && l != mid)l = mid;
            else if(arr[mid] > x)r = mid-1;
            else {
                if(arr[r]<=x)l=r;
                break;
            }
        }
        int gap = 0, num = 0, tmp;
        r = l+1;
        //cout<<"l == "<<l<<", arr[l] == "<<arr[l]<<", r = "<<r<<", arr[r] == "<<arr[r]<<endl;
        vector<int> low, high;
        while(num<k && l >= 0 && r < arr.size()){
            //cout<<"l == "<<l<<", arr[l] == "<<arr[l]<<", r = "<<r<<", arr[r] == "<<arr[r]<<endl;
            if(x-arr[l]<=arr[r]-x){
                low.push_back(arr[l]);
                l--;
            }
            else {
                high.push_back(arr[r]);
                r++;
            }
            num++;
        }
        if(l<0){
            while(num < k){
                num++;
                high.push_back(arr[r]);
                r++;
            }
        }
        if(r>=arr.size()){
            while(num < k){
                num++;
                low.push_back(arr[l]);
                l--;
            }
        }
        /*
        for(auto &i : low)
            cout<<i<<" ";
        cout<<endl;
        for(auto &i : high)
            cout<<i<<" ";
        cout<<endl;
        */
        vector<int> ans;
        for(int i = low.size()-1; i >= 0; i--)
            ans.push_back(low[i]);
        for(int i = 0; i < high.size(); i++)
            ans.push_back(high[i]);
        return ans;
    }
};

int main(){
    vector<int> a = {0,1,2,3,4,4,4,5,5,5,6,7,9,9,10,10,11,11,12,13,14,14,15,17,19,19,22,24,24,25,25,27,27,29,30,32,32,33,33,35,36,38,39,41,42,43,44,44,46,47,48,49,52,53,53,54,54,57,57,58,59,59,59,60,60,60,61,61,62,64,66,68,68,70,72,72,74,74,74,75,76,76,77,77,80,80,82,83,85,86,87,87,92,93,94,96,96,97,98,99};
    Solution A;
    int k = 25, x = 90;
    vector<int> ans = A.findClosestElements(a,k,x);
    for(auto &i : ans){
        cout<<i<<" ";
    }
    return 0;
}