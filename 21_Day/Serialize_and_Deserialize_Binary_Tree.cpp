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

string serializeTree(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    q.push(root);
    string res = "";
    while(!q.empty()){
        TreeNode<int>* frontNode = q.front();
        q.pop();
        if(!frontNode) res += "# ";
        else{
            res += to_string(frontNode->data);
            res += ' ';
            q.push(frontNode->left);
            q.push(frontNode->right);
        }
    }
    return res;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    stringstream s(serialized);
    string str = "";
    getline(s, str, ' ');
    if(str == "#") return NULL;
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* frontNode = q.front();
        q.pop();
        getline(s, str, ' ');
        if(str == "#") frontNode->left = NULL;
        else{
            frontNode->left = new TreeNode<int>(stoi(str));
            q.push(frontNode->left);
        }
        getline(s, str, ' ');
        if(str == "#") frontNode->right = NULL;
        else{
            frontNode->right = new TreeNode<int>(stoi(str));
            q.push(frontNode->right);
        }
    }
    return root;
}