vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root) return {};

    vector<int> res;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        res.push_back(node->val);
        q.pop();

        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
    
    return res;
}