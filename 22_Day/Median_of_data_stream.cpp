#include <bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return minHeap.top()/2.0 + maxHeap.top()/2.0;
        }
        else{
            if(minHeap.size() > maxHeap.size()) return minHeap.top();
            else return maxHeap.top();
        }
    }
};
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> res(n, -1);
	MedianFinder obj;
	for(int i = 0; i < n; i++){
		obj.addNum(arr[i]);
		res[i] = obj.findMedian();
	}
	return res;
}