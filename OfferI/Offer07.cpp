/*
剑指 Offer 07. 重建二叉树               难度：中等
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

链接：https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/

执行用时：40 ms, 在所有 C++ 提交中击败了14.33% 的用户
内存消耗：24.4 MB, 在所有 C++ 提交中击败了79.59% 的用户
通过测试用例：203 / 203
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*迭代版题解：
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){   //判断是否为空
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]); //先序的首为根节点
        stack<TreeNode*> stk;   //建立栈
        stk.push(root); //根节点入栈
        int inorderIndex = 0;   //扫描中序的指针
        for(int i = 1; i < preorder.size(); i++){   //从先序遍历开始逐个遍历
            TreeNode *node = stk.top();
            if(node->val != inorder[inorderIndex]){ //栈顶元素的值与中序遍历当前所指的元素值不等
                node->left = new TreeNode(preorder[i]); //前序遍历中处在栈顶元素位置后一位的元素是栈顶元素的左子树
                stk.push(node->left);   //栈顶元素左子树节点入栈
            }else{  //栈顶元素的值与中序遍历当前所指的元素值相等,栈顶即为最左下角的树节点
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]){ //while循环向上返回，寻找位置进行右子树的重建
                    node = stk.top();   //指针向右扫描中序遍历
                    stk.pop();  //栈中所有与当前指针所指元素值相等的节点出栈
                    inorderIndex++;
                }
                node->right = new TreeNode(preorder[i]);    // 循环结束后，node所指栈顶元素即是需要重建右子树的节点
                stk.push(node->right);
            }
        }
        return root;    
    }
};
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int prel, int prer, vector<int>& inorder, int inl, int inr) {
        if(prer < prel)return nullptr;
        TreeNode* root = new TreeNode(preorder[prel]);
        if(prer == prel)return root;
        int pos;
        for(int i = inl; i <= inr; i++){
            if(inorder[i] == preorder[prel]){
                pos = i;
                break;
            }
        }
        root->left = buildTree(preorder, prel+1, pos-inl+prel, inorder, inl, pos-1);
        root->right = buildTree(preorder, prer+pos+1-inr, prer, inorder, pos+1, inr);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

};