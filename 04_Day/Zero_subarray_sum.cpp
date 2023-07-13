#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n=arr.size();
    int res=(arr[0]==0);
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
        if(arr[i]==0) res=i+1;
    }
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
      if(mp.count(arr[i])){
        res=max(res,i-mp[arr[i]]);
      }
      else{
        mp[arr[i]]=i;
      }
    }
    return res;
}