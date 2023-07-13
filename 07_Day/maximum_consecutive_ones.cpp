int longestSubSeg(vector<int> &arr , int n, int k){
    int res=0,j=0,cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt++;
        while(cnt>k){
            if(arr[j]==0){
                cnt--;
            }
            j++;
        }
        res=max(res,i-j+1);
    }
    return res;
}