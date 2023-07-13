#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1=0,cnt2=0,n=arr.size();
    int ele1=-1,ele2=-1;
    for(int i=0;i<n;i++){
        if(cnt1==0 and arr[i] != ele2){
            cnt1++;
            ele1=arr[i];
        }
        else if(cnt2==0 and arr[i] != ele1){
            cnt2++;
            ele2=arr[i];
        }
        else if(arr[i]==ele1){
            cnt1++;
        }
        else if(arr[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> res;
    int cntElement1=0,cntElement2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ele1){
            cntElement1++;
        }
        else if(arr[i]==ele2){
            cntElement2++;
        }
    }
    int mini=n/3+1;
    if(cntElement1>=mini){
        res.push_back(ele1);
    }
    if(cntElement2>=mini){
        res.push_back(ele2);
    }
    sort(res.begin(),res.end());
    return res;
}