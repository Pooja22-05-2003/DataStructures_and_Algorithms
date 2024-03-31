// TC=O(n)
// SC=O(n)
class Solution {
public:
    int solve(int st, int i , vector<int>&nums , vector<int>&dp)
    
    {
        if(i==st) return dp[i]=nums[i];
        if(i==st+1) return dp[i]=max(nums[i],nums[i-1]);
        
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max((solve(st,i-1,nums,dp)), (solve(st,i-2,nums,dp)+nums[i]));
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;       // ✨✨Don't Forget to add these 2 base comdition
        if(n==1) return nums[0]; // ✨✨Don't Forget to add these 2 base comdition
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        
        int take_0th_el=solve(0,n-2,nums,dp1); // If u are taking 0th element , then u have to send here n-2 as the end index
        int Not_Take_0th_el=solve(1,n-1,nums,dp2);  // If u are ignoring the first index, then u can take the last index
        return max(take_0th_el,Not_Take_0th_el);
    }
};