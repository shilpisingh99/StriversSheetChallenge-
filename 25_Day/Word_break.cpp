#include <bits/stdc++.h>

bool solve(int ind, vector<string> &arr, int n, string &target, vector<int> &dp) {
    if (ind == n)
        return true;

    if (dp[ind] != -1)
        return dp[ind];

    for (auto word : arr)
        if (target.substr(ind, word.size()) == word and
            solve(ind + word.size(), arr, n, target, dp))
        return dp[ind] = true;

    return dp[ind] = false;
}

bool wordBreak(vector<string> &arr, int n, string &target) {
    vector<int> dp(target.size() + 1, -1);
    return solve(0, arr, target.size(), target, dp);
}