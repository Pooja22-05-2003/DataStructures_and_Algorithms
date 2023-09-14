/*
Problem link :https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/
//  TC=O(logn)
//  SC=O(1)

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	int st=0;
	int end=n-1;
	int ind=n;

	while(st<=end){
		int mid=(2*st+(end-st))/2;
		if(arr[mid]>x){
			ind=mid;
			end=mid-1;
		}
		else {
			st=mid+1;
		}
	}	

	return ind;
}