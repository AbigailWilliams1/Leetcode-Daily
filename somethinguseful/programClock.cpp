#include<bits/stdc++.h>
using namespace std;

int main(){
    clock_t start, finish;  
    double time_length;  

    start = clock();//start  
    //计算时间的代码片  
    finish = clock();//finish  
    
    //根据两个时刻的差，计算出运行的时间  ，而且CLOCKS_PER_SEC = 1000 的
    time_length = (double)(finish - start) / CLOCKS_PER_SEC;
    cout<<"Time used is "<<time_length<<" second."<<endl;
    return 0;
}