// Memoization- O(n*k)
// Space Complexity = O(n*k)+O(n)
#include <bits/stdc++.h> 
bool helper(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
      //  ⚠️⚠️ u missed this edge case
    if(k==0) return true;
      if(ind==0){
        if(arr[0]==k) return  true;
        else return false;
    }
    
    // if(ind<0) return false;
    
  
    
  
    if(dp[ind][k]!=-1) return dp[ind][k];
    //  take
    else {
         bool take = false;

        //   ⚠️⚠️⚠️ take condition is only applicable if the current element is greater or equal to target, u missed this codition
        if (arr[ind] <= k) {
          take = helper(ind - 1, k - arr[ind], arr, dp);
        }

        //  not take
        bool notTake = false;
        notTake = helper(ind - 1, k, arr, dp);

        return dp[ind][k] = take || notTake;
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    if (n == 0) return k == 0;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return helper(n-1,k,arr,dp);
}
