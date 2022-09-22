#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int number[10] = {0};
        string s = "";
        for(int i = 0; i < num.size(); i++)
            number[num[i] - '0'] ++;
        for(int i = 9; i > 0; i--){
            for(int j = 0; j < number[i]/2; j++)
                s += to_string(i);
        }
        if(s != ""){
            for(int j = 0; j < number[0]/2; j++)
                s += "0";
        }
        char mid = '#';
        for(int i = 9; i >= 0; i--){
            if(number[i]%2 == 1){
                mid = '0'+i;
                break;
            }
        }
        string tmp = s;
        reverse(s.begin(), s.end());
        if(mid != '#')
            s = tmp + string(1,mid) + s;
        else s = tmp + s;
        return s;
    }
};

int main(){
    Solution A;
    string s ="000000";
    cout << A.largestPalindromic(s);
    return 0;
}