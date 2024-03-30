// Tabulation sol
// TC=O(n)
// SC=O(n*n)

class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                
                int up, left=100000; // Must Initialize this with some large value. but not with INT_MAX, it will cause overflow
                
                  if(i>0) up=grid[i][j]+dp[i-1][j];
                  if(j>0) left=grid[i][j]+dp[i][j-1];
                
                  dp[i][j]=min(up,left);
            }
        }
        
        return dp[m-1][n-1];
    }
};