class Solution {
public:
    int numRollsToTarget(int n, int p, int target) {
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        int mod = 1e9+7;

        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){

                for(int k=1;k<=min(p, j);k++){

                    dp[i][j] = (dp[i][j]%mod + dp[i-1][j-k]%mod)%mod;

                }
// cout<<"i is "<<i<<" j is "<<j<<" dp[i][j] is "<<dp[i][j]<<endl;
            

            }
        }

        return dp[n][target];

    }
};