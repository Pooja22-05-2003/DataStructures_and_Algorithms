//  TC=O(2^n)
//  SC=O(n)
class Solution {
public:
    int solve(int ind,int target,vector<int>&nums){
        //  base case
    //     **** try to add this base condition(short and correct)
        if(ind<0){
            return (target==0);
        }

     
        // add +
        //  if u are adding plus in your answer , then target should reduce by 1
        int positive=0;
        positive =  solve(ind-1,target-nums[ind],nums);

        //  add -
        //  if u are adding minus in your answer, then target should increase by 1
        int negative=solve(ind-1, target+nums[ind], nums);

        return positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size()-1;
        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n,target,nums);
    }
};

