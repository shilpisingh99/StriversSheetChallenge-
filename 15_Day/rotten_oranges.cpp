#include <bits/stdc++.h>
int delRow[] = {-1,0,+1,0};
int delCol[] = {0,+1,0,-1};
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,int>> q;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
            }
            if(grid[i][j] == 1){
                cnt++;
            }
        }
    }
    int lvl = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                    cnt--;
                }
            }
        }
        lvl++;
    }
    return cnt !=0 ? -1 : max(0,lvl - 1);
}