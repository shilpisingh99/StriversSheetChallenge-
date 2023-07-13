BinaryTreeNode<int>* ceil(BinaryTreeNode<int>* node, int x, BinaryTreeNode<int>* &res){
    if(!node) return node;
    if(node->data == x){
        res = node;
        return node;
    }
    else if(node->data > x){
        res = node;
        return ceil(node->left, x, res);
    }
    else return ceil(node->right, x, res);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int>* res = NULL;
    ceil(node, x, res);
    return res ? res->data:-1;
}