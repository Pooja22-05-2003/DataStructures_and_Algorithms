// TC=O(n)
// SC=O(n*5)
long long int dp[1000+5][5];
int u = 1e9+7 ; 
class Solution {
public:
    int numTilings(int n) {
        dp[1][1] = 1 ; 
        dp[2][1] = 2 ; 
        
        dp[2][0] = 1 ; 
        dp[2][2] = 1 ; 

        int i = 3 ;
        while(i<=n){

            dp[i][1] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][0] + dp[i-2][1])%u ; 
            dp[i][0] = (dp[i-2][1] + dp[i-1][2])%u ; 

            dp[i][2] = (dp[i-2][1] + dp[i-1][0])%u ; 
            i++;
        }
        return dp[n][1]%u ;
        //RMRM..... 
    }
};