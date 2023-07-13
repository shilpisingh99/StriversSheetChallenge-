#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> res;
   int n=arr.size();
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++){
      int remsum=s-arr[i];
      if(mp.count(remsum)){
         int cnt=mp[remsum];
         while(cnt--){
            if(remsum<=arr[i])
               res.push_back({remsum,arr[i]});
            else
               res.push_back({arr[i],remsum});
         }
      }
      mp[arr[i]]++;
   }
   sort(res.begin(),res.end());
   return res;
}