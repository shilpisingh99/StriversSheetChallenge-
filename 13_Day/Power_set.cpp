#include <bits/stdc++.h> 
#define ll long long
vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> res;
    ll sz=1ll<<n;
    for(ll mask=0;mask<sz;mask++){
        vector<int> curr;
        for(ll i=0;i<n;i++){
            if((mask>>i)&1) curr.push_back(v[i]);
        }
        res.push_back(curr);
    }
    return res;
}