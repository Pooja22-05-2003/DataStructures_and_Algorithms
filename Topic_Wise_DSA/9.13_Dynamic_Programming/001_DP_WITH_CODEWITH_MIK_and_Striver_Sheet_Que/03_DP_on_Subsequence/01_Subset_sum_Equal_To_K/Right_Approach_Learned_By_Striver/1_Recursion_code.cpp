// Recursion 
// TC=O(2^n)
// SC=O(n*k)+O(n) //Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

#include <bits/stdc++.h> 
bool solve(int ind, int target, vector<int>&arr)
{
    // base case
    if(target==0) return true; // It is compulsory to write the first case upper line, then only u can write the lower case case
    if(ind==0) return (target==arr[0]); // don't write this base case at the top
 
    
    bool notTake=solve(ind-1,target,arr);
    bool Take=false;
    if(arr[ind]<=target)
    {
        Take=solve(ind-1,(target-arr[ind]),arr);
    }
    return (notTake | Take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n-1,k,arr);
}