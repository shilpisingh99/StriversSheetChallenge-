#include <bits/stdc++.h> 

vector<int> nextSmallerElement(vector<int>& a, int n) {
    vector<int> res(n, n);
    stack<int> st;

    for(int i = n-1; i >=0 ; i--){
        while(!st.empty() and a[i] <= a[st.top()]) st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return res;
}

vector<int> prevSmallerElement(vector<int>& a, int n) {
    vector<int> res(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() and a[i] <= a[st.top()]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> nse = nextSmallerElement(a, n);
    vector<int> pse = prevSmallerElement(a, n);
    vector<int> res(n,INT_MIN);
    for(int i = 0; i < n; i++){
        int windowSize = nse[i] - pse[i] - 2;
        res[windowSize] = max(res[windowSize], a[i]);
    }
    for(int i = n-2 ; i >= 0; i--){
        res[i] = max(res[i], res[i+1]);
    }
    return res;
}