// Tabulation code 
// TC=O(n)
// SC=O(n*n)
class Solution {
public:
  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int ans=1000000;
        int m=matrix.size();
        int n=matrix[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
          // for i=n-1, intialize the dp values
            dp[m-1][j]=matrix[n-1][j];
        }
        if(n==1) return dp[0][0]; // this is the edge case
        int ans=INT_MAX;
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int below= INT_MAX;    // Intialie all the value // don't do this int below, Dleft, Dright=10000000;(It intialized only 1 value)
                int Dleft= INT_MAX ;
                int Dright=INT_MAX;
                if(i+1<m) below=matrix[i][j]+dp[i+1][j];
                if(i+1<m && j-1>=0) Dleft=matrix[i][j]+dp[i+1][j-1];
                if(i+1<m && j+1<n) Dright=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min(below,min( Dleft, Dright));
                if(i==0) ans=min(ans,dp[0][j]) ;
            
               
            
                    
            }
            
            
        }
        
        return ans;
        
    }
};