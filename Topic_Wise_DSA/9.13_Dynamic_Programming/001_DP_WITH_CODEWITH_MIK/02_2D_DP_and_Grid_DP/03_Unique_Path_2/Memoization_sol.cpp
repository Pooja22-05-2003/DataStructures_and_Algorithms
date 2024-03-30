class Solution {
public:
    int solve(int r, int c, vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
    {
        // base case
         if(r<0 || c<0) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==0 && c==0) return 1;
       
        
        if(dp[r][c]!=-1) return dp[r][c];
        int ans1=solve(r,c-1,dp,obstacleGrid);
        int ans2=solve(r-1,c,dp,obstacleGrid);

        return dp[r][c]=ans1+ans2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
        
        
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};