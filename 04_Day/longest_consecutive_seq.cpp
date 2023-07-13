#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int res=1,cntCurr=1,lastSmaller=INT_MIN;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastSmaller){
            lastSmaller=arr[i];
            cntCurr++;
        }
        else if(arr[i]==lastSmaller){
            continue;
        }
        else{
            res=max(res,cntCurr);
            cntCurr=1;
            lastSmaller=arr[i];
        }
    }
    return max(res,cntCurr);
}