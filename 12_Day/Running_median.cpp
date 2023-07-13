#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;

    for(int i=0;i<n;i++){
        if(maxh.empty() || maxh.top()>=arr[i]) maxh.push(arr[i]);
        else minh.push(arr[i]);

        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }

        if(minh.size()<maxh.size()) cout<<maxh.top()<<" ";
        else cout<<(minh.top()+maxh.top())/2<<" ";
    }

}