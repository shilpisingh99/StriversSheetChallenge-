#include <bits/stdc++.h> 

class Node{
    public:
    int height;
    int leftIdx;
    int rightIdx;
    
    Node(int height, int leftIdx, int rightIdx){
        this->height = height;
        this->leftIdx = leftIdx;
        this->rightIdx = rightIdx;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int,int> mp;
    for(int i = 0; i < N; i++){
        mp[inorder[i]] = i;
    }
	queue<Node*> q;
    q.push(new Node(0, 0, N-1));
    int idx = 0, res = 0;
    while(!q.empty()){
        Node* frontNode = q.front();
        int height = frontNode->height;
        int leftIdx = frontNode->leftIdx;
        int rightIdx = frontNode->rightIdx;
        res = max(res, height);
        q.pop();
        
        int j = mp[levelOrder[idx]];
        if(j-1 >= leftIdx){
            q.push(new Node(height+1, leftIdx, j-1));
        }
        if(j+1 <= rightIdx){
            q.push(new Node(height+1, j+1, rightIdx));
        }
        idx++;
    }
    return res;
}