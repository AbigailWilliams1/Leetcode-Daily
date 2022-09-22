#include<tools.h>

TreeNode* createATree(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    /*
                        1
                       / \
                      2   3
                     / \   \
                    4   5   6
                       /   / \
                      7   8   9
    */
    return root;
}