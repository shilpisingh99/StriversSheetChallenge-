#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value) {
  vector<long> prev(value + 1, 0), curr(value + 1, 0);

  for (int i = 0; i <= value; i++)
    prev[i] = value % denominations[0] == 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= value; j++) {
      long notTake = prev[j];
      long take = 0;
      if (denominations[i] <= j)
        take = curr[j - denominations[i]];

      curr[j] = take + notTake;
    }
    prev = curr;
  }

  return prev[value];
}