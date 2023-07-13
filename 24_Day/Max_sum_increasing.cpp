#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
	for(int i = n; i >= 1; i--){
		for(int j = n; j >= 0; j--){
			if(j == 0){
				dp[i][j] = max(rack[i-1] + dp[i+1][i], dp[i+1][j]);
			}
			else{
				dp[i][j] = dp[i+1][j];
				if(rack[j-1] < rack[i-1]){
					dp[i][j] = max(dp[i][j], rack[i-1] + dp[i+1][i]);
				}
			}
		}
	}
	return dp[1][0];
}