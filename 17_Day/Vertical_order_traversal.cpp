#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if(!root) return {};

    vector<int> res;

    map<int,map<int,vector<int>>> mp;//mp[hd][lvl] => TreeNode<int>*

    queue<pair<int,pair<int,TreeNode<int>*>>> q;
    q.push({0,{0,root}});
    
    while(!q.empty()){
        auto front = q.front();
        int hd = front.first;
        int lvl = front.second.first;
        TreeNode<int>* node = front.second.second;
        q.pop();

        mp[hd][lvl].push_back(node->data);

        if(node->left){
            q.push({hd-1,{lvl+1,node->left}});
        }
        if(node->right){
            q.push({hd+1,{lvl+1,node->right}});
        }
    }
    for(auto &i:mp){
        for(auto &j:i.second){
            for(auto &k:j.second){
                res.push_back(k);
            }
        }
    }

    return res;
}