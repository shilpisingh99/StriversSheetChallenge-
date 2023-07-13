#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int cnt=0,ele;
	for(int i=0;i<n;i++){
		if(cnt==0){
			cnt=1;
			ele=arr[i];
		}
		else if(arr[i]==ele){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	int cntele=0;
	for(int i=0;i<n;i++){
		cntele+=(arr[i]==ele);
	}
	return cntele>n/2?ele:-1;
}