// ✅✅ Passing all test cases. (Karandeep solution)
class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n, 0);

        if(n>0 and s[n-1]!='0')
        dp[n-1] = 1;

        if(n-2>=0){

            if(s[n-2] == '0')
            dp[n-2] = 0;

            else
            dp[n-2] = dp[n-1] + ((s[n-2]-'0')*10 + (s[n-1]-'0')<=26 ? 1 : 0);
      
        }
        for(int i=n-3;i>=0;i--){

            if(s[i] == '0'){

                dp[i] = 0;
                continue;

            }

            int num = (s[i]-'0')*10 + (s[i+1]-'0');

            if(num<=26)
            dp[i] = dp[i+2];

            dp[i]+=dp[i+1];

        }

        return dp[0];

    }
};