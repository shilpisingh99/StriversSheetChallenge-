#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vector<int> prev(m + 1, 0), curr(m + 1, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 and j == 0)
        curr[j] = grid[i][j];
      else {
        int up = 1e9, left = 1e9;
        if (i - 1 >= 0)
          up = grid[i][j] + prev[j];
        if (j - 1 >= 0)
          left = grid[i][j] + curr[j - 1];

        curr[j] = min(left, up);
      }
    }
    prev = curr;
  }

  return prev[m - 1];
}