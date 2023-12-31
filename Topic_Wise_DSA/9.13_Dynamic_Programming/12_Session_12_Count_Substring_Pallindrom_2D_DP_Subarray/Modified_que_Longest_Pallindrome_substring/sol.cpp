// Optimized version - Using DP
// TC=O(n2)
// SC=O(n)
class Solution {
public:
   
    int longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        // d[i][j]==1 if s[i] to s[j].....is Pallindrome.
        // So for all the strings of length=1 , dp[i][j]=1, As 1 char length is always a pallindrome.

        int cnt=0;
        int longest_Pallindrome_Substring=0;
        // For substring of len=1
        int i=0;
        while(i<n){
            dp[i][i]=1;
            longest_Pallindrome_Substring=1;
            cnt++;
            i++;
        }


        // For substring of len=2;
        i=0;
        while(i<n-1){
            if(s[i]==s[i+1]) {
                dp[i][i+1]=1;
                longest_Pallindrome_Substring=2;
                cnt++;
                }
            else dp[i][i+1]=0;
            i++;
        }


        // For substring of len=3 and more.
        int len=3;
        while(len<=n){
        i=0;
        while(i<n-len+1){
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1) {
                longest_Pallindrome_Substring=max(longest_Pallindrome_Substring,len);
                dp[i][j]=1;
                cnt++;
                }
            else dp[i][j]=0;

            i++;
        }
        len++;
        }
        return longest_Pallindrome_Substring;

    }
};





