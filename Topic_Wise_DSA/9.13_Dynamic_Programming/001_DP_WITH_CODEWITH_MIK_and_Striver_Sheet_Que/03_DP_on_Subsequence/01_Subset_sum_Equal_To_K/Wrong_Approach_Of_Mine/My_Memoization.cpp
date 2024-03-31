/*
⭐⭐⚠️⚠️⚠️
1. Memoization is (Top-Down) , so start your recursion with index n-1 and go towards lower indexes and initialize the base case
2. Tabulation is (Bottom-Up), so do just opposite of Tabulation and first intialize the base case value in the dp state.

*/

// Memoized  Approach
// TC=O(n*k) Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.
// Space Complexity: O(N*K) + O(N)

// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
#include <bits/stdc++.h> 
bool solve(int ind , int sum, int k, vector<int>&arr,vector<vector<int>>&dp)
{
   
    if(sum==k) return true;
    if(sum>k) return 0;
    if(ind>=arr.size()) return 0; // Put this condition after checking the sum and k condtion, because if u put this condition at first, it will not able to pass all the test cases.
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    bool take=solve(ind+1,(sum+arr[ind]),k,arr,dp);
    bool notTake=solve(ind+1, sum, k, arr,dp);

    return dp[ind][sum]=(take|notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k,-1));
    int sum=0;
    for(int i=)

    return solve(0,sum,k,arr,dp);
}









