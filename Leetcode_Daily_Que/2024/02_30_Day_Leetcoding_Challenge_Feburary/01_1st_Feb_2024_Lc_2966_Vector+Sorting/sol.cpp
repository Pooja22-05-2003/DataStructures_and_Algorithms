class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> currentArray;

        for (int num : nums) {
            if (currentArray.empty() || num - currentArray.back() <= k) {
                if(currentArray.size()==2) {
                    if(num-currentArray[0] >k) return {};
                }
                currentArray.push_back(num);
                if (currentArray.size() == 3) {
                    ans.push_back(currentArray);
                    currentArray.clear();
                }
            } 
            
            else {
                return {}; 
            }
        }

        return ans;
        
    }
    
    
};