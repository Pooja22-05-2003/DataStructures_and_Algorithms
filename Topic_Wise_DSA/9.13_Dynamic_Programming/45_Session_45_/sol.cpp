// TC=O(n)
// SC=O(n)
class Solution {
public:
    int numTilings(int n) {
        vector<int>dp(n+1,0);
        vector<int>dp_up_tromino(n+1,0);
        vector<int>dp_down_tromino(n+1,0);

        // dp will store the combination of vertical and horizontal tiles combo
        dp[1]=1;
        if(n>=2) dp[2]=2;
        if(n>=3) dp[3]=3;

        // dp_up_tromino[i]=> Store the maximum possible way to place tiles, when tromino upper part is bulge out.
        // -----
        // |
        // |

        dp_up_tromino[1]=0;
         if(n>=2) dp_up_tromino[2]=1;

        // For explaination see the github repository image 1
         if(n>=3) dp_up_tromino[3]=2;

        dp_down_tromino[1]=0;
         if(n>=2)  dp_down_tromino[2]=1;

        // For explaination see the github repository image 1
         if(n>=3) dp_down_tromino[3]=2;

         dp[1]=1;
         if(n>=2) dp[2]=2;
         if(n>=3) dp[3]= 5;
        int i=4;
        while(i<=n){
            dp[i]=dp[i]% 1000000007;
            dp[i]+=dp[i-1];// when the vertical tile is added
             dp[i]=dp[i]% 1000000007;
            dp[i]+=dp[i-2]; // when horizontal time is added in the last 2 horizontal position.
            dp[i]=dp[i]% 1000000007;
            dp_up_tromino[i-1]=dp_up_tromino[i-1]% 1000000007;
            dp[i]+=dp_up_tromino[i-1];// when the last tile is up tromino(means upper part is bulge out).
            dp[i]=dp[i]% 1000000007;
            dp_down_tromino[i-1]=dp_down_tromino[i-1]% 1000000007;
            dp[i]+=dp_down_tromino[i-1];// when the last tile is down tromino(means upper part is bulge out).
            dp[i]=dp[i]% 1000000007;
            dp_up_tromino[i]=dp_up_tromino[i]% 1000000007;
            dp_up_tromino[i]=dp[i-2]+dp_down_tromino[i-1];

            dp_down_tromino[i]=dp_down_tromino[i]% 1000000007;
            dp_down_tromino[i]=dp[i-2]+dp_up_tromino[i-1];

            i++;
        }

        return dp[n];
    }
};