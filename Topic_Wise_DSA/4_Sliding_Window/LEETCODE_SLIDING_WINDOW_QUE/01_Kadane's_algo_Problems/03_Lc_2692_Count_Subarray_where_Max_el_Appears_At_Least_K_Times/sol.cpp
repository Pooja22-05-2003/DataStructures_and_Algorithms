// TC=O(2n)=O(n)
// SC=O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxel=nums[0];
        for(auto it : nums) maxel=max(maxel,it);
        
        int cnt=0;
        long long ans=0;
        int j=0;
        // cout<<"maxel:"<<maxel<<endl;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxel){
             cnt++;
            }  
            while(cnt>=k )  // here checking with j<i is not correct, and it will fail some test cases, so not add that .
            {
                
                ans+=(nums.size()-i); // at least k time maxel should appear in the array, so till index i maxel is appearing k times, so starting from i till last index, it will apprear for k time and more, so that is a valid subarray
                 if(nums[j]==maxel){
                 cnt--;
                  }
                j++;
            }
            
        }
        
        return ans;
    }
};