// Exact similar to Count number of ways to partition the arrya with the given difference

class Solution {
public:
    // Memoization
// TC=O(n*k)
// SC=O(n) [Auxiallry stack spacce of O(n)]

int solve(int ind, int k ,vector<int>& arr, vector<vector<int>>&dp )
{
    // base case
    // if(k==0) return 1;
    // if(ind==0) return  (arr[0]==k);

     // handling the zero case, when zero can also be present in the arr
    if (ind == 0) {
      if (k == 0 && arr[0] == 0)
        return 2; // 2 possible cases, take or not take 0 , both will help in
                  // achieving the target
      if (k == 0 || k == arr[0])
        return 1;
      return 0;
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    int notTake=solve(ind-1,k,arr,dp);
    // take but only if the current element is less than the target
    int take=0;
    if(arr[ind]<=k) take=solve(ind-1, (k-arr[ind]),arr,dp);

    return dp[ind][k]=(take+notTake)%1000000007;

}

int findWays(vector<int>& arr, int k)
{
   
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return solve(n-1,k,arr,dp);
}

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
      
        int totalsum=0;
        for(auto it : arr) totalsum+=it;
        
        if((totalsum-d <0) ||( ((totalsum-d)%2)==1)) return 0;
        
        return findWays(arr,(totalsum-d)/2);
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};