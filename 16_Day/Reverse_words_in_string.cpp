#include <bits/stdc++.h>
string reverseString(string &str){
	int n = str.size();
	string res = "";
	stack<string> st;
	for(int i = 0; i < n; i++){
		if(str[i] == ' ') continue;
		string s="";
		while(i < n and str[i] != ' ') s+=str[i++];
		st.push(s);
	}
	while(st.size()){
		res += st.top();
		st.pop();
		res += " ";
	}
	res.pop_back();
	return res;
}