string longestCommonPrefix(vector<string> &arr, int n)
{
    int m = arr[0].size();
    for(int i = 0; i < n; i++) m = min(m, (int)arr[i].size());

    string res = "";
    for(int i = 0;i < m; i++){
        char ch = arr[0][i];
        for(int j = 0; j < n; j++){
            if(ch != arr[j][i]) return res;
        }
        res += ch;
    }
    return res;
}
