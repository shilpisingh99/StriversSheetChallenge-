#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int i=0,j=n-1;
    long leftMax=0,rightMax=0,res=0;
    while(i<j){
        if(arr[i]<arr[j]){
            leftMax=max(leftMax,arr[i]);
            res+=(leftMax-arr[i]);
            i++;
        }
        else if(arr[i]>arr[j]){
            rightMax=max(rightMax,arr[j]);
            res+=(rightMax-arr[j]);
            j--;
        }
        else{
            leftMax=max(leftMax,arr[i]);
            rightMax=max(rightMax,arr[j]);
            i++;
        }
    }
    return res;
}