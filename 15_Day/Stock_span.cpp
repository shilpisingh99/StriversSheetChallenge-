#include <bits/stdc++.h> 

vector<int> nextGreaterToTheRight(vector<int>& price){
    int n = price.size();
    stack<int> st;
    vector<int> res(n,-1);
    for(int i = 0; i < n; i++){
        
        while(!st.empty() and price[st.top()] <= price[i]) st.pop();

        res[i] = st.empty() ? -1:st.top();
        st.push(i);
    }

    return res;
}

vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    vector<int> res = nextGreaterToTheRight(price);
    for(int i = 0; i < n; i++){
        res[i] = (i - res[i]);
    }
    return res;
}