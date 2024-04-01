// Space Optimization code
// TC=O(n*amount)
// SC=O(n*amount)+O(n)


// ✨✨You are using the jth var for the amount, so must replace the amount with j variable while copying from memoixed code to tabulation
class Solution {
public:
   
   
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0) return 1; // edge case
        
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        
        for(int j=0;j<=amount;j++)
        {
            if (j% coins[0]==0) prev[j]= 1 ;  
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                 int notTake=prev[j];
                 int take=0;    
                 if(coins[ind]<=j) take=curr[j-coins[ind]];  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
          
                 curr[j]=(notTake+take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return ans;
    }
};