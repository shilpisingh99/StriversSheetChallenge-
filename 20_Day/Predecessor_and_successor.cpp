#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int> *root, pair<int,int> &p, int &key){

    if(root==nullptr) return;

    if(root->data>p.first && root->data<key)

    p.first=root->data;

    if(root->data<p.second && root->data>key)

    p.second=root->data;

    solve(root->left,p,key);

    solve(root->right,p,key);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> p={INT_MIN,INT_MAX};
    solve(root,p,key);
    
    if(p.first==INT_MIN) p.first=-1;

    if(p.second==INT_MAX) p.second=-1;

    return p;
}
