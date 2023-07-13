#include <bits/stdc++.h>  

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<int> adj_list[vertex];
    for(int i= 0; i < edges.size(); i++){
        adj_list[edges[i].first].push_back(edges[i].second);
        adj_list[edges[i].second].push_back(edges[i].first);
    }
// since in test case we want output in lexicographically order
    for(int i = 0; i < vertex; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    vector<int> ans;
    vector<int> vis(vertex, 0);
    for(int i = 0; i < vertex ; i++){
        queue<int> q;
        if(vis[i] == 0){
            vis[i] = 1;
            q.push(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                ans.push_back(top);
                for(auto it: adj_list[top]){     
                    if(vis[it] == 0){
                        q.push(it);
                        vis[it] = 1;
                    } 
                }
            }
        }
    }
    return ans;
}