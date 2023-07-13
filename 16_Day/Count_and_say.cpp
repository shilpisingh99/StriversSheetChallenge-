#include <bits/stdc++.h> 

string countAndSay(string &s){
	int n = s.size();
	string res = "";
	for(int i = 0; i < n; i++){
		int j = i;
		while(j < n and s[i] == s[j]) j++;
		j--;
		res+=(j-i+1+'0');
		res+=s[i];
		if(i != j) i = j;
	}
	return res;
}
string solve(int n){
	if(n == 1) return "1";

	string res = solve(n-1);
	return countAndSay(res);
}
string writeAsYouSpeak(int n) 
{
	return solve(n);
}