class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
           int ind=abs(nums[i])-1; // we are using index to mark the element as visited to prevent the space
           int number=nums[ind];
            
            if(number<0)
            {
                // it means that number is already visited
                ans.push_back(ind+1);
            }
            else
            {
                // we are reaching here first time, so mark it negative
                nums[ind]=-nums[ind];
            }
            
        }
        return ans;
    }
};