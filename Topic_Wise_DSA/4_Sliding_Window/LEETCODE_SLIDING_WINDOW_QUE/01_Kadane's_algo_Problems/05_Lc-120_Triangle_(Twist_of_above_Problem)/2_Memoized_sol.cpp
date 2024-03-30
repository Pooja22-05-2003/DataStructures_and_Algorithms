// Memoized  sol
// TC=O(n)
// SC=O(n)

class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        if(i==n-1) return triangle[i][j];
        // if(i>n || i.size()) return 0; // Not requires, because at the curr index, we are going down or down adajcent, so on the next it will have one more el than the current row, and it will never go out of bound
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        int downRight=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
        
        return dp[i][j]=min(down, downRight);
          
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n,triangle,dp);
    }
};