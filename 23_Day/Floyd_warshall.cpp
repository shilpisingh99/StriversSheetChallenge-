int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> matrix(n+1, vector<int> (n+1, 1e9));
    for(int i = 1; i <= n; i++){
        matrix[i][i] = 0;
    }

    for(auto &i:edges){
        int u = i[0];
        int v = i[1];
        int w = i[2];
        matrix[u][v] = w;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i][k] == 1e9 or matrix[k][j] == 1e9) continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }
    
    return (int)matrix[src][dest];
}