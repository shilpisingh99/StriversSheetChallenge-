bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(!root1 and !root2) return true;
    if(!root1 or !root2) return false;
    if(root1->data == root2->data){
        return solve(root1->left, root2->left) and solve(root1->right, root2->right);
    }
    else{
        return false;
    }
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return solve(root1, root2);
}