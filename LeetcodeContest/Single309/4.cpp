#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct cmp{
        bool operator() (vector<int>& a, vector<int>& b ){ 
            //compare  
            return (a[0]>b[0]) || (a[0]==b[0] && a[2]>b[2]); 
        }
    };

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //sort(meetings.begin(), meetings.end(), cmp);
        int m = meetings.size();
        for(int i = 0; i < m; i++)
            meetings[i].push_back(meetings[i][0]);

        vector<bool> used(n, false);
        vector<int> nums(n, 0);

        vector<int> tmp(n);
        for(int i = 0; i < n; i++)
            tmp[i]=i;

        priority_queue<int, vector<int>, greater<int>> pq(tmp.begin(), tmp.end());
        priority_queue<vector<int>, vector<vector<int>, cmp>> task(meetings.begin(), meetings.end());

        while(!task.empty()){
            
        }

    }
};