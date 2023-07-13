#include <bits/stdc++.h> 
bool comp(pair<int,int> &a,pair<int,int>& b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size();
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.push_back({end[i],i});
    }
    sort(vec.begin(),vec.end(),comp);
    vector<int> res;
    int prevEnd=-1;
    for(int i=0;i<n;i++){
        int currStart=start[vec[i].second];
        int currEnd=vec[i].first;
        if(currStart>prevEnd){
            res.push_back(vec[i].second+1);
            prevEnd=currEnd;
        }
    }
    return res;
}