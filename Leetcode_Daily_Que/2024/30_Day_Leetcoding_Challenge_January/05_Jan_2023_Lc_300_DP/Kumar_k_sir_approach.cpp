/*
Using Kumar k sir Appraoch
1. Calaculte dp[0]=1;
2. Calculate dp[1]= if(arr[2]>arr[1]) then , dp[1]=2, else dp[1]=1
3. For  dp[i] tells that the best answer till index i. it necesaary to include the last element
4. So, for any index i, check for i-1,i-2 ....till 1. and increment in your count.


*/

// TC=O(n*n)
// SC=O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n,1); // each element has the minimum LIS=1

            for(int i=1;i<nums.size();i++){
                for(int j=i-1;j>=0;j--){
                    if(nums[j]<nums[i]){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
            }

            return *max_element(dp.begin(),dp.end());
    }
};