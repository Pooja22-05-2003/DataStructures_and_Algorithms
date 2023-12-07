//  Problem Link :https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Recursive- O(2^n)
// Space Complexity = O(n)
// The space complexity of this code is determined by the depth of the recursive call stack. In the worst case, the recursion goes as deep as the size of the input array, which is n. Therefore, the space complexity is O(n) due to the space required for the call stack.


#include <bits/stdc++.h> 
bool helper(int ind,int k,vector<int>&arr){
    if(ind<0) return false;
    
    //  ⚠️⚠️ u missed this edge case
    if(k==0) return true;
    
    if(ind==0){
        if(arr[0]==k) return true;
        else return false;
    }
    
    //  take 
    bool take=helper(ind-1,k-arr[ind],arr);
    
    //  not take
    bool notTake=helper(ind-1,k,arr);
    
    return take||notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    if(n==0) return true;
    return helper(n-1,k,arr);
}
