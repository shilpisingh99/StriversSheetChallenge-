#include <bits/stdc++.h> 

int dp[100][100];
int fun(int i, int j, vector<int> &arr, int N){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + fun(i, k, arr, N) + fun(k+1, j, arr, N);
        mini = min(steps, mini);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp, -1, sizeof(dp));
    return fun(1, N-1, arr, N);
}