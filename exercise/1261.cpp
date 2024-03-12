/*
1261. 在受污染的二叉树中查找元素                难度：中等
给出一个满足下述规则的二叉树：
    root.val == 0
    如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
    如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
    现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。
请你先还原二叉树，然后实现 FindElements 类：
FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。

链接：https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/description/
*/
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    unordered_set<int> nodes;

    void dfs(TreeNode* root, int value){
        nodes.insert(value);
        if(root->left)dfs(root->left, value * 2 + 1);
        if(root->right)dfs(root->right, value * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return nodes.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */