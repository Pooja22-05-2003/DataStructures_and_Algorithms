// TC=O(2^n*n) [For each indexes there are 2 options to pick or not pick. SO for each indexes, also we are pushing the temp in ans vector which will take O(n) time]
// SC=O(n) [ Maximum at one time recursion depth can go up to all the indexed which are equal to n]

class Solution {
public:
    void solve(int ind,vector<int>&temp ,vector<vector<int>>& ans,vector<int>& nums){
        if(ind>=nums.size()){
            ans.push_back(temp);
            // ✨You forgot to add this return statement 
            return;
        }

        // take the current index
        temp.push_back(nums[ind]);
        solve(ind+1,temp,ans,nums);
        // not take the current index

        temp.pop_back();
        solve(ind+1,temp,ans,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,ans,nums);
        return ans;
    }
};