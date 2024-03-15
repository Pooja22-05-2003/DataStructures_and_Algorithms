// TC=O(N)
// SC=O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int fromBegin=1;
        int fromEnd=1;
        int n=nums.size();

        vector<int> res(n,1);
        for(int i=0;i<nums.size();i++){

            // in this we move forward , and store the curr ind elem by multiplying prevoious multiplication
            res[i]*=fromBegin;
            fromBegin*=nums[i];

         // in this we move from backward to forward , and store the curr ind elem by multiplying iske piche wale elememt ke  multiplication

         res[n-1-i]*=fromEnd;
         fromEnd=fromEnd*nums[n-1-i];


        }
        return res;
    }
};