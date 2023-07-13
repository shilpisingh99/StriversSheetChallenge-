#include <bits/stdc++.h>
bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.push_back({start[i],finish[i]});
    }
    sort(vec.begin(),vec.end(),comp);
    int res=0,prevEnd=0;
    for(int i=0;i<n;i++){
        int startTime=vec[i].first;
        int endTime=vec[i].second;
        if(startTime>=prevEnd){
            res++;
            prevEnd=endTime;
        }
    }
    return res;
}