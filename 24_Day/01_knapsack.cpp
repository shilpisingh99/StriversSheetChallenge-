int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
	for(int i = n-1; i >= 0; i--){
		for(int j = 0 ; j <= w; j++){
			dp[i][j] = dp[i+1][j];
			if(weights[i] <= j){
				dp[i][j] = max(dp[i][j],values[i] + dp[i+1][j-weights[i]]);
			}
		}
	}
	return dp[0][w];
}