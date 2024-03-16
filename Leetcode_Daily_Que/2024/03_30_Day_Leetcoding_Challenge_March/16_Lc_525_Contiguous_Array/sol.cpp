class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> tracker;

        int currSum=0;
        int len=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) currSum-=1;
            if(nums[i]==1) currSum+=1;
            if(currSum==0) len=i+1;
            else if (tracker.find(currSum)!=tracker.end()) len=max(len,i-tracker[currSum]);
            else tracker[currSum]=i;
        }

        return len;
    }
};