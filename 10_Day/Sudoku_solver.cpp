bool isValid(int row,int col,int board[9][9],int ch){
    for(int i=0;i<9;i++){
        if(board[row][i]==ch) return false;
        if(board[i][col]==ch) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
    }
    return true;
}

bool solve(int board[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int ch=1;ch<=9;ch++){
                    if(isValid(i,j,board,ch)){
                        board[i][j]=ch;
                        if(solve(board)==true){
                            return true;
                        }
                        else{
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int board[9][9]) {
    return solve(board);
}