#include<bits/stdc++.h>
using namespace std;

int solution(int a, int b, int c, int d){
    long long int s = (long long)a*(long long)d, t = (long long)b*(long long)c;
    if(s == t)return 0;
    if(s == 0 || t == 0 || s%t == 0 || t%s == 0)return 1;
    else return 2;
}

int main(){
    int n;
    cin>>n;
    int a, b, c, d;
    while(n){
        n--;
        cin>>a>>b>>c>>d;
        cout<<solution(a,b,c,d)<<endl;
    }
    return 0;
}