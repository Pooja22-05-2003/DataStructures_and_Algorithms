// Memoization Code 
// TC=O(n)
// SC=O(n*k)+O(n) //Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

#include <bits/stdc++.h> 
bool solve(int ind, int target, vector<int>&arr,vector<vector<int>>&dp)
{
    // base case
    if(target==0) return true; // It is compulsory to write the first case upper line, then only u can write the lower case case
    if(ind==0) return (target==arr[0]); // don't write this base case at the top
 
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake=solve(ind-1,target,arr,dp);
    bool Take=false;
    if(arr[ind]<=target)
    {
        Take=solve(ind-1,(target-arr[ind]),arr,dp);
    }
    return dp[ind][target]=(notTake | Take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1)); // ⚠️⚠️Remeber to make the size of k to k+1, because it is 0 based indexing and k+1 insure that your dp arr size till k
    return solve(n-1,k,arr,dp);
}