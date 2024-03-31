// TC=O(n)
// SC=O(n)
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n<=1) return n;
        
        // if ans previously u already solved, then don't need to do the recursion call again
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
    }
    int fib(int n) {
        // create dp array of +1 size, so that it will never go in runtime error, or size overflow
       vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};