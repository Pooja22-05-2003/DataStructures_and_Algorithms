// Memoized code
// TC=O(n*amount)
// SC=O(n*amount)+O(n)

class Solution {
public:
    int solve(int ind, vector<int>&coins, int amount,vector<vector<int>>&dp)
    {
//         base case
      
        if(ind==0)
        {
            if (amount% coins[0]==0) return 1 ;  
            return 0;    
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
       
        int notTake=solve(ind-1,coins, amount,dp);
        int take=0;    
        if(coins[ind]<=amount) take=solve(ind,coins,amount-coins[ind],dp);  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
        
        return dp[ind][amount]=(notTake+take);
    }
   
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0) return 1; // edge case
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins, amount,dp);
        return ans;
    }
};