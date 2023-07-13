#include <bits/stdc++.h> 
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int element) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(element);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if(s1.empty()) return -1;
        int res=s1.top();
        s1.pop();
        return res;
    }

    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};
