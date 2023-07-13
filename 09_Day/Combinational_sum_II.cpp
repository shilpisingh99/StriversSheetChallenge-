#include <bits/stdc++.h>
void fun(int idx,int target,int n,vector<int>& temp,vector<vector<int>>& ds,vector<int>& arr){
    if(target==0){
        ds.push_back(temp);
        return ;
    }
    for(int i=idx;i<n;i++){
        if(arr[i]>target) break;
        if(i>idx and arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
        fun(i+1,target-arr[i],n,temp,ds,arr);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(),arr.end());
    vector<vector<int>> ds;
    vector<int> temp;
    fun(0,target,n,temp,ds,arr);
    return ds;
}