/*
Approach:
1. Why it is a DP Problem??
2. This contain overlapping subproblem
3. For calculating dp[i] we need 2 answers, dp[i-1] and dp[i-2]
4. dp[i]=dp[i-1]+dp[i-2]
5. And Finally we can return dp[n]

*/

// TC=O(n)
// SC=O(n)

class Solution {
public:
    int climbStairs(int n) {
        // if n=1, then there is only one way so dp[i]=1;
        // if n=2, then there are 2 ways [(1 step + 1step), (2 steps)]
        
        vector<int>dp(n+1,0);
        if(n<=1) return n;
        dp[0]=1; // if there are no stairs then keep at that place only, because that is only the last start, so there is only 1 ways.
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};