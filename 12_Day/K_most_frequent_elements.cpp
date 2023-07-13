#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int j=i;
        while(j<n and arr[j]==curr){
            j++;
        }
        pq.push({j-i,curr});
        if(i != j) i=j-1;
    }
    vector<int> res;
    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(),res.end());
    return res;
}