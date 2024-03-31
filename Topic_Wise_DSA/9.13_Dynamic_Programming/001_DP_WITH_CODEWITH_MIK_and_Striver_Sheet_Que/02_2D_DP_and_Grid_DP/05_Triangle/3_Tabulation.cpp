// Tabulation  sol
// TC=O(n)
// SC=O(n)

class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // base case is for last row, we alread know ans for that.
        // our final answer will get store in dp[0][0]
        
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                
                int down=triangle[i][j]+dp[i+1][j];
                int downRight=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,downRight);
            }
        }
        return dp[0][0];
    }
};