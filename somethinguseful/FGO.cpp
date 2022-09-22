#include<bits/stdc++.h>
using namespace std;

int main(){
    long double upRate = 0.008;              //up五星单抽出货率
    long double notUp = 1.000 - upRate;      //up五星单抽沉船率
    long long number = 534;                   //抽卡次数
    cout<< "0 宝概率为："<<pow(notUp, number)<<endl;
    cout<< "1 宝概率为："<<number * pow(notUp, number-1) * upRate<<endl;
    cout<< "2 宝概率为："<<number*(number-1)/2 * pow(notUp, number-2) * pow(upRate, 2)<<endl;
    cout<< "3 宝概率为："<<number*(number-1)*(number-2)/6 * pow(notUp, number-3) * pow(upRate, 3)<<endl;
    cout<< "4 宝概率为："<<number*(number-1)*(number-2)*(number-3)/24 * pow(notUp, number-4) * pow(upRate, 4)<<endl;
    cout<< "5 宝概率为："<<number*(number-1)*(number-2)*(number-3)*(number-4)/120 * pow(notUp, number-5) * pow(upRate, 5)<<endl;
    return 0;
}