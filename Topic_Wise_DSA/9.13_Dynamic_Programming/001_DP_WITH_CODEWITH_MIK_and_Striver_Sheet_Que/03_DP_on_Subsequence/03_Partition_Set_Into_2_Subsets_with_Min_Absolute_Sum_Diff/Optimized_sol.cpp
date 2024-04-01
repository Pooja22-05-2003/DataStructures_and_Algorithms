// It will not pass all the testcases on the leetcode and work only if all the numbers in the array is positive.

class Solution {
public: 
        
void subsetSumToK(int n, int k, vector<int> &arr,vector<vector<bool>>&dp) {
    // Write your code here.
    
    // vector<vector<bool>>dp(n,vector<bool>(k+1,false)); // ⚠️⚠️Remeber to make the size of k to k+1, because it is 0 based indexing and k+1 insure that your dp arr size till k
    
    

    // base case for target==0, index can range from 0 to n-1
    for(int i=0;i<=n-1;i++)
    {
        dp[i][0]=true;
    }

    // now intialize the dp array for the base case if(ind==0) return (target==arr[0]); , here ind is fixed and only target value having el=arr[0]will marked as true
    if(arr[0]<=k) dp[0][k]=true;

    for(int ind=1;ind<=n-1;ind++) // ⚠️⚠️we will intialize this only from ind=1, because at ind=0, only the base the which we initialized is true
    {
        for(int target=1;target<=k;target++)
        {
            bool notTake=dp[ind-1][target];
            bool Take=false;
            if(arr[ind]<=target)
             {
               Take=dp[ind-1][target-arr[ind]];
             }
            dp[ind][target]=(notTake | Take);
        }
    }

    // return dp[n-1][k];
}
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
         int totalsum=0;
        for(auto it : nums) totalsum+=it;
         vector<vector<bool>>dp(n,vector<bool>(totalsum+1,false)); // ⚠️⚠️Remeber to make the size of k to k+1, because it is 0 based indexing and k+1 insure that your dp arr size till k
       
        
        subsetSumToK(n,totalsum,nums,dp);
        
        // now dp is ready to tell u whether it is possible to achive any sum of subset in arr or not
        
        int mini=1e9;
        
        for(int i=0;i<=totalsum;i++)
        {
            if(dp[n-1][i]==true)
            {
                int diff=abs(i-(totalsum-i));
                mini=min(mini,diff);
            }
        }
        
        return mini;
    }
    
    
};