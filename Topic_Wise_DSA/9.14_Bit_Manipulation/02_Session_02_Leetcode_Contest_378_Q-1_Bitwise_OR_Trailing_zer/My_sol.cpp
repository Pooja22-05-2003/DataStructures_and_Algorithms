// TC=O(n)
// SC=O(1)
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            // cout<<"last_bit:"<<(nums[i]&1)<<endl;
            if((nums[i]&1)==0) cnt++;
        }
        if(n==1 && cnt==1) return true;
        if(n==2 && cnt==2) return true;
        if(n>2 && cnt>=2) return true;
        else return false;
    }
};