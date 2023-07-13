int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(mid%2==0){
			if(mid+1==n or mid==0){
				return arr[mid];
			}
			if(arr[mid+1]==arr[mid]){
				low=mid+1;
			}
			else if(arr[mid]==arr[mid-1]){
				high=mid-1;
			}
			else{
				return arr[mid];
			}
		}
		else{
			if(mid+1==n or mid==0){
				return arr[mid];
			}
			if(arr[mid] != arr[mid+1] and arr[mid] != arr[mid-1]){
				return arr[mid];
			}
			if(arr[mid]!=arr[mid+1]){
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
	}
	return -1;
}