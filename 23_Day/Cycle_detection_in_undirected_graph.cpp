bool dfs(int node, int parent, vector<int> adj[], vector<bool>& isVisited){
    isVisited[node] = true;
    for(auto &i:adj[node]){
        if(i == parent) continue;
        if(!isVisited[i]){
            if(dfs(i, node, adj, isVisited)) return true;
        }
        else{
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    vector<bool> isVisited(n+1, false);
    for(auto &i:edges){
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!isVisited[i]){
            if(dfs(i, -1, adj, isVisited)) return "Yes";
        }
    }
    return "No";
}