// TC=O(n)
// SC=O(n)

// Tabulation
class Solution {
public:
  
    int fib(int n) {
        // create dp array of +1 size, so that it will never go in runtime error, or size overflow
    
       // here if n<=1 return here only, because while intializing u are accessing the 1st index and if n==0 then accessing 1st index will give u the runtime error
        
       if(n<=1) return n;
       vector<int>dp(n+1,0);
    
       dp[0]=0;
       dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};