// Space Optimization code
// TC=O(n*amount)
// SC=O(amount)
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0; // edge case
        // vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX-100));
        vector<int>prev(amount+1,INT_MAX-100);
        vector<int>curr(amount+1,INT_MAX-100);
        
        for(int j=0;j<=amount;j++)
        {
             if (j% coins[0]==0) prev[j]=j/coins[0] ; 
        }
        
        
        for(int ind=1;ind<n;ind++)     // ind will start here from 1, because u handled for 0 case already
        {
            for(int j=0;j<=amount;j++ )
            {
                 int notTake=0+prev[j];
                 int take=INT_MAX-100;
                 if(coins[ind]<=j) take=1+curr[j-coins[ind]];  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
        
                 curr[j]=min(notTake,take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return (ans==INT_MAX-100)? -1:ans;   // ✨✨ Here it is mentioned in the question, if ans  is not possible then return -1
    }
};