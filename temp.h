#ifndef TEMP
#define TEMP
#include<bits/stdc++.h>
#define pr(x) cout<<#x<<" = "<<x<<endl
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

template<class T>
void show(T& a){
    for(auto &i : a)
        cout<<i<<" ";
    cout<<endl;
    return;
}

template<class T>
void show(T& a, int k){
    for(int j = 0; j < k; j++)
        cout<<a[j]<<" ";
    cout<<endl;
    return;
}

template<class T>
void show(T& a, int l, int r){
    for(int j = l; j < r; j++)
        cout<<a[j]<<" ";
    cout<<endl;
    return;
}

#endif