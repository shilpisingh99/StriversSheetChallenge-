#include <bits/stdc++.h> 
using namespace std;
/*
 Dutch National Flag Algorithm
<-----0s-----> <-------1s------>  <--Unsorted-->   <-------2s------>
 0       low-1 low         mid-1  mid        high  high+1        n-1
 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1  0 1 2 2 1 0 2 1  2 2 2 2 2 2 2 2 2
*/
void sort012(int *arr, int n)
{
   int low=0,mid=0,high=n-1;
   while(mid<=high){
       if(arr[mid]==0){
           swap(arr[low],arr[mid]);
           low++;
           mid++;
       }
       else if(arr[mid]==1){
           mid++;
       }
       else{
           swap(arr[high],arr[mid]);
           high--;
       }
   }
}