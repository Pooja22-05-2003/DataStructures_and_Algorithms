// TC=O(n)
// SC=O(1)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 1 1 2 3 5 12 50
        int n=nums.size();
        int CurrSum=nums[0];
        int ans=0;
        int i=1;
        while(i<n)
        {
            
            if(nums[i]>CurrSum)
            {
                ans=CurrSum;
            }
            else {CurrSum+=nums[i];}
            i++;
        }
        
        return ans;
    }
};