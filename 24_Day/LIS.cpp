#include <bits/stdc++.h>
int longestIncreasingSubsequence(int nums[], int n)
{
    vector<int> dp;
    dp.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        if(nums[i]>dp.back())
        {
            dp.push_back(nums[i]);
        }
        else{
            int idx=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[idx]=nums[i];
        }
    }
    return dp.size();
}
