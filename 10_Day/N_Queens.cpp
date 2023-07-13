#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

bool isPossible(int row,int col,int n,vector<vector<int>>& board){
    for(int i=0;i<n;i++){
        if(board[row][i]) return false;
    }
    for(int i=0;i<n;i++){
        if(board[i][col]) return false;
    }
    int i=row,j=col;
    while(i>=0 and j>=0){
        if(board[i][j]) return false;
        i--;
        j--;
    }
    i=row,j=col;
    while(i<n and j<n){
        if(board[i][j]) return false;
        i++;
        j++;
    }
    i=row,j=col;
    while(i>=0 and j<n){
        if(board[i][j]) return false;
        i--;
        j++;
    }
    i=row,j=col;
    while(i<n and j>=0){
        if(board[i][j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int col,int n,vector<vector<int>>& board,vector<vector<int>>& res){
    if(col==n){
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans.push_back(board[i][j]);
            }
        }
        res.push_back(ans);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isPossible(row,col,n,board)){
            board[row][col]=1;
            solve(col+1,n,board,res);
            board[row][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> res,board(n,vector<int>(n,0));
    solve(0,n,board,res);
    return res;
}

int main()
{
fast;
int n;
cin>>n;
vector<vector<int>> res=solveNQueens(n);
for(auto &i:res){
    for(auto &j:i){
        cout<<j<<" ";
    }
    cout<<endl;
}
return 0;
}