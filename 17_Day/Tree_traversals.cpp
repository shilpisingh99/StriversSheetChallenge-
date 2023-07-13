void inOrderTraversal(BinaryTreeNode<int>* root,vector<vector<int>>& res){
    if(!root) return ;
    inOrderTraversal(root->left, res);
    res[0].push_back(root->data);
    inOrderTraversal(root->right, res);
}

void preOrderTraversal(BinaryTreeNode<int>* root,vector<vector<int>>& res){
    if(!root) return ;
    res[1].push_back(root->data);
    preOrderTraversal(root->left, res);
    preOrderTraversal(root->right, res);
}

void postOrderTraversal(BinaryTreeNode<int>* root,vector<vector<int>>& res){
    if(!root) return ;
    postOrderTraversal(root->left, res);
    postOrderTraversal(root->right, res);
    res[2].push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res(3);
    inOrderTraversal(root,res);
    preOrderTraversal(root,res);
    postOrderTraversal(root,res);
    return res;
}