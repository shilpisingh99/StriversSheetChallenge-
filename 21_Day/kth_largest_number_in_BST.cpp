#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int KthLargestNumber(TreeNode<int>* root, int k) 
{

    int countNodes = 0;
    TreeNode<int>* temp = root;
    while(root){
        if(!root->left){
            countNodes++;
            root = root->right;
        }
        else{
            //find inorder predecessor of current Node
            TreeNode<int>* curr = root->left;
            while(curr->right and curr->right != root){
                curr = curr->right;
            }
            if(!curr->right){
                curr->right = root;
                root = root->left;
            }
            else{
                curr->right = NULL;
                countNodes++;
                root = root->right;
            }
        }
    }
    // cout<<"No of Nodes: "<<countNodes<<" "<<countNodes-k<<endl;
    int count = 0, res = -1;
    root = temp;
    while(root){
        if(!root->left){
            count++;
            if(count == countNodes - k + 1) return  root->data;
            root = root->right;
        }
        else{
            //find inorder predecessor of current Node
            TreeNode<int>* curr = root->left;
            while(curr->right and curr->right != root){
                curr = curr->right;
            }
            if(!curr->right){
                curr->right = root;
                root = root->left;
            }
            else{
                curr->right = NULL;
                count++;
                if(count == countNodes - k + 1) return root->data;
                root = root->right;
            }
        }
    }
    return res;
}