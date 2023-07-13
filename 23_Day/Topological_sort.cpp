#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    vector<int> indegree(v, 0), res;
    for(auto &i:edges){
        int u = i[0], v = i[1];
        indegree[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int frontNode = q.front();
        res.push_back(frontNode);
        q.pop();
        for(auto &i: adj[frontNode]){
            indegree[i]--;
            if(indegree[i] == 0) q.push(i);
        }
    }
    return res;
}