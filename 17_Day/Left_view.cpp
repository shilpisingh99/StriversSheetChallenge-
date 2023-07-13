void solve(TreeNode<int>* root,int lvl, vector<int>& ans){
    if(!root) return ;
    if(ans.size() == lvl){
        ans.push_back(root -> data);
    }
    solve(root->left,lvl+1,ans);
    solve(root->right,lvl+1,ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}