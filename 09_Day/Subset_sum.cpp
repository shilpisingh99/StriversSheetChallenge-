#include <bits/stdc++.h> 
void fun(int idx,int sum,vector<int>& num,vector<int>& ds){
    if(idx==num.size()){
        ds.push_back(sum);
        return ;
    }
    fun(idx+1,sum,num,ds);
    fun(idx+1,sum+num[idx],num,ds);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ds;
    fun(0,0,num,ds);
    sort(ds.begin(),ds.end());
    return ds;
}