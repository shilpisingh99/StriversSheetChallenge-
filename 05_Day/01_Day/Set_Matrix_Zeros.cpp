#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	vector<int> rows(n,0),cols(m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				rows[i]++;
				cols[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(rows[i] or cols[j]){
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
}