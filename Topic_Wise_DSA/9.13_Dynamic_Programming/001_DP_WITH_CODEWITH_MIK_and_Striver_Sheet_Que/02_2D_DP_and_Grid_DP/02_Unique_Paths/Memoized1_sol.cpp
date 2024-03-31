// Memoized Sol
// TC=O(n)
// SC=O(n*n)

class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>&dp)
    {
        // base case
        if(r==m-1 && c==n-1) return 1;
        if(r>=m || c>=n) return 0;
        
        if(dp[r][c]!=-1) return dp[r][c];
        int ans1=solve(r,c+1,m,n,dp);
        int ans2=solve(r+1,c,m,n,dp);

        return dp[r][c]=ans1+ans2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};