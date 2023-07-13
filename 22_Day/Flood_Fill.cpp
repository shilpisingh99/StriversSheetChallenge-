int delRow[] = {-1, 0, +1, 0};
int delCol[] = {0, +1, 0, -1};

void dfs(int row, int col, vector<vector<int>> & image, int oldColor, int newColor){
    image[row][col] = newColor;
    int m = image.size(), n = image[0].size();
    for(int i = 0; i < 4; i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and image[nrow][ncol] == oldColor){
            dfs(nrow, ncol, image, oldColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(image[x][y] == newColor) return image;
    dfs(x, y, image, image[x][y], newColor);
    return image;
}