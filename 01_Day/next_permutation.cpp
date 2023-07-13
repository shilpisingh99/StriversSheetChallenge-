#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    for(int i=n-1;i>idx;i--){
        if(permutation[i]>permutation[idx]){
            swap(permutation[i],permutation[idx]);
            break;
        }
    }
    reverse(permutation.begin()+idx+1,permutation.end());
    return permutation;
}