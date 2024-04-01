// / Memoization
// TC=O(n*n)
// SC=O(n*n)+O(n)
class Solution{
  public:
    int solve(int ind, int c, int price[],vector<vector<int>>&dp)
    {
        // base case
        if(ind==0)
        {
            if(c%(ind+1)==0)
            {
                return price[ind]*(c/(ind+1));
            }
            return 0;
        }
        
        if(dp[ind][c]!=-1) return dp[ind][c];
        int nottake=solve(ind-1,c,price,dp);
        int take=INT_MIN;
        if(c>=(ind+1))
        {
            take=price[ind]+solve(ind,(c-(ind+1)),price,dp);
        }
        return dp[ind][c]=max(nottake,take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};