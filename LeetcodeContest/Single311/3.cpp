#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;

    void bfd(TreeNode* r, vi& a, int root){
        a[root] = r->val;
        sum ++;
        if(r->left)bfd(r->left, a, root<<1);
        if(r->right)bfd(r->right, a, root<<1|1);
        return;
    }

    TreeNode* recover(vi& a, int root){
        if(root > sum)return nullptr;
        TreeNode* r = new TreeNode(a[root]);
        r->left = recover(a, root<<1);
        r->right = recover(a, root<<1|1);
        return r;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        vi tree(1<<14 | 7, 0);
        bfd(root, tree, 1);
        for(int i = 2; i <= sum; i <<= 2){
            reverse(tree.begin() + i, tree.begin() + (i<<1)-1);
        }
        return recover(tree, 1);
    }
};