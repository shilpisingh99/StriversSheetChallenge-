void traverse(TreeNode* root, vector<int>& res){
    if(!root) return ;
    traverse(root -> left, res);
    res.push_back(root -> data);
    traverse(root -> right, res);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    traverse(root, res);
    return res;
}