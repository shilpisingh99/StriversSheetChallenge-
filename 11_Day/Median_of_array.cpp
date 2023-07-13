#include<bits/stdc++.h>
int cntSmallerThanOrEqualMid(vector<int>& arr,int mid){
    return upper_bound(arr.begin(),arr.end(),mid)-arr.begin();
}
int getMedian(vector<vector<int>> &matrix)
{
    int m=matrix.size(),n=matrix[0].size();
    int low=1,high=1e5+10;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<m;i++){
            cnt+=cntSmallerThanOrEqualMid(matrix[i],mid);
        }
        if(cnt<=(m*n)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}