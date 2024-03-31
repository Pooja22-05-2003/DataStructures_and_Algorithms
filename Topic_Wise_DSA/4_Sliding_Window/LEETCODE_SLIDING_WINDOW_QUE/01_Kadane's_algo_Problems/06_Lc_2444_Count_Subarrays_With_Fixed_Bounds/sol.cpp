class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minind=-1;
        int maxind=-1;
        int badind=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!(nums[i]>=minK and nums[i]<=maxK)) badind=i;
            if(nums[i]==minK) minind=i;
            if(nums[i]==maxK) maxind=i;
            ans+=max(0,( min(minind, maxind)-badind));            
        }
        return ans;
    }
};