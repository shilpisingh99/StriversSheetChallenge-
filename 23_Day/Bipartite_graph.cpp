bool checkBipartite(int node, int col, vector<int>& color, vector<int> adj[]){
    color[node] = col;
    for(auto &i:adj[node]){
        if (color[i] == -1) {
            if (checkBipartite(i, !col, color, adj) == false) {
                return false;
            }
        }
        else if (color[i] == col){
            return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
	vector<int> adj[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edges[i][j]){
                int u = i, v = j;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(checkBipartite(i, 0, color, adj) == false) return false;
        }
    }
    return true;
}