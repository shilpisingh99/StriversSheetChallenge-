bool dfs(int node, vector<int> adj[], vector<int>& isVisited){
    isVisited[node] = 2;
    for(auto &i:adj[node]){
        if(isVisited[i] == 0){
            if(dfs(i, adj, isVisited)) return true;
        }
        else if(isVisited[i] == 1){
           continue;
        }
        else{
            return true;
        }
    }
    isVisited[node] = 1;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(auto &i:edges){
        int u = i.first, v = i.second;
        adj[u].push_back(v);
    }
    vector<int> isVisited(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(!isVisited[i]){
            if(dfs(i, adj, isVisited)) return true;
        }
    }
    return false;
}