bool solve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(!root1 and !root2) return true;
    if(!root1 or !root2) return false;

    return root1->data == root2->data and solve(root1->left, root2->right) and solve(root1->right, root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return solve(root->left, root->right);
}