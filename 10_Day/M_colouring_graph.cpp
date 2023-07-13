#include <bits/stdc++.h> 

bool isValid(int node,int col,int color[],vector<vector<int>>& mat,int V){
    for(int i=0;i<V;i++){
        if(i != node and mat[i][node] and color[i] == col) return false;
    }
    return true;
}

bool solve(int node,int color[],int m,vector<vector<int>>& mat,int V){
    if(node==V) return true;
    for(int col=1;col<=m;col++){
        if(isValid(node,col,color,mat,V)){
            color[node]=col;
            if(solve(node+1,color,m,mat,V)==true){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int V=mat.size();
    int color[V];
    memset(color,0,sizeof(color));
    return solve(0,color,m,mat,V)?"YES":"NO";
}