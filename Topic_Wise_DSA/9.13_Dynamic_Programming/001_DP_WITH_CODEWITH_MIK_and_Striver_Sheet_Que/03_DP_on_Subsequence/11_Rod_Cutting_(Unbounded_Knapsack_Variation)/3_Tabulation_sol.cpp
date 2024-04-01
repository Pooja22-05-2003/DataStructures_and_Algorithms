// Tabulation
// TC=O(n*n)
// SC=O(n*n)
class Solution{
  public:
   
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        for(int j=0;j<=n;j++)
        {
            int ind=0;
            if(j%(ind+1)==0)
            {
                dp[ind][j]= price[ind]*(j/(ind+1));
            }
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int c=1;c<=n;c++)   // ✨✨here must intialize the value starting from 1 and not 0 and end at n
            {
                int nottake=dp[ind-1][c];
                int take=INT_MIN;
                if(c>=(ind+1))
                {
                   take=price[ind]+dp[ind][c-(ind+1)];
                }
               dp[ind][c]=max(nottake,take);
            }
        }
        return dp[n-1][n];
    }
};