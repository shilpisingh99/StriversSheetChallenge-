#include <bits/stdc++.h> 
bool isPalindrome(string& s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

void fun(int idx,string& s,vector<string>& temp,vector<vector<string>>& ds){
    if(idx==s.size()){
        ds.push_back(temp);
        return ;
    }
    int n=s.size();
    for(int i=idx;i<n;i++){
        string str=s.substr(idx,i-idx+1);
        if(isPalindrome(str)){
            temp.push_back(str);
            fun(i+1,s,temp,ds);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<string> temp;
    vector<vector<string>> ds;
    fun(0,s,temp,ds);
    return ds;
}