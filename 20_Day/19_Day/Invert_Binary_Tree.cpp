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

bool storeParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents, TreeNode<int> *leaf) {
    parents.push(root);

    if (!root->left and !root->right) {
        if (root->data == leaf->data)
        return true;
        else
        parents.pop();
        return false;
    }

    if (root->left) {
        if (storeParents(root->left, parents, leaf))
        return true;
    }

    if (root->right) {
        if (storeParents(root->right, parents, leaf))
        return true;
    }

    parents.pop();
    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
    if (!root) return NULL;

    stack<TreeNode<int> *> parents;
    storeParents(root, parents, leaf);

    TreeNode<int> *head = parents.top();
    parents.pop();

    TreeNode<int> *par = head;
    while (!parents.empty()) {
        auto p = parents.top();
        parents.pop();

        if (p->right == head) {
            p->right = p->left;
            p->left = NULL;
        } 
        else {
            p->left = NULL;
        }

        head->left = p;
        head = p;
    }

    return par;
}