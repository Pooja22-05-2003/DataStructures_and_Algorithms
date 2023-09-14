/*
Problem Link :https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

//  ceil is same as lowe bound in the array 
//  TC=O(nlogn)
//  sc=O(1)
int ceil(int arr[], int n, int x){
	int st=0;
	int end=n-1;
	int ans=-1;

	while(st<=end){
		int mid=(st+end)/2;
		if(arr[mid]>=x){

			//  ⚠️⚠️here u need to return the ans and not index, read questions carefully
			ans=arr[mid];
			// st=mid+1; ❌
			//  isme smallest element find karna hai which is greater then x, so smallest ke liye 
			//  tumhe end ko mid-1 karna padega
			end=mid-1;
		}
		else {
			// end=mid-1;
			st=mid+1;
		}

	
	}

	return ans;
}


int floor(int arr[], int n, int x){
	int st=0;
	int end=n-1;
	int ans=-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(arr[mid]<=x){
			ans=arr[mid];
			// end=mid-1;❌
			//  floor mei greatest element u need to find , which is smallest then the mid el
			st=mid+1;
		}
		else {
			end=mid-1;
		}
	}

	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr,arr+n);
	int floor_ans=floor(arr,n,x);
	int ceil_val=ceil(arr, n, x);
	return {floor_ans,ceil_val};
}
