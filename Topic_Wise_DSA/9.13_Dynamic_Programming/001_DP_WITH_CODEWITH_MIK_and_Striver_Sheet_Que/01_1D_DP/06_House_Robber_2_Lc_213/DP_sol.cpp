// TC=O(n)
// SC=O(n)
class Solution {
public:
    int solve(int st, int end , vector<int>&nums , vector<int>&dp)
    
    {
       dp[st]=nums[st];
       if(st+1<=end) dp[st+1]=max(nums[st+1],nums[st]); // ✨✨ Here if condition is necessary, without if (u will get error in [0,0])
       
      for(int i=st+2;i<=end;i++)
      {
          dp[i]=max(dp[i-1],(nums[i]+dp[i-2]));
      }
        return dp[end];
        
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