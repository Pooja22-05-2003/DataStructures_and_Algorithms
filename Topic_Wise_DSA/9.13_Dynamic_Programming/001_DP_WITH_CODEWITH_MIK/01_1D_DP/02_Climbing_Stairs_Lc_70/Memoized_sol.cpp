// TC=O(n^2)
// SC=O(n)

class Solution {
public:
    
    int helper(int i, vector<int>&dp,vector<int>nums )
    {
        if(i==0) return dp[0]=nums[0];
        if(i==1) return dp[1]=max(nums[1],nums[0]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max( helper(i-1,dp,nums) , (nums[i]+helper(i-2,dp,nums)));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,-1);
        return helper(n-1,dp,nums);
        
    }
};