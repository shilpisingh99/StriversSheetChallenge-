bool validateBST(BinaryTreeNode<int> *root, int mini = -1e9, int maxi = 1e9) {
    if(!root) return true;
    if(root->data >= mini and root->data <= maxi){
        return validateBST(root->left, mini, root->data) and validateBST(root->right, root->data, maxi);
    }
    return false;
}