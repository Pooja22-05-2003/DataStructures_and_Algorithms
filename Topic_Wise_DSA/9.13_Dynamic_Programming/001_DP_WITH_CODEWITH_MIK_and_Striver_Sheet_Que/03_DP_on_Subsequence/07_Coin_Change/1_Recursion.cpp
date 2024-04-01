// Recursion
// TC=O(2^n)
// SC=O(n)

class Solution {
public:
    int solve(int ind, vector<int>&coins, int amount)
    {
//         base case
      
        if(ind==0)
        {
            if (amount% coins[0]==0) return amount/coins[0] ;   // ✨✨✨✨Here multiple coins we can take, so at index 0, if we have target which is multiple of the el at index 0, we can take that number of coins of index 0
            return INT_MAX-100;     // ✨✨If if is not possible than send some large value
        }
        
       
        int notTake=0+solve(ind-1,coins, amount);
        int take=INT_MAX-100;    // Here intializign with INT_MAX-100 to prevent the integer overflow case
        if(coins[ind]<=amount) take=1+solve(ind,coins,amount-coins[ind]);  // ✨✨Here remember not to send ind-1, because we can take multiple occurence of the same index element.
        
        return min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0) return 0; // edge case
        int ans=solve(n-1,coins, amount);
        return (ans==INT_MAX-100)? -1:ans;   // ✨✨ Here it is mentioned in the question, if ans  is not possible then return -1
    }
};