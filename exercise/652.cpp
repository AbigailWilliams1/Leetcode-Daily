/*
652. 寻找重复的子树             难度：中等
给定一棵二叉树 root，返回所有重复的子树。
对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
如果两棵树具有相同的结构和相同的结点值，则它们是重复的。

链接：https://leetcode.cn/problems/find-duplicate-subtrees/

执行用时：36 ms, 在所有 C++ 提交中击败了60.40% 的用户
内存消耗：41.6 MB, 在所有 C++ 提交中击败了87.12% 的用户
通过测试用例：176 / 176
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    unordered_map<string, TreeNode*> mm;
    unordered_set<TreeNode*> repeat;
public:
    string dfs(TreeNode* r){
        if(!r)return "";
        string tmp = to_string(r->val) + "("+dfs(r->left) + ")(" + dfs(r->right) + ")";
        auto i = mm.find(tmp);
        if(i != mm.end()){
            repeat.insert(mm[tmp]);
        } else{
            mm[tmp] = r;
        }
        return tmp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return vector<TreeNode*>(repeat.begin(), repeat.end());
    }
};