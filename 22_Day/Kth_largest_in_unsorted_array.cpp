#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	sort(arr.begin(), arr.end(), greater<int>());
	return arr[K-1];
}