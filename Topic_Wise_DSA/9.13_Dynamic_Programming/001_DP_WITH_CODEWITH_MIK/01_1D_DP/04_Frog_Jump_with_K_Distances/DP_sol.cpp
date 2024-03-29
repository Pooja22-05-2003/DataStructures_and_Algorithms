// TC=O(n*k)
// SC=O(n)
int minimizeCost(int n, int k, vector<int> &v){
    // Write your code here.
    vector<int>dp(n,INT_MAX);

    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);

    for(int i=2;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]=min(dp[i], (dp[i-j]+ abs(v[i]-v[i-j])));
            }
        }
    }

    return dp[n-1];
}