#include<bits/stdc++.h>
using namespace std;

void show(vector<int> a){
    for(auto i : a)
        cout<<i<<" ";
    cout<<endl;
    return;
}

class Solution {
public:
    bool isStrict(int n, int k){
        vector<int> num;
        while(n){
            num.push_back(n%k);
            n /= k;
        }
        vector<int> tmp = num;
        //show(tmp);
        reverse(num.begin(), num.end());
        //show(num);
        if(tmp == num)return true;
        else return false;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i < n-1; i++){
            if(!isStrict(n, i))return false;
        }
        return true;
    }
};

int main(){
    Solution a;
    cout<<a.isStrict(7782, 10);
    return 0;
}