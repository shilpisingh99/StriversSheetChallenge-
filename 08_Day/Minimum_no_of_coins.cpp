#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int res=0;
    for(int i=8;i>=0;i--){
        res+=amount/coins[i];
        amount%=coins[i];
    }
    return res;
}