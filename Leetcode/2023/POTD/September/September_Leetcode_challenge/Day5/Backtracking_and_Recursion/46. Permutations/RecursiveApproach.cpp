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

/*
-> Recursive approach 
-> Time Complexity:  N! x N
-> Space Complexity:  O(N)
*/

class Solution {
public:

    void solve(vector<int>& nums ,vector<vector<int>> &ans ,vector<int> &temp,vector<int>vis){
        //  base case
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,ans,temp,vis);

                vis[i]=0;
                temp.pop_back();

            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int>vis(nums.size(),false);
        solve(nums,ans,temp,vis);
        return ans;
    }
};