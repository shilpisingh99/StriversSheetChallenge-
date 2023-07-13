const int mod = 1e9 + 7;
const int pr = 37;
vector<int> stringMatch(string text, string pattern) {
	int n = pattern.size();
	long dhv = 0, pow = 1;
	for(int i = 0; i < n; i++){
		dhv = (dhv + (pattern[i] - 'a' + 1)*pow) % mod;
		pow = (pow * pr) % mod;
	}
	int m = text.size();
	long dp[m],powr[m];
	powr[0] = 1;
	pow = 1;
	for(int i = 0; i < m; i++){
		dp[i] = ((text[i] - 'a' + 1)*pow) % mod;
		if(i) dp[i] = (dp[i] + dp[i-1]) % mod;
		powr[i] = pow;
		pow = (pow * pr) % mod;
	}
	vector<int> res;
	for(int i = 0; i + n -1 < m; i++){
		int j = i + n - 1;
		long currhv = dp[j];
		if(i) currhv -= dp[i-1];
		currhv = (currhv + mod) % mod;
		if(currhv == (dhv * powr[i]) % mod) res.push_back(i+1);
	}
	return res;
}
