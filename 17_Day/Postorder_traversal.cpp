void traverse(TreeNode* root, vector<int>& res){
    if(!root) return ;
    traverse(root -> left, res);
    traverse(root -> right, res);
    res.push_back(root -> data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}