
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root){
        if(root->data == x) {
            return true;
        }
        else if(root->data > x){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return false;
}