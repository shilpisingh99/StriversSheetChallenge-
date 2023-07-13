
void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            auto front = q.front();
            q.pop();
            if(i != sz-1)front->next = q.front();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right); 
        }
    }
}