// Tabulation code
// TC=O(n*amount)
// SC=O(n*amount)+O(n)


// ✨✨You are using the jth var for the amount, so must replace the amount with j variable while copying from memoixed code to tabulation
class Solution {
public:
   
   
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0) return 1; // edge case
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int j=0;j<=amount;j++)
        {
            if (j% coins[0]==0) dp[0][j]= 1 ;  
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                 int notTake=dp[ind-1][j];
                 int take=0;    
                 if(coins[ind]<=j) take=dp[ind][j-coins[ind]];  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
          
                 dp[ind][j]=(notTake+take);
            }
        }
        int ans=dp[n-1][amount];
        return ans;
    }
};