#include <bits/stdc++.h> 

bool Predicate(int gap,vector<int> positions,int n,int c){
	int players=1,prev=positions[0];
	for(int i=1;i<n;i++){
		if(positions[i]>=prev+gap){
			players++;
			prev=positions[i];
		}
	}
	return players>=c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int low=1,high=1e9,res=1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(Predicate(mid,positions,n,c)){
			low=mid+1;
			res=mid;
		}
		else{
			high=mid-1;
		}
	}
	return res;
}