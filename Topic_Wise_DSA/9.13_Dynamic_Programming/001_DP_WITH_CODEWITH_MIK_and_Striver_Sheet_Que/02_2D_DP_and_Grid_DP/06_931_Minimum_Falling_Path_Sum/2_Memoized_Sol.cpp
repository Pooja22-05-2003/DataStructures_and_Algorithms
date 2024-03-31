// Memoized sol
// TC=O(n)
// SC=O(n)
class Solution {
public:
    int solve(int i, int j, int m , int n , vector<vector<int>>& nums,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n || j<0) return 1000000;
        if(i==m-1) return dp[i][j]=nums[i][j];
     
        
        if(dp[i][j]!=-1) return dp[i][j];
        int below= 1000000 , Dleft= 1000000 , Dright=10000000;
        if(i+1<m  ) below=nums[i][j]+solve(i+1,j,m,n,nums,dp);
        if(i+1<m && j-1>=0) Dleft=nums[i][j]+solve(i+1, j-1, m , n, nums,dp);
        if(i+1<m && j+1<n) Dright=nums[i][j]+solve(i+1,j+1,m,n,nums,dp);
            
        return dp[i][j]=min(below, min(Dleft, Dright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1000000;
        int m=matrix.size();
        int n=matrix[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
           
            ans=min(ans,solve(0,j,m,n,matrix,dp));
        }
        return ans;
    }
};