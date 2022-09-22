#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row(k+1, 0);
        for(auto i : rowConditions){
            if(row[i[0]] == row[i[1]])row[i[0]]++;
            else if(row[i[0]] < row[i[1]])row[i[0]]
        }

    }
};

int main(){

    return 0;
}