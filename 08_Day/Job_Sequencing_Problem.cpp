#include <bits/stdc++.h> 

bool comp(vector<int>& a,vector<int>& b){
    return a[1]>b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    multiset<int> days;
    for(int i=1;i<=3000;i++){
        days.insert(i);
    }
    sort(jobs.begin(),jobs.end(),comp);
    int n=jobs.size(),res=0;
    for(int i=0;i<n;i++){
        int deadline=jobs[i][0];
        if(days.empty()) break;
        auto it=days.upper_bound(deadline);
        if(it==days.begin()) continue;
        --it;
        days.erase(it);
        res+=jobs[i][1];
    }
    return res;
}