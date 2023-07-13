int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, m+n));
    for(int i = 0; i <= n; i++){
        dp[i][m] = n - i;
    }
    for(int i = 0; i <= m; i++){
        dp[n][i] = m - i;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i+1][j],dp[i][j+1]);
                dp[i][j] = min(dp[i][j], 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1])));
            }
        }
    }
    return dp[0][0];
}