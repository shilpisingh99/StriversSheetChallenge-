#include <bits/stdc++.h>
using namespace std;
void swapIfGreater(vector<int>& arr1,vector<int>& arr2,int idx1,int idx2){
	if(arr1[idx1]>arr2[idx2]){
		swap(arr1[idx1],arr2[idx2]);
	}
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int len=m+n;
	int gap=(len+1)/2;
	while(gap>0){
		int left=0,right=gap;
		while(right<len){
			if(left<m and right>=m){
				swapIfGreater(arr1,arr2,left,right-m);
			}
			else if(left>=m){
				swapIfGreater(arr2,arr2,left-m,right-m);
			}
			else{
				swapIfGreater(arr1,arr1,left,right);
			}
			left++;
			right++;
		}
		if(gap==1) break;
		gap=(gap+1)/2;
	}
	for(int i=0;i<n;i++){
		arr1[i+m]=arr2[i];
	}
	return arr1;
}