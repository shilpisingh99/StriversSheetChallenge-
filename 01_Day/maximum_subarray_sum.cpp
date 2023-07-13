#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long maxi=0,currmax=0;
    for(int i=0;i<n;i++){
        currmax=max((long long)arr[i],arr[i]+currmax);
        maxi=max(maxi,currmax);
    }
    return maxi;
}