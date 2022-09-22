/*
剑指 Offer 62. 圆圈中最后剩下的数字             难度：简单
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
求出这个圆圈里剩下的最后一个数字。
例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

链接：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

执行用时：4 ms, 在所有 C++ 提交中击败了93.40% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了89.11% 的用户
通过测试用例：36 / 36
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    struct Node{
        int val;
        Node* next;
        Node(int v):val(v), next(nullptr){}
    };
    */

    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = (ans + m) % i;
        return ans;

        /*链表法
        Node * tail = new Node(0);
        Node * head = tail;
        for(int i = 1; i < n; i++){
            tail->next = new Node(i);
            tail = tail->next;
        }
        tail->next = head;
        while(n > 1){
            for(int i = 0; i < (m-1)%n; i++){
                tail = tail->next;
            }
            Node* t = tail->next;
            tail->next = t->next;
            delete t;
            t = nullptr;
            n --;
        }
        return tail->val;
        */

        /*暴力法：
        vector<int> v(n);
        for(int i = 0; i < n; i ++)
            v[i] = i;
        int num = n, pos = n-1, tmp;
        while(num > 1){
            tmp = m;
            while(tmp){
                ++ pos %= n;
                if(v[pos] != -1)
                    tmp --;
            }
            cout<<v[pos]<<" ";
            v[pos] = -1;
            num --;
        }
        for(auto i : v){
            if(i != -1)return i;
        }
        return -2;
        */
    }
};

int main(){
    clock_t start_time, end_time;
    start_time = clock();
    Solution A;
    int n = 70866, m = 116922;
    cout<<A.lastRemaining(n, m)<<endl;
    end_time = clock();
    std::cout<< "Total time: " 
			<< (double)(end_time - start_time) / CLOCKS_PER_SEC 
			<< "s" << std::endl;
    return 0;
}