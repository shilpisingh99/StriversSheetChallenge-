#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root){
    return !root->left and !root->right;
}

vector<int> leftBorder(TreeNode<int>* root){
    vector<int> res;
    root = root->left;
    while(root){
        if(!isLeaf(root)) res.push_back(root->data);
        if(root->left){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return res;
}

vector<int> rightBorder(TreeNode<int>* root){
    vector<int> res;
    root = root->right;
    while(root){
        if(!isLeaf(root)) res.push_back(root->data);
        if(root->right){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void addLeafNodes(TreeNode<int>* root, vector<int>& res){
    if(!root) return;
    if(isLeaf(root)){
        res.push_back(root->data);
    }
    addLeafNodes(root->left, res);
    addLeafNodes(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    vector<int> left = leftBorder(root);
    if(!isLeaf(root)) res.push_back(root->data);
    for(auto &i:left){
        res.push_back(i);
    }
    addLeafNodes(root, res);
    vector<int> right = rightBorder(root);
    for(auto &i:right){
        res.push_back(i);
    }
    return res;
}