#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int s = garbage.size();
        int m = 0, p = 0, g = 0, time = 0;
        for(int i = 0; i < s; i++){
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'M')m = i;
                else if(garbage[i][j] == 'G')g = i;
                else p = i;
            }
            time += garbage[i].size();
        }
        int addtravel = 0;
        for(int i = 0; i < s-1; i++){
            addtravel += travel[i];
            if(i == m - 1)time += addtravel;
            if(i == p - 1)time += addtravel;
            if(i == g - 1)time += addtravel;
        }
        return time;
    }
};

int main(){

    return 0;
}