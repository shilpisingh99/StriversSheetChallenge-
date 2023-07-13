#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
static bool comp(vector<int>& a,vector<int>& b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n=intervals.size();
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end(),comp);
    int i=0;
    while(i<n){
        int j=i+1;
        int start=intervals[i][0],end=intervals[i][1];
        while(j<n and end>=intervals[j][0]){
            end=max(end,intervals[j][1]);
            j++;
        }
        res.push_back({start,end});
        i=j;
    }
    return res;
}
