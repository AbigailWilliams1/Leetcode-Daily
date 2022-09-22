#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2){
        return (v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]));
    }

    /*
    class Compare{
    public:
        bool operator()(vector<int>& v1, vector<int>& v2)const{
            return (v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]));
        }
    };

    void choose(multiset<vector<int>, Compare>& mv){
        auto it = mv.begin();
        int finish = 0;
        while(it != mv.end()){
            if(it->front() > finish){
                finish = it->back();
                it = mv.erase(it);
            }else{
                it++;
            }
        }
        return;
    }
*/
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> room;
        room.push(0);
        
        for(auto &i : intervals){
            int tmp = room.top();
            if(tmp < i[0])room.pop();
            room.push(i[1]);
        }
        return room.size();
    }

        /*
        multiset<vector<int>, Compare> mv;
        for(auto &i : intervals){
            mv.insert(i);
        }

        int ans;
        while(!mv.empty()){
            choose(mv);
            ans++;
        }
        return ans;
    }
        */

};