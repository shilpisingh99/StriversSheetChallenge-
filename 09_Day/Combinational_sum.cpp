void fun(int idx,int sum,vector<int>& temp,vector<int>& arr,vector<vector<int>>& ds,int n){
    if(idx==n){
        if(sum==0){
            ds.push_back(temp);
        }
        return ;
    }
    //not pick
    fun(idx+1,sum,temp,arr,ds,n);
    //pick
    temp.push_back(arr[idx]);
    fun(idx+1,sum-arr[idx],temp,arr,ds,n);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ds;
    vector<int> temp;
    fun(0,k,temp,arr,ds,n);
    return ds;
}