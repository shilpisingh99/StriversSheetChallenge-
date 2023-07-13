#include <bits/stdc++.h> 
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
map<int,int> inMap;

TreeNode<int>* solve(int& idx, int n, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder){
    if(idx < 0 or inStart > inEnd) return NULL;

    TreeNode<int>* root = new TreeNode<int>(postorder[idx--]);
    int i = inMap[root->data];
    root->right = solve(idx, n, i+1, inEnd, inorder, postorder);
    root->left = solve(idx, n, inStart, i-1, inorder, postorder);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
    int n = inorder.size();
    inMap.clear();
    for(int i = 0; i < n; i++){
        inMap[inorder[i]] = i;
    }
    int idx = inorder.size()-1;
    return solve(idx, n, 0, n-1, inorder, postorder);
}
