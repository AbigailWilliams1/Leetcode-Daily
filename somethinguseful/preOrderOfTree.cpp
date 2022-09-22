#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){};
    TreeNode(int v):val(v), left(nullptr), right(nullptr){};
};

void preOrder(TreeNode* root){
    stack<TreeNode*> s;
    TreeNode* r= root;
    while(r||!s.empty()){
        for(;r;r=r->left)
            s.push(r);
        r=s.top();
        if(r){
            s.pop();
            cout<<r->val<<" ";
            r=r->right;
        }
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    /*
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    */
    preOrder(root);
    return 0;
}