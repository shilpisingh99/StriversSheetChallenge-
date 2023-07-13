#include <bits/stdc++.h> 

void solve(int idx,int n,vector<string>& words,string& s,unordered_map<string,bool>& mp,vector<string>& ds){
    if(idx==n){
        string res="";
        int sz=words.size();
        for(int i=0;i<sz;i++){
            res+=words[i];
            if(i != sz-1) res+=' ';
        }
        ds.push_back(res);
        return ;
    }
    string str="";
    for(int i=idx;i<n;i++){
        str+=s[i];
        if(mp.find(str) != mp.end()){
            words.push_back(str);
            solve(i+1,n,words,s,mp,ds);
            words.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<string,bool> mp;
    for(auto &word:dictionary){
        mp[word]=true;
    }
    vector<string> ds,words;
    solve(0,(int)s.size(),words,s,mp,ds);
    return ds;
}