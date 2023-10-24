//  TC=O(2^n)
//  SC=O(n)
int solve(int ind,vector<int> &arr, int target){

	//  base case
	if(target==0) return 1;
	if(ind==0){
		if(arr[ind]==target) return 1;
		else return 0;
	}
	if(ind<0) return 0;

	
	//  Include 
	int include=0;

	//  ⚠️⚠️ U putted greater then equal to , by mistake
	if(arr[ind]<=target){
    // ⚠️⚠️  here no need to add += because we are adding at the last both include and exclude options
		include=solve(ind-1,arr,target-arr[ind]);
	}

	int exclude=solve(ind-1,arr,target);

	return include+exclude;



	//  Not Include


}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	return solve(arr.size()-1,arr,k);
}



