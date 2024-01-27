/*
Problem : Given n, find the count of the arrays(Permutation) of arr[1,2....n] such that there are exactly k inverse pair in the array.

-> As the answer can be huge return the ans with modulo(10^9+7).

dp[i][j]=> Maximum number of valid array possible till index i having j number of pairs.

*/

// TC=O(n*n)
// SC=O(n*n)
class Solution {
public:
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            long long val=0;
            for(int j=0;j<=k;j++)
            {
               
                val+=dp[i-1][j];


                if(j>=i)
                {
                    val=val-dp[i-1][j-i];
                }

               
                dp[i][j]=(val%mod);
            }
        }

        return dp[n][k];
        
    }
};