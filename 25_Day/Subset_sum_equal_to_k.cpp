#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<int> prev(k + 1, 0), curr(k + 1, 0);

  prev[0] = curr[0] = true;

  if (arr[0] <= k)
    prev[arr[0]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      int notTake = prev[j];
      int take = false;
      if (arr[i] <= j)
        take = prev[j - arr[i]];

      curr[j] = take or notTake;
    }
    prev = curr;
  }

  return prev[k];
}