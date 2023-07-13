#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int>* solve(TreeNode<int>* root, int x, int y){
    if(!root) return NULL;
    if(root->data == x or root->data == y) return root;

    TreeNode<int>* left = solve(root->left, x, y);
    TreeNode<int>* right = solve(root->right, x, y);

    if(!left and !right){
        return NULL;
    }
    else if(left and right){
        return root;
    }
    else{
        return left?left:right;
    }
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int>* res = solve(root, x, y);
    return res?res->data:-1;
}
