void traverse(TreeNode* root, vector<int>& res){
    if(!root) return ;
    res.push_back(root -> data);
    traverse(root -> left, res);
    traverse(root -> right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}