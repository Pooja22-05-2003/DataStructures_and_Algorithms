// TC=O(n)
// SC=O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,0);
        if(n==0) return 0;
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max( dp[i-1] , (nums[i]+dp[i-2]));
        }
        return dp[n-1];
    }
};