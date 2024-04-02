// Memoization
// TC=O(n*m)
// SC=O(n*m)+O(n+m)[Recursion stack space]
class Solution{
    public:
    int helper(string &S1, string &S2, int i, int j,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        int nottake=0;
        if(S1[i]==S2[j]){
            take= 1+helper(S1,S2,i-1,j-1,dp);
        }
        else {
            nottake=0;
        }
        return dp[i][j]=max(take,nottake);
         
        
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                ans=max(ans,helper(s1,s2,i,j,dp));
            }
        }
       return ans;
    }
};