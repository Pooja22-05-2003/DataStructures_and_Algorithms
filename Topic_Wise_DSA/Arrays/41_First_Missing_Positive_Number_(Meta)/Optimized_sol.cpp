// TC=O(n)
// SC=O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int cnt_1=0;
        // If u find any number <=0 make it 1, and if 1 can be our answer handle that case separately
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) cnt_1++;
            else if(nums[i]<=0)
            {
                nums[i]=1;
            }
        }
        
        if(cnt_1==0) return 1;
        
        for(int i=0;i<n;i++)
        {
            int el=nums[i];
            int ind=abs(nums[i]);
            if(ind<=n)
            {
                // it means ind+1 element is present in the array
               if(nums[ind-1]>0) nums[ind-1]=-1*(nums[ind-1]);
            }
              
        }
        

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};