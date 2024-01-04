/*

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.


*/




// Swapping and backtracking approach
/*
-> Time Complexity:  N! x N
-> Space Complexity:  O(1)  [ No extra array space used , only recursive space is used]
*/

class Solution {
public:

    void solve(int ind,vector<int>& nums ,vector<vector<int>> &ans ){
        //  base case
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,ans);
            swap(nums[ind],nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
       
        // vector<int>vis(nums.size(),false);
        solve(0,nums,ans);
        return ans;
    }
};