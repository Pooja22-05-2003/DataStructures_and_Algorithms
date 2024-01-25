// TC=O(n*m)
// SC=O(n*m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        int i=1;
        while(i<=n1){
            int j=1;
            while(j<=n2)
            {
                // take 
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                    
                else   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                

                j++;
            }

            i++;
        }
        return dp[n1][n2];
    }
};