#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int source) {
    vector<pair<int,int>> adj[V];
    for(auto &i:vec){
        int u = i[0], v = i[1], w = i[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    dist[0] =  0;
    while(!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto &i:adj[node]){
            int adjNode = i.first;
            int weight = i.second;
            if(dist[adjNode] > dis + weight){
                dist[adjNode] = dis + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}