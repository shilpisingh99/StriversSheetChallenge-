#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		int mini;
		stack<int> st;
		minStack() 
		{ 
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(st.empty()){
				mini = num;
				st.push(num);
			}
			else{
				if(num < mini){
					st.push(2 * num - mini);
					mini = num;
				}
				else{
					st.push(num);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			int res = -1;
			if(st.empty()) return res;
			if(st.top() < mini){
				res = mini;
				mini = 2 * mini - st.top();
				st.pop();
			}
			else{
				res = st.top();
				st.pop();
			}
			return res;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;
			if(st.top() < mini){
				return mini;
			}
			else{
				return st.top();
			}
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			return mini;
		}
};