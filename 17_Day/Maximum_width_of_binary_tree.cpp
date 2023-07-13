int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;
    int res = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        res = max(sz, res);
        for(int i = 0; i < sz; i++){
            TreeNode<int>* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return res;
}