#include <bits/stdc++.h> 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> nse(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top()>=arr[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(arr[i]);
    }
    return nse;
}