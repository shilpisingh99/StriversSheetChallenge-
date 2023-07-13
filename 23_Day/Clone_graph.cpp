#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<Node*, Node*> mp;
    Node* dfs(Node* node){
        vector<Node*> neighbors;
        Node* curr = new Node(node->val);
        mp[node] = curr;
        for(auto &i:node->neighbors){
            if(mp.find(i) == mp.end()){
                neighbors.push_back(dfs(i));
            }
            else{
                neighbors.push_back(mp[i]);
            }
        }
        curr->neighbors = neighbors;
        return curr;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0) 
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node);
    }
};
int main()
{
    return 0;
}