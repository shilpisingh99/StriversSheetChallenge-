
vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,BinaryTreeNode<int>*> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        BinaryTreeNode<int>* node = front.first;
        int dis = front.second;
        mp[dis] = node;
        q.pop();

        if(node -> left){
            q.push({node->left, dis - 1});
        }
        if(node -> right){
            q.push({node->right, dis + 1});
        }
    }
    vector<int> res;
    for(auto &i:mp){
        res.push_back(i.second->data);
    }
    return res;
}