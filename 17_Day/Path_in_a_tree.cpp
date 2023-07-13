void solve(TreeNode<int>* root, int x,vector<int>& ds,vector<int>& res){
	if(!root) return ;
	if(root->data == x){
		res = ds;
		res.push_back(root->data);
		return ;
	}
	ds.push_back(root->data);
	solve(root->left, x, ds, res);
	solve(root->right, x, ds, res);
	ds.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res, ds;
	solve(root, x, ds, res);
	return res;
}