#include <bits/stdc++.h>

void dfs(int node, vector<int> adj[], vector<bool>& isVisited ,vector<int> &res)
{
    res.push_back(node);
    isVisited[node] = true;
    for(auto &i:adj[node])
    {
        if(isVisited[i]) continue;
        dfs(i, adj, isVisited, res);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> res;
    vector<int> adj[V];
    for(auto &it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<bool> isVisited(V+1, false);
    for(int i = 0; i < V; i++)
    {
        if(!isVisited[i])
        {
            vector<int> curr;
            dfs(i, adj, isVisited, curr);
            res.push_back(curr);
        }
    }
    return res;
}