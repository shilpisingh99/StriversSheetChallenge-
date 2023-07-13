#include <bits/stdc++.h> 
bool comp(pair<int,int>& a,pair<int,int>& b){
    double r1=(double)a.second/(double)a.first;
    double r2=(double)b.second/(double)b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);
    double maxProfit=0;
    for(int i=0;i<n;i++){
        if(w>=items[i].first){
            w-=items[i].first;
            maxProfit+=items[i].second;
        }
        else{
            maxProfit+=((double)items[i].second*w/(double)items[i].first);
            break;
        }
    }
    return maxProfit;
}