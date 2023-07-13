#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
	vector<vector<int>> res;
	for(int i=0;i<n;i++){
		if(i !=0 and arr[i]==arr[i-1]) continue;
		int remsum=K-arr[i];
		int j=i+1,k=n-1;
		while(j<k){
			if(arr[j]+arr[k]==remsum){
				vector<int> triplet={arr[i],arr[j],arr[k]};
				res.push_back(triplet);
				while(j<n and triplet[1]==arr[j]) j++;
				while(k>=0 and triplet[2]==arr[k]) k--;
			}
			else if(arr[j]+arr[k]<remsum){
				j++;
			}
			else{
				k--;
			}
		}
	}
	return res;
}