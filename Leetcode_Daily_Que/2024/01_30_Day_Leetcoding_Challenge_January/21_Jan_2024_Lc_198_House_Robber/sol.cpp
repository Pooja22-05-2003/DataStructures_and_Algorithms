/*
Approach:
1. At any index 'i', we have 2 options , whether to pick the current index element , or to ignore the current index element.
2. If we are picking the current index element , then u will add dp[i-2] in the current element and the other option is just ignore the current index element, so add dp[i-1] in that.
3. After all iteration till index n , return dp[n] as the final answer.
*/

// TC=O(n)
// SC=O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        if(n>=2){

            dp[1]=max(nums[0],nums[1]);
        
            int i=2;
            while(i<n){

                dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
                i++;
            }
        }

        return dp[n-1];
    }
};