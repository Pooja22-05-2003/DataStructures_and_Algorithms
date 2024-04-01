// Tabulation code
// TC=O(n*amount)
// SC=O(n*amount)[No recursion stack space]

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0; // edge case
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX-100));
        
        for(int j=0;j<=amount;j++)
        {
             if (j% coins[0]==0) dp[0][j]=j/coins[0] ; 
        }
        
        
        for(int ind=1;ind<n;ind++)     // ind will start here from 1, because u handled for 0 case already
        {
            for(int j=0;j<=amount;j++ )
            {
                 int notTake=0+dp[ind-1][j];
                 int take=INT_MAX-100;
                 if(coins[ind]<=j) take=1+dp[ind][j-coins[ind]];  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
        
                 dp[ind][j]=min(notTake,take);
            }
        }
        int ans=dp[n-1][amount];
        return (ans==INT_MAX-100)? -1:ans;   // ✨✨ Here it is mentioned in the question, if ans  is not possible then return -1
    }
};