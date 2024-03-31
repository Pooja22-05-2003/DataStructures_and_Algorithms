// Space Optimzatiom Code 
// TC=O(n)
// SC=O(2*k)/==O(k) / Here O(n) extra recursion stack space got removed

#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    // vector<vector<bool>>dp(n,vector<bool>(k+1,false)); // ⚠️⚠️Remeber to make the size of k to k+1, because it is 0 based indexing and k+1 insure that your dp arr size till k

    // // base case for target==0, index can range from 0 to n-1
    // for(int i=0;i<=n-1;i++)
    // {
    //     dp[i][0]=true;
    // }

    // // now intialize the dp array for the base case if(ind==0) return (target==arr[0]); , here ind is fixed and only target value having el==arr[0]will marked as true
    // dp[0][arr[0]]=true;

    
    vector<bool>prev(k+1,false);
    prev[arr[0]]=true;
    prev[0] =true;
    for(int ind=1;ind<=n-1;ind++) // ⚠️⚠️we will intialize this only from ind=1, because at ind=0, only the base the which we initialized is true
    {
        prev[0]=true;
        vector<bool>temp(k+1,false);
        for(int target=1;target<=k;target++)
        {
            bool notTake=prev[target];
            bool Take=false;
            if(arr[ind]<=target)
             {
               Take=prev[target-arr[ind]];
             }
            temp[target]=(notTake | Take);
        }
        prev=temp;
    }

    return prev[k];
}