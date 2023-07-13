TreeNode<int>* solve(int low, int high, vector<int>& arr, TreeNode<int>* root) {
    if(low > high) return NULL;
    int mid = low + (high - low)/2;
    root = new TreeNode<int>(arr[mid]);
    root->left = solve(low, mid-1, arr, root);
    root->right = solve(mid+1, high, arr, root);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    TreeNode<int>* root = NULL;
    return solve(0, n-1, arr, root);
}