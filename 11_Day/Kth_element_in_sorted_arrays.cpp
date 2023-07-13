#include <bits/stdc++.h>

int cntLowerThanOrEqualToMid(int mid,vector<int>& arr,int n){
    return upper_bound(arr.begin(),arr.end(),mid)-arr.begin();
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int low=0,high=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=cntLowerThanOrEqualToMid(mid,row1,m)+cntLowerThanOrEqualToMid(mid,row2,n);
        if(cnt<=k-1){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}