// TC=O(2*n)=O(n)
// SC=O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int i=0;
        int j=0;
        int maxlen=0;
        int n=nums.size();
        while(j<n)
        {
            mp[nums[j]]++;
            
            while(mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }
            
            // calculate the lenght of the subarray
            int len=j-i+1;
            maxlen=max(maxlen,len);
            j++;
        }
        
        return maxlen;
    }
};