#include <bits/stdc++.h>
void dfs1(int node, vector<int> adj[], stack<int>& st, vector<int>& isVisited){
    isVisited[node] = 1;
    for(auto &i:adj[node]){
        if(isVisited[i]) continue;
        dfs1(i, adj, st, isVisited);
    }
    st.push(node);
}

void dfs2(int node, vector<int> adjT[], vector<int>& isVisited, vector<int>& curr){
    isVisited[node] = 1;
    curr.push_back(node);
    for(auto &i:adjT[node]){
        if(isVisited[i]) continue;
        dfs2(i, adjT, isVisited, curr);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    stack<int> st;
    vector<int> adj[n];
    vector<int> isVisited(n, 0);

    for(auto &i:edges){
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++){
        if(!isVisited[i]){
            dfs1(i, adj, st, isVisited);
        }
    }

    vector<int> adjT[n];
    for(int i = 0; i < n; i++){
        isVisited[i] = 0;
    }

    for(auto &i:edges){
        int u = i[0], v = i[1];
        adjT[v].push_back(u);
    }

    vector<vector<int>> res;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int> curr;
        if (!isVisited[node]) {
            dfs2(node, adjT, isVisited, curr);
            res.push_back(curr);
        }
    }

    return res;
}