//  TC=O(n*k)
//  SC=O(n*k)

int mod=(1e9+7);

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,0));

	for(int ind=0;ind<n;ind++){
		dp[ind][0]=1;
	}
	if(arr[0]<=k) dp[0][arr[0]]=1;

	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=k;target++){
				int include=0;

	           if(arr[ind]<=target){
		             include=dp[ind-1][target-arr[ind]];
	             }

	             int exclude=dp[ind-1][target];

	// ⚠️⚠️ First convert mod to int then do the operation
	        dp[ind][target]=(include+exclude)%(mod);
		}
	}
	return dp[n-1][k];
}
