int NthRoot(int n, int m) {
  int low=0,high=m;
  while(low<=high){
    int mid=low+(high-low)/2;
    long long ans=1;
    for(int i=1;i<=n;i++){
      ans*=mid;
      if(ans>m) break;
    }
    if(ans==m){
      return mid;
    }
    else if(ans<m){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  return -1;
}