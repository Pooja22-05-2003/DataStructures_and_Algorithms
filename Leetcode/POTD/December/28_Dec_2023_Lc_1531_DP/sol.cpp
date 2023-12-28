//Not Mine solution 
int dp[101][101][27][101]; // now using heap memory...if in class then stack memory hence runtime error
class Solution {
public:
   
    int solve(int i,int k,int prev,int prev_count,string&s){
        if(k<0)return 1e9;
        if(i==s.size())return 0;
        if(dp[i][k][prev][prev_count]!=-1)return dp[i][k][prev][prev_count];
        int notake=solve(i+1,k-1,prev,prev_count,s);
        int take=0;
        if(s[i]==(prev+'a')){
            take=solve(i+1,k,prev,prev_count+1,s);
            take+=(prev_count==1 || prev_count==9 || prev_count==99);
        }
        else take=1 +solve(i+1,k,s[i]-'a',1,s);
        return dp[i][k][prev][prev_count]= min(take,notake);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,26,0,s);
    }
};
