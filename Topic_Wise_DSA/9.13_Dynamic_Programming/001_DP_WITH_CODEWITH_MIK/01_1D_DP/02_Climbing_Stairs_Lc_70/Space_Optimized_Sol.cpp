/*
Approach:
1. Why it is a DP Problem??
2. This contain overlapping subproblem
3. For calculating dp[i] we need 2 answers, dp[i-1] and dp[i-2]
4. dp[i]=dp[i-1]+dp[i-2]
5. And Finally we can return dp[n]

*/

// TC=O(n)
// SC=O(1)

class Solution {
public:
    int climbStairs(int n) {
        // if n=1, then there is only one way so dp[i]=1;
        // if n=2, then there are 2 ways [(1 step + 1step), (2 steps)]
        
        if(n<=1) return n;
        int prev2=1; 
        int prev1=1; // lets take the prev1 as the closest to curr
        int curr=0;
        
        for(int i=2;i<=n;i++)
        {
            // dp[i]=dp[i-1]+dp[i-2];
            curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};