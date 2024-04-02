// Memoization
// TC=O(len1*len2)
// SC=O(len1*len2)+O(len1+len2)

class Solution {
public:
    int solve(int ind1, int ind2, string text1 , string text2,vector<vector<int>>&dp)
    {
        // base case
        if(ind1<0 || ind2<0) return 0;
    
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
       
        int take=0;
        if(text1[ind1]==text2[ind2])
        {
            take=1+solve(ind1-1, ind2-1, text1, text2,dp);
        }
        
         // not take 
        int  nottake=max(solve(ind1-1, ind2, text1, text2,dp),solve(ind1, ind2-1, text1, text2,dp));
        
        return dp[ind1][ind2]=max(nottake, take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1, n2-1,text1, text2,dp);
    }
};