#include <bits/stdc++.h> 
void fun(int idx,vector<int>& temp,vector<int>& arr,set<vector<int>>& res){
    if(idx==arr.size()){
        res.insert(temp);
        return ;
    }
    //not pick
    fun(idx+1,temp,arr,res);
    //pick
    temp.push_back(arr[idx]);
    fun(idx+1,temp,arr,res);
    temp.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    vector<int> temp;
    set<vector<int>> res;
    fun(0,temp,arr,res);
    vector<vector<int>> ans(res.begin(),res.end());
    return ans;
}