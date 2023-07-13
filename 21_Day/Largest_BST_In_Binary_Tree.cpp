#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class Info{
  public:
    bool isBST = false;
    int maxValue = INT_MAX;
    int minValue = INT_MIN;
    int size = 0;

    Info(){
        //default constructor
    }

    Info(bool isBST, int maxValue, int minValue, int size){
        this->isBST = isBST;
        this->maxValue = maxValue;
        this->minValue = minValue;
        size = size;
    }
};

int ans = 0;

Info solve(TreeNode<int>* root){
    if(!root) return Info(true, INT_MIN, INT_MAX, 0);
    Info left = solve(root->left);
    Info right = solve(root->right);
    if(left.isBST and right.isBST and  root->data >= left.maxValue and root->data <= right.minValue){
        Info res;
        res.isBST = true;
        res.maxValue = max(root->data,right.maxValue);
        res.minValue = min(root->data, left.minValue);
        res.size = 1 + left.size + right.size;
        ans = max(ans, res.size);
        return res;
    }
    else{
        return Info();
    }
}
int largestBST(TreeNode<int>* root) 
{
    ans = 0;
    solve(root);
    return ans;
}