#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(auto i:g){
        adj[i.first.first-1].push_back({i.first.second-1,i.second});
        adj[i.first.second-1].push_back({i.first.first-1,i.second});
    }
    vector<pair<pair<int, int>, int>> ans;
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>q;
    vector<int>vis(n,0);
    q.push({0,{0,-1}});
    while(!q.empty()){
        int wt=q.top().first;
        int fnode=q.top().second.first;
        int par=q.top().second.second;
        q.pop();
        if(vis[fnode]==1)continue;
        vis[fnode]=1;
        if(par!=-1){
            ans.push_back({{fnode+1,par+1},wt});
        }
        for(auto i:adj[fnode]){
            int anode=i.first;
            int awt=i.second;
            if(!vis[anode]){
                q.push({awt,{anode,fnode}});
            }
        }
    }
    return ans;
}