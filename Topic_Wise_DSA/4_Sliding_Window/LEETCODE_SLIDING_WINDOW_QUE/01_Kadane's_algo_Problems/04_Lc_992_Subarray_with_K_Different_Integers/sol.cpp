// ans1=Find the subarray with k,k-1,k-2...1 distinct subarray
// ans2=Find the subarray with k-1,k-2...1 distinct subarray
// ans=ans1-ans2

class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
         int cnt=0;
        int n=nums.size();
        int i=0;
        int j=0;
        
        unordered_map<int,int>mp;
        while(j<n)
        {
          mp[nums[j]]++;
           
              while(mp.size()>k)
              {
            
                  mp[nums[i]]--;
                  if(mp[nums[i]]==0) mp.erase(nums[i]);
                  i++;
                 
              }
          
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return solve(nums,k)-solve(nums,k-1);
    }
};