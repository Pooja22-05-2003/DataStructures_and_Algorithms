// TC=O(n*m)
// SC=O(n*m)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        int i=1;
        while(i<=n){
            int j=1;
            while(j<=m){
                // in question only up and down moves are allowed.
                // but we are filling from top to bottom , so at any matrix[i][j]...we can get ans from left or up.
                // left=col--
                // up=row--
                    if(i==1 && j==1)   dp[1][1]=grid[0][0];
                    else 
                    {
                        int up=INT_MAX;
                        if(i-2>=0) up=grid[i-1][j-1]+dp[i-1][j];

                        int left=INT_MAX;
                        if(j-2>=0) left=grid[i-1][j-1]+dp[i][j-1];
                        // cout<<"up:"<<up<<" left:"<<left<<endl;
                        dp[i][j]=min(left,up);
                    } 
                // cout<<"i:"<<i<<" j:"<<j<<" dp[i][j]:"<<dp[i][j]<<endl;
                j++;
            }
            i++;
        }
        return dp[n][m];
    }
};