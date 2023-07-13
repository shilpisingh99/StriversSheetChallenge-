#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int n=arr.size();
    unordered_map<int,int> mp;
    int xr=0,cnt=0;
    mp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        int x=xr^k;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}