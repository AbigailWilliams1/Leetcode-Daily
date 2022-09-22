/*
剑指 Offer 36. 二叉搜索树与双向链表             难度：中等
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。。
对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
还需要返回链表中的第一个节点的指针。

链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了26.51% 的用户
通过测试用例：50 / 50
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root){
        if(!root)return root;
        if(!root->left && !root->right){
            root->left = root;
            root->right = root;
            return root;
        }
        Node* l = root->left, *r = root->right;
        if(l){
            Node* leftchild = treeToDoublyList(l);
            if(leftchild->left == nullptr){
                leftchild->right = root;
                root->left = leftchild;
            }else{
                leftchild->left->right = root;
                root->left = leftchild->left;
            }
            leftchild->left = root;
            root->right = leftchild;
        }
        Node* head = (l==nullptr)?root:root->right;
        if(r){
            Node* rightchild = treeToDoublyList(r);
            if(rightchild->left == nullptr){
                head->left = rightchild;
                rightchild->right = head;
            }else{
                head->left = rightchild->left;
                rightchild->left->right = head;
            }
            rightchild->left = root;
            root->right = rightchild;
        }
        return head;
    }
};