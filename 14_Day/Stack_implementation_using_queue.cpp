#include <bits/stdc++.h> 
class Stack {
	

   public:
    queue<int> q;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        int sz=q.size();
        q.push(element);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) return -1;
        int res=q.front();
        q.pop();
        return res;
    }

    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
};