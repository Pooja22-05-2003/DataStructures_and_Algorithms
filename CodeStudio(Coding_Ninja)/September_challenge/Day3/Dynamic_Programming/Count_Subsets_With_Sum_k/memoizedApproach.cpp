//  TC=O(n*k)
//  SC=O(n*k)+O(n)

int mod=(1e9+7);
int solve(int ind,vector<int> &arr, int target,vector<vector<int>>&dp){

	//  base case
	if(target==0) return 1;
	if(ind==0){
		if(arr[ind]==target) return 1;
		else return 0;
	}
	// if(ind<0) return 0;

	if(dp[ind][target]!=-1) return dp[ind][target];
	//  Include 
	int include=0;

	//  ⚠️⚠️ U putted greater then equal to , by mistake
	if(arr[ind]<=target){
		include=solve(ind-1,arr,target-arr[ind],dp);
	}

	int exclude=solve(ind-1,arr,target,dp);

	// ⚠️⚠️ First convert mod to int then do the operation
	return dp[ind][target]=(include+exclude)%(mod);



	//  Not Include


}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return solve(arr.size()-1,arr,k,dp);
}



