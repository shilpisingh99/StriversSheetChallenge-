#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> res;
    for(int i=1;i<=N;i++){
        vector<int> currRow(i,1);
        if(i==1){
            res.push_back(currRow);
            continue;
        }
        vector<int> prevRow=res[res.size()-1];
        for(int j=1;j<i-1;j++){
            currRow[j]=prevRow[j]+prevRow[j-1];
        }
        res.push_back(currRow);
    }
    return res;
}