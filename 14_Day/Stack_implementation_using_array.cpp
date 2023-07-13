#include <bits/stdc++.h> 
// Stack class.
class Stack {

private:
    int *arr;
public:
    int size,front;
    Stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        front = -1;
    }

    void push(int num) {
        if(front == size - 1) return;
        front++;
        arr[front]=num;
    }

    int pop() {
        if(front == -1) return -1;
        int res = arr[front];
        front--;
        return res;
    }
    
    int top() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    int isEmpty() {
        return front == -1;
    }
    
    int isFull() {
        return front == size-1;
    }
    
};