// Tabulation
// TC=O(n*k)
// SC=O(n*k) [No Auxiallry stack spacce of O(n)]



int findWays(vector<int>& arr, int K)
{
   
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(K+1,0));

    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }

    if(arr[0]<=K) dp[0][arr[0]]=1;

    for(int ind=1;ind<n;ind++)
    {
        for(int k=1;k<=K;k++)
        {
            int notTake=dp[ind-1][k];
            // take but only if the current element is less than the target
            int take=0;
            if(arr[ind]<=k) take=dp[ind-1] [k-arr[ind]];

             dp[ind][k]=(take+notTake)%1000000007;
  
        }
    }
	return dp[n-1][K];
}
