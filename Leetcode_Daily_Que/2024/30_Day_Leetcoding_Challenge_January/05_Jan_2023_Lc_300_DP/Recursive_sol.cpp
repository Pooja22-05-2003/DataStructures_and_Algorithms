// Recurisve Solution, TC=O(2^n), SC=O(n)

class Solution {
public:
    int solve(int ind, int prev_ind,vector<int> nums, int n ){
        //  base case 
        if(ind==n) return 0;

        // not take condition
        int len=0;
        len=0+solve(ind+1,prev_ind,nums,n);

        // take condition
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])  len=max(len,(1+solve(ind+1,ind,nums,n)));

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(0,-1,nums,n);
    }
};