#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root) return {};
    vector<int> res;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> temp;
        for(int i = 0; i < sz; i++){
            BinaryTreeNode<int>* frontNode = q.front();
            q.pop();
            temp.push_back(frontNode->data);
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        if(leftToRight){
            for(int i = 0; i < temp.size(); i++){
                res.push_back(temp[i]);
            }
        }
        else{
            for(int i = temp.size() - 1; i >= 0; i--){
                res.push_back(temp[i]);
            }
        }
        leftToRight = !leftToRight;
    }
    return res;
}