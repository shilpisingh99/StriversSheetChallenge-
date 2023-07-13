int delRow[] = {-1, 0, +1, 0, -1, +1, -1, +1};
int delCol[] = {0, +1, 0, -1, +1, +1, -1, -1};

void dfs(int row, int col, int n, int m, vector<vector<bool>>& isVisited, int** arr){
   isVisited[row][col] = true;
   for(int i = 0; i < 8; i++){
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];
      if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !isVisited[nrow][ncol] and arr[nrow][ncol]){
         dfs(nrow, ncol, n, m, isVisited, arr);
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<bool>> isVisited(n, vector<bool> (m, 0));
   int res = 0;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(!isVisited[i][j] and arr[i][j]){
            res++;
            dfs(i, j, n, m, isVisited, arr);
         }
      }
   }

   return res;
}
