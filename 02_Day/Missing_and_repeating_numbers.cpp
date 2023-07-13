#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xor_all=0;
	for(int i=1;i<=n;i++){
		xor_all=xor_all^arr[i-1]^i;
	}
	int bitNo=0;
	while(1){
		if((xor_all&(1<<bitNo)) != 0){
			break;
		}
		bitNo++;
	}
	int zero=0,one=0;
	for(int i=1;i<=n;i++){
		if((i&(1<<bitNo)) != 0){
			one^=i;
		}
		else{
			zero^=i;
		}
		if((arr[i-1]&(1<<bitNo)) != 0){
			one^=arr[i-1];
		}
		else{
			zero^=arr[i-1];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i]==zero) cnt++;
	}
	if(cnt==2) return {one,zero};
	else return {zero,one};
}