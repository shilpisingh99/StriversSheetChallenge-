#include <bits/stdc++.h>

 vector<int> nextSmallerElementLeft(vector<int>& heights){
   int n = heights.size();
   vector<int> res(n, -1);
   stack<int> st;
   for(int i = 0; i <n; i++){
      while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
      res[i] = st.empty() ? -1 : st.top();
      st.push(i);
   }
   return res;
 }

  vector<int> nextSmallerElementRight(vector<int>& heights){
   int n = heights.size();
   vector<int> res(n, n);
   stack<int> st;
   for(int i = n-1; i >= 0; i--){
      while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
      res[i] = st.empty() ? n : st.top();
      st.push(i);
   }
   return res;
 }

 int largestRectangle(vector < int > & heights) {
   int n = heights.size();
   vector<int> left = nextSmallerElementLeft(heights);
   vector<int> right = nextSmallerElementRight(heights); 
   int res = 0;
   for(int i = 0; i < n; i++){
     res = max( res, heights[i] * (right[i] - left[i] -1) );
   }
   return res;
 }