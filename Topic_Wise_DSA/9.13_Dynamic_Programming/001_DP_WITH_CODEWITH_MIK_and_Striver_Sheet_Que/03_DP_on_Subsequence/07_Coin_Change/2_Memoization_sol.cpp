// Memoization code
// TC=O(n*amount)
// SC=O(n*amount)+O(n)

class Solution {
public:
    int solve(int ind, vector<int>&coins, int amount,vector<vector<int>>&dp)
    {
//         base case
      
        if(ind==0)
        {
            if (amount% coins[0]==0) return amount/coins[0] ;   // ✨✨✨✨Here multiple coins we can take, so at index 0, if we have target which is multiple of the el at index 0, we can take that number of coins of index 0
            return INT_MAX-100;     // ✨✨If if is not possible than send some large value
        }
        
       if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake=0+solve(ind-1,coins, amount,dp);
        int take=INT_MAX-100;
        if(coins[ind]<=amount) take=1+solve(ind,coins,amount-coins[ind],dp);  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
        
        return dp[ind][amount]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0; // edge case
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins, amount,dp);
        return (ans==INT_MAX-100)? -1:ans;   // ✨✨ Here it is mentioned in the question, if ans  is not possible then return -1
    }
};