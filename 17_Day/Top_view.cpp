vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;
    if(!root) return res;
    
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        TreeNode<int>* node = front.first;
        int dis = front.second;
        if(!mp.count(dis)) mp[dis] = node -> val;
        q.pop();

        if(node -> left){
            q.push({node->left, dis - 1});
        }
        if(node -> right){
            q.push({node->right, dis + 1});
        }
    }
    for(auto &i:mp){
        res.push_back(i.second);
    }
    return res;
}