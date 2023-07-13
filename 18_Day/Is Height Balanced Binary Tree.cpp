pair<bool,int> solve(BinaryTreeNode<int>* root){
    if(!root) return {true, 0};
    pair<bool,int> left = solve(root->left);
    pair<bool,int> right = solve(root->right);

    pair<bool,int> res;
    res.first = abs(left.second-right.second)<=1 and left.first and right.first;
    res.second = max(left.second,right.second)+1;
    return res;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return solve(root).first;
}