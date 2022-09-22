/*
第307场周赛-第三题
6154. 感染二叉树需要的总时间                难度：中等

给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。
每分钟，如果节点满足以下全部条件，就会被感染：
    节点此前还没有感染。
    节点与一个已感染节点相邻。
返回感染整棵树需要的分钟数。

链接：https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/
*/
#include<bits/stdc++.h>
#include"D:\VsCode\leetcode\tools.h"
using namespace std;

class Solution {
public:
    bool find = false;
    vector<TreeNode*> path;
    unordered_map<TreeNode*, int> tree;

    int lngthOfTree(TreeNode* root){
        if(root == nullptr){
            tree[root] = 0;
            return 0;
        }
        int l = 0;
        if(root->left)l = max(l, lngthOfTree(root->left));
        if(root->right)l = max(l, lngthOfTree(root->right));
        l += 1;
        tree[root] = l;
        return l;
    }

    int lngth(TreeNode* r){
        if(r == nullptr)return 0;
        else return tree[r];
    }

    void dfs(TreeNode* root, int start){
        if(root == nullptr)return;
        if(!find)path.push_back(root);

        //cout<<root->val<<" ----> ";

        if(root->val == start){
            find = true;
            return;
        }
        dfs(root->left, start);
        dfs(root->right, start);
        if(!find)path.pop_back();
    }

    TreeNode* sister(TreeNode* parent, TreeNode* bro){
        if(parent->left == bro)return parent->right;
        if(parent->right == bro)return parent->left;
        return nullptr;
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        
        
        // cout<<endl;
        // for(auto i : path)
        //     cout<<i->val<<", ";
        // cout<<endl;

        lngthOfTree(root);
        // for(auto i = tree.begin(); i != tree.end(); i++)
        //     cout<<"Node: "<<i->first->val<<", Length: "<<i->second<<endl;
        // cout<<endl;
        

        if(root->val == start)
            return max(lngth(root->left), lngth(root->right));
        int ans, n = path.size()-1;
        ans = lngth(path[n])-1;
        for(int i = n-1; i >= 0; i--){
            ans = max(ans, lngth(sister(path[i], path[i+1]))+n-i);
        }
        return ans;
    }
};

int main(){
    Solution A;
    TreeNode* root = createATree();
    int start = 3;
    //cout<<A.lngth(root);
    cout<<A.amountOfTime(root, start);
    return 0;
}