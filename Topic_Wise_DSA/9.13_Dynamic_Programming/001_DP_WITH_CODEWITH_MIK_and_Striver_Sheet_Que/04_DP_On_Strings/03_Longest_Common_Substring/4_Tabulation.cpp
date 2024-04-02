// Tabulation
// TC=O(n*m)
// SC=O(n*m)
class Solution{
    public:
   
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       int ans=0;
        int i=0;// means s1 string has length=0;
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;   // it menas that the length of longest common substring when length of string 1 is 0 and length of strign 2 is j
        }
        
        int j=0; // means s2 string has length =0;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                if(s1[i-1]==s2[j-1]){  // ✨✨here must do i-1 and j-1, because we are using 1 based indexing
                  dp[i][j]= 1+dp[i-1][j-1];
                }
                else {
                   dp[i][j]=0;
                }
               
                ans=max(ans,dp[i][j]);
            }
        }
       return ans;
    }
};