
int floorInBST(TreeNode<int> * root, int X)
{
    int res = INT_MAX;
    while(root){
        if(!root->left){
            if(root->val <= X) res = root->val;
            root = root->right;
        }
        else{
            TreeNode<int>* pred = root->left;
            while(pred->right and pred->right != root){
                pred = pred->right;
            }
            if(pred->right){
                pred->right = NULL;
                if(root->val <= X) res = root->val;
                root = root->right;
            }
            else{
                pred->right = root;
                root = root->left;
            }
        }
    }
    return res;
}