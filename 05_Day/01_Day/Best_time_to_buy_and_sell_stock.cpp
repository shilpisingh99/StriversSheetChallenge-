#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int mini=INT_MAX,res=0;
    for(auto& i:prices){
        mini=min(i,mini);
        res=max(res,i-mini);
    }
    return res;
}