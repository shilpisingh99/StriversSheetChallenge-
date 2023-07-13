#include <bits/stdc++.h> 

int delRow[]={-1,0,+1,0};
int delCol[]={0,+1,0,-1};

void solve(int row,int col,int n,vector<vector<int>>& path,vector<vector<int>>& maze,vector<vector<int>>& res){
  path[row][col]=1;
  if(row==n-1 and col==n-1){
    vector<int> currPath;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        currPath.push_back(path[i][j]);
      }
    }
    res.push_back(currPath);
    path[row][col]=0;
    return ;
  }
  for(int i=0;i<4;i++){
    int nrow=row+delRow[i];
    int ncol=col+delCol[i];
    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !path[nrow][ncol] and maze[nrow][ncol]){
      solve(nrow,ncol,n,path,maze,res);
    }
  }
  path[row][col]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> res,path(n,vector<int>(n,0));
  solve(0,0,n,path,maze,res);
  return res;
}