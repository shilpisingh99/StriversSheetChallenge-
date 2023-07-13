#include <bits/stdc++.h>

string longestPalinSubstring(string str)
{
    int n = str.size();
    bool isPalindrome[n][n];
    memset(isPalindrome,false,sizeof(isPalindrome));

    int low = 0, high = 0;
    for(int gap = 0; gap < n; gap++){
        for(int i = 0; i < n; i++){
            int j = gap + i;
            if(j >= n) continue;
            if(gap == 0){
                isPalindrome[i][j] = true;
            }
            else if(gap == 1){
                isPalindrome[i][j] = (str[i] == str[j]);
            }
            else{
                isPalindrome[i][j] = (str[i] == str[j]) and isPalindrome[i+1][j-1];
            }
            if(isPalindrome[i][j]){
                if(high - low < gap ){
                    low = i, high = j;
                }
            }
        }
    }
    return str.substr(low,high-low+1);
}