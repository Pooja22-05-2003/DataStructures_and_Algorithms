// Memoized solution, TC=O(n*(n+1)), SC=O(n*n)

class Solution {
public:
    int solve(int ind, int prev_ind,vector<int> &nums, int n,vector<vector<int>>& dp ){
        //  base case 
        if(ind==n) return 0;

        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        // not take condition
        
        int len=0+solve(ind+1,prev_ind,nums,n,dp);

        // take condition
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])  len=max(len,(1+solve(ind+1,ind,nums,n,dp)));

        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // Conditional shifht here we are doing , as prev_ind ranges from -1 to n-1 and (-1) ind not present in the array, So here we use 0 for -1, 1 for 0 and so on
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
};