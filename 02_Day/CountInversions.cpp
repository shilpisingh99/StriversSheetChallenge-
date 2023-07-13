#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int mergeSortedArray(long long *arr,int s,int e){
    int mid=s+(e-s)/2;
    vector<long long> newArr;
    int i=s,j=mid+1;
    int cnt=0;
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j]){
            newArr.push_back(arr[i++]);
        }
        else{
            newArr.push_back(arr[j++]);
            cnt+=(mid-i+1);
        }
    }
    while(i<=mid){
        newArr.push_back(arr[i++]);
    }
    while(j<=e){
        newArr.push_back(arr[j++]);
    }
    for(int i=s;i<=e;i++){
        arr[i]=newArr[i-s];
    }
    return cnt;
}

int mergeSort(long long* arr,int s,int e,int n){
    if(s>=e) return 0;
    int mid=s+(e-s)/2;
    int cnt=0;
    cnt+=mergeSort(arr,s,mid,n);
    cnt+=mergeSort(arr,mid+1,e,n);
    cnt+=mergeSortedArray(arr,s,e);
    return cnt;
}
