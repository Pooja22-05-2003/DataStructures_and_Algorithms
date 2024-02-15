class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 1 1 2 3 5 12 50
        int n=nums.size();
        int i=1;
        long long  sum=nums[0];
        long long  ans=0;
        while(i<n-1)
        {
            if(sum+nums[i]>nums[i+1])
            {
                // ok move forward
                ans=sum+nums[i]+nums[i+1];
                sum+=nums[i];
                i++;
            }
           
            else 
            {
              sum=sum+nums[i];
                i++;
            }
        }
        
       if (ans==0) return -1;
        else return ans;
    }
};