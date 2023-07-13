#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int maxi = INT_MIN, pref = 1, suff = 1;
	for(int i = 0; i < n; i++){
		if(pref == 0) pref = 1;
		if(suff == 0) suff = 1;
		suff = suff * arr[n-i-1];
		pref = pref * arr[i];
		maxi = max(maxi, max(pref, suff));
	}
	return maxi;
}