#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    vector<int> res;
    map<int,int> mp;
    for(int j = 0, i = 0; j < n; j++){
        mp[arr[j]]++;
        while(j-i+1 > k){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        }
        if(j - i + 1 == k){
            res.push_back(mp.size());
        }
    }
    return res;
}
