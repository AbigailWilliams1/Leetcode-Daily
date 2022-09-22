#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    char shiftChar(char a, int d){
        if(d == 1){
            if(a == 'z')return 'a';
            else return a+1;
        }else{
            if(a == 'a')return 'z';
            else return a-1;
        }
    }
    
    string shifting(string& s, int low, int high, int d){
        for(int i = low; i <= high; i++){
            s[i] = shiftChar(s[i], d);
        }
        return s;
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(int i = 0; i < shifts.size(); i++){
            s = shifting(s, shifts[i][0], shifts[i][1], shifts[i][2]);
        }
        return s;
    }
    /*
    char shift(char a, int s){
        while(s<0){
            s+=26;
        }
        if(s > 0)s=s%26;
        if(a+s>'z')return a-(26-s);
        else return a+s;
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> act(n,0);
        for(int i = 0; i < shifts.size(); i++){
            if(shifts[i][2]){
                for(int j = shifts[i][0];j<=shifts[i][1];j++)
                    act[j]++;
            }else{
                for(int j = shifts[i][0];j<=shifts[i][1];j++)
                    act[j]--;
            }
        }
        for(int i = 0; i < n; i++){
            s[i] = shift(s[i], act[i]); 
        }
        return s;
    }
    */
};