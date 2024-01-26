// Time Complexity=O(m*n*maxmove)
// Space Complexity=O(m*n*maxmove)
class Solution {
public:
    int mod=1e9+7;
    int solve(int r,int c,int currMove,int m,int n,int maxMove,vector<vector<vector<int>>>&dp)
    {
        // grid indexing start from 0 and go till n-1 or m-1
        if(r<0 || r>=m || c<0 || c>=n) return 1;
        if(currMove==maxMove) return 0;
        // 4 options at curr position
        if(dp[r][c][currMove]!=-1) return dp[r][c][currMove];
        int up=(solve(r-1,c,currMove+1,m,n,maxMove,dp))%mod;
        int down=(solve(r+1,c,currMove+1,m,n,maxMove,dp))%mod;
        int left=(solve(r,c-1,currMove+1,m,n,maxMove,dp))%mod;
        int right=(solve(r,c+1,currMove+1,m,n,maxMove,dp))%mod;

        return dp[r][c][currMove]=(((up+down)%mod)+((left+right)%mod))%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,0,m,n,maxMove,dp);
    }
};