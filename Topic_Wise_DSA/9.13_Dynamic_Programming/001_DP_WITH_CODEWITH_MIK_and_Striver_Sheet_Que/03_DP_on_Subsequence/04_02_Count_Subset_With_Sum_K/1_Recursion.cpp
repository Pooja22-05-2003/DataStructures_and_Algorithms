// Recursion
// TC=O(n*k)
// SC=O(n) [Auxiallry stack spacce of O(n)]

int solve(int ind, int k ,vector<int>& arr, vector<vector<int>>&dp )
{
    // base case
    if(k==0) return 1;
    if(ind==0) return  (arr[0]==k);

    if(dp[ind][k]!=-1) return dp[ind][k];
    int notTake=solve(ind-1,k,arr,dp);
    // take but only if the current element is less than the target
    int take=0;
    if(arr[ind]<=k) take=solve(ind-1, (k-arr[ind]),arr,dp);

    return dp[ind][k]=take+notTake;

}

int findWays(vector<int>& arr, int k)
{
   
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return solve(n-1,k,arr,dp);
}
