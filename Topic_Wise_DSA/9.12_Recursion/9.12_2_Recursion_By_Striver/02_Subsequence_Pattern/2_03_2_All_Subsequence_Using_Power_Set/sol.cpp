// Power Set
// TC=O(2^n*n)
// SC=O(1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        // Outer loop will run from 0 -> (2^n)
        int pow_size=pow(2,nums.size());
        for(int i=0;i<pow_size;i++){
            // Inner loop will run from 0-> n
            for(int j=0;j<n;j++){
                // if the ith bit is set , then take the ele that index present in the array
                // For checking the ith bit is set or not, do the left shift of j=> (1<<j)
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};