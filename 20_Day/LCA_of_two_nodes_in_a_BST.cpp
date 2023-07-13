#include <bits/stdc++.h> 

 

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q) {  

    if(root==NULL) return NULL;

    if(root->data > P->data and root->data > Q->data) {
        return LCAinaBST(root->left,P,Q); 
    }   
    else if(root->data < P->data and root->data < Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    return root;   
} 