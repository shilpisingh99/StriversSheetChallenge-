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
map<int,int> inMap;

TreeNode<int>* solve(int& idx, int n, int inStart, int inEnd, vector<int>& inorder, vector<int>& preorder){
    if(idx >= n or inStart > inEnd) return NULL;

    TreeNode<int>* root = new TreeNode<int>(preorder[idx++]);
    int i = inMap[root->data];
    root->left = solve(idx, n, inStart, i-1, inorder, preorder);
    root->right = solve(idx, n, i+1, inEnd, inorder, preorder);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    inMap.clear();
    for(int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }
    int idx = 0;
    return solve(idx, inorder.size(), 0, inorder.size()-1, inorder, preorder);
}