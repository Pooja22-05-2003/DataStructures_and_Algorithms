class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxAns=INT_MIN;
        int n =nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    int product=(nums[i]-1)*(nums[j]-1);
                    maxAns=max(maxAns , product);
                }
            }
        }

        return maxAns;
    }
};