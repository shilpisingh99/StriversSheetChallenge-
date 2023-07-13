int cutRod(vector<int> &price, int n) {
 vector<int> prev(n + 1), curr(n + 1);
  for (int i = 0; i <= n; i++)
    prev[i] = price[0] * i;

	for(int i = 1; i < n; i++) {
		for(int j=0;j<=n;j++) {
			int notTake = prev[j];
			int take = -1e9, rodlen = i + 1;
			if(rodlen <= j)
				take = price[i] + curr[j - rodlen];

			curr[j] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[n];
}