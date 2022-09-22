#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int, int> usii;

class Solution {
public:
    const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int caldays(string a, string b){
        int amonth = to_string(a.substr(0, 2)), aday = to_string(a.substr(3, 2));
        int bmonth = to_string(b.substr(0, 2)), bday = to_string(b.substr(3, 2));
        int ans = 0;
        for(int i = amonth; i < bmonth; i++)
            ans += days[i];
        return ans + bday - aday;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        if(leaveAlice < arriveBob || leaveBob < arriveAlice)return 0;
        vector<string> date{arriveAlice, leaveAlice, arriveBob, leaveBob};
        sort(date.begin(), date.end());
        return caldays(date[0], date[3]) - caldays(days[1], days[2]);
    }
};
