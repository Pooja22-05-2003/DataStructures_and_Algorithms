class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int first_pair_product=nums[0]*nums[1];
        int second_pair_product =nums[n-1]*nums[n-2];

        return (second_pair_product-first_pair_product);
    }
};