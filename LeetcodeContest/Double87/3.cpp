#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;
/*
template<class T>
void show(vector<T>& a){
    for(auto &i : a)
        cout<<i<<" ";
    cout<<endl;
    return;
}
*/
class Solution {
private:
    vi orToVector(vi& a, int b){
        int t = 31;
        while(b){
            if(b&1)a[t]++;
            b >>= 1;
            t--;
        }
        return a;
    }

    bool down(vi&a, vi&b){
        for(int i = 0; i < 32; i++){
            if(a[i] == 0 && b[i] > 0)
                return false;
        }
        return true;
    }

    void subnum(vi& a, int b){
        int t = 31;
        while(b){
            if(b&1)a[t]--;
            b >>= 1;
            t--;
        }
        return;
    }

    vi subVec(vi a, vi b){
        vi ans(32);
        for(int i = 0; i < 32;i++)
            ans[i] = b[i] - a[i];
        return ans;
    }

public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vvi sumOr(n+1);
        sumOr[n] = vi(32,0);
        vi ans(n);
        for(int i = n-1; i >= 0; i--)
            sumOr[i] = orToVector(sumOr[i+1], nums[i]);
        sumOr.push_back(vi(32,0));
        // for(auto &i:sumOr){
        //     show(i);
        // }
        // cout<<"----------------"<<endl;
        
        ans[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            int tmp = ans[i+1] + i + 1;
            vi tt = subVec(sumOr[tmp+1], sumOr[i+1]);
            vi t = tt;
            //cout<<i<<endl;
            while(tmp > i && down(t, tt)){
                //show(t);
                tmp--;
                subnum(t,nums[tmp]);
                //show(t);
            }
            ans[i] = tmp-i+1;
        }
        return ans;
    }
};
