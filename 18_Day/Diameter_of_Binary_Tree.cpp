int solve(TreeNode<int>* root,int& res){
    if(!root) return 0;
    int left = solve(root->left, res);
    int right = solve(root->right, res);
    res = max( res, max(left + right + 1, max(left, right) + 1));
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int res = 0;
    solve(root, res);
	return res - 1;
}