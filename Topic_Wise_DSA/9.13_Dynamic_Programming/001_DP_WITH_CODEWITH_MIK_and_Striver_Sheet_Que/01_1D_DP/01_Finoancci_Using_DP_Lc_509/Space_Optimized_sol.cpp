/*
How we will get to know that space optimization we can do??
-> If the dp recurrence formula need constant previous dp state, then we can store those previous
state in some variable and we can use that.
-> Like in fibonaaci series only, we need 2 previous state, so we can do here space optimization for sure.
*/

// TC=O(n)
// SC=O(1)

// Space Optimized Tabulation
class Solution {
public:
  
    int fib(int n) {
        if(n<=1) return n;
       int prev2=0;
       int prev1=1;
       int curr=0;
        
       for(int i=2;i<=n;i++)
       {
           // dp[i]=dp[i-1]+dp[i-2];
           curr=prev1+prev2;
           prev2=prev1;
           prev1=curr;
       }
        
        return curr;
    }
};