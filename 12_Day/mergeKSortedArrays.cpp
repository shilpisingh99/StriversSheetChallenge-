#include <bits/stdc++.h> 
vector<int> solve(vector<int>& a,vector<int>& b){
    int n=a.size(),m=b.size();
    vector<int> res(n+m,0);
    int i=0,j=0,k=0;
    while(i<n and j<m){
        if(a[i]<=b[j]){
            res[k++]=a[i++];
        }
        else{
            res[k++]=b[j++];
        }
    }
    while(i<n) res[k++]=a[i++];
    while(j<m) res[k++]=b[j++];
    return res;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> res=kArrays[0];
    for(int i=1;i<k;i++){
        res=solve(res,kArrays[i]);
    }
    return res;
}