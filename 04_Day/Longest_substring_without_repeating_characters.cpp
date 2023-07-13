#include <bits/stdc++.h> 
int freq[26];
bool isValid(char ch){
    return (freq[ch-'a']==0);
}
int uniqueSubstrings(string input)
{
    for(int i=0;i<26;i++){
        freq[i]=0;
    }
    int n=input.size(),res=1;
    int i=0;
    for(int j=0;j<n;j++){
        char ch=input[j];
        if(isValid(ch)){
            freq[ch-'a']++;
            res=max(res,j-i+1);
        }
        else{
            while(i<=j and !isValid(ch)){
                freq[input[i]-'a']--;
                i++;
            }
            freq[ch-'a']++;
        }
    }
    return res;
}