/*
721. 账户合并               难度：中等
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。
现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。
请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。
一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 按字符 ASCII 顺序排列 的邮箱地址。账户本身可以以 任意顺序 返回。

链接：https://leetcode.cn/problems/accounts-merge/
*/
#include "temp.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(), f[n];
        iota(f, f+n, 0);
        function<int(int)> find = [&f](int x){
            while(x!=f[x])x=f[x]=f[f[x]];
            return x;
        };

        unordered_map<string, int> index;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(index.count(accounts[i][j]))
                    f[find(i)] = find(index[accounts[i][j]]);
                else
                    index[accounts[i][j]] = i;
            }
        }
        
        unordered_map<int, set<string>> mails_map;
        for(int i = 0; i < n; i++){
            int id = find(i);
            for(int j = 1; j < accounts[i].size(); j++)
                mails_map[id].insert(accounts[i][j]);
        }
        
        vector<vector<string>> ans;
        for(auto& [id, mails] : mails_map){
            vector<string> account;
            account.push_back(accounts[id][0]);
            for(auto& mail : mails)
                account.push_back(mail);
            ans.push_back(move(account));
        }
        return ans;
    }
};