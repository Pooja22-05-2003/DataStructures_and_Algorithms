// Optimized solution-DP solution
// TC=O(n2)
// Sc=O(n2)
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        // consider substring for len=1;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        // for len=2
        int i=0;
        while(i<=(n-1))
        {
            if(s[i]==s[i+1]) dp[i][i+1]=1;
            i++;
        }

        int len=3;
        while(len<=n)
        {
            int i=0;
            int endInd=(n-len);
            while(i<=endInd)
            {
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j]=1;

                i++;
            }
            len++;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j]==1) ans++;
            }
        }

        return ans;
    }
};