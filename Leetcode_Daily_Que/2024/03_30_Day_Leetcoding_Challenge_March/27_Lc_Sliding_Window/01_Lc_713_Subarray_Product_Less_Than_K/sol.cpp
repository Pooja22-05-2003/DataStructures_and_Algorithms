// TC=O(2*n)==O(n)[Sare element maximum 2 times hi traverse ho rahe hai]
// SC=O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int cnt=0;
        int product=1;
        int n=nums.size();
        if(k<=1) return 0;
        
        while(j<n && i<n)
        {
            product*=nums[j];
            
            while(product>=k)
            {
                product/=nums[i];
                i++;
            }
            
            // valid subarray ending at index j, add all those subarray
            // cout<<"i:"<<i<<" j:"<<j<<endl;
            cnt+=(j-i+1);
            j++;
        }
        
        return cnt;
    }
};
