#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0,bottom=n-1,left=0,right=m-1;
    while(top<bottom and left<right){
        int temp=mat[top][left];
        for(int i=top+1;i<=bottom;i++){
            mat[i-1][left]=mat[i][left];
        }
        for(int i=left;i<right;i++){
            mat[bottom][i]=mat[bottom][i+1];
        }
        for(int i=bottom;i>top;i--){
            mat[i][right]=mat[i-1][right];
        }
        for(int i=right;i>=left+2;i--){
            mat[top][i]=mat[top][i-1];
        }
        mat[top][left+1]=temp;
        top++;
        left++;
        right--;
        bottom--;
    }

}