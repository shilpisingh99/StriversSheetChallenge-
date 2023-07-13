#include <bits/stdc++.h> 
class Kthlargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
       this->k = k;
       for(int i = 0; i < arr.size(); i++){
           pq.push(arr[i]);
       }
    }

    void add(int num) {
        pq.push(num);
        while(pq.size() > k) pq.pop();
    }

    int getKthLargest() {
        return pq.top();
    }

};