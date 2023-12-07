/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/


/*
-> Problem is saying that u need to divide the array in two subsets , having sum of both the subset equal
-> Now break the problem into subproblems
-> U can find the sum of the array easily
-> Now find sum/2
-> If that sum/2 is odd , ( It will be never possible that u will find two subsets having equal sum)
-> If sum/2 is even , then if u were able to find the subset sum equal to sum/2 in the subset , then remainig sum/2 subset will definitely also be present in that array 

=> So , In final now your problem breaks down if sum is even , then just simply [Do subset sum equal to target question , if that is returning true , return true as your asnwer , else return false]
*/

class Solution {
public:


    // Space Optimization- O(n*k)
// Space Complexity = O(n*k)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // if (n == 0) return k == 0;
    // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    vector<bool>prev(k+1,false);
    
     //   ⚠️⚠️⚠️ dont' forget to intialize curr[0]=true, in space optimization
    prev[0]=true;

    if(arr[0]<=k) prev[arr[0]] =true;


    for(int ind=1;ind<n;ind++){

          //   ⚠️⚠️⚠️ make sure to make this curr vector inside
        vector<bool>curr(k+1,false);

         //   ⚠️⚠️⚠️ dont' forget to intialize curr[0]=true, in space optimization
        curr[0]=true;
        for(int target=1;target<=k;target++){
        bool take = false;

        //   ⚠️⚠️⚠️ take condition is only applicable if the current element is greater or equal to target, u missed this codition
        if (arr[ind] <= target) {
          take = prev[target - arr[ind]];
        }

        //  not take
        bool notTake = false;
        notTake = prev[target];

        curr[target] = take || notTake;
        }
        prev=curr;

       
    }
   
     return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it : nums) sum+=it;
        if(sum%2!=0) return false;
        else{
            int target=sum/2;
            return subsetSumToK(nums.size(),target,nums);
        }
    }
};



