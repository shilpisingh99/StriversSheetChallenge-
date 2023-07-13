#include<bits/stdc++.h>
int maxValue(int ind,vector<int>values,vector<int>weights,int wt,vector<vector<int>>&dp){

	if(ind==0){
		if(weights[ind]<=wt)return values[ind];
		else return 0;
	}
	if(dp[ind][wt]!=-1) return dp[ind][wt];
	
	int notTake=maxValue(ind-1,values,weights,wt,dp);
	int take=0;
	if(weights[ind]<=wt){
		take=values[ind]+maxValue(ind-1,values,weights,wt-weights[ind],dp);
	}

	return dp[ind][wt]= max(notTake,take);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int maxi=INT_MIN;
	for(auto x:weights)maxi=max(maxi,x);
	vector<vector<int>>dp(n+1,vector<int>(1001,0));
	// return maxValue(n-1,values,weights,w,dp);
	
	for(int i=0;i<=weights[0];i++){
			dp[0][i]=values[0];
	}
	
	for(int ind=1;ind<n;ind++){
		for(int wt=0;wt<=1000;wt++){

			int notTake=dp[ind-1][wt];
			int take=INT_MIN;
			if(weights[ind]<=wt){
				take=values[ind]+dp[ind-1][wt-weights[ind]];
			}
			dp[ind][wt]= max(notTake,take);
		}
	}
	return dp[n-1][w];

}