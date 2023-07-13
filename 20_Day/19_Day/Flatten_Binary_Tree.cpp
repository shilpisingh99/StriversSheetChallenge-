#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solve(TreeNode<int>* root){
    if(!root) return root;
    TreeNode<int>* left = solve(root->left);
    TreeNode<int>* right = solve(root->right);

    root->right = left;
    TreeNode<int>* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    curr -> right = right;

    return root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    return solve(root);
}