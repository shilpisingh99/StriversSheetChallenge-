#include <bits/stdc++.h> 
void solve(int idx,int n,string& s,vector<string>& ds){
    if(idx==n){
        ds.push_back(s);
        return ;
    }
    for(int i=idx;i<n;i++){
        swap(s[i],s[idx]);
        solve(idx+1,n,s,ds);
        swap(s[i],s[idx]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ds;
    solve(0,s.size(),s,ds);
    return ds;
}