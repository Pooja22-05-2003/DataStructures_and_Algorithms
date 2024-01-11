/*
Approach :
1. dp[0]=0, As , in the case when we consider the whole string, then we need the dp[i-1] answer and here dp[0] is needed.
2. dp[i] => It denotes the best answer till index i of string . Means minimum number of Beautiful partition of string till index i.
3.dp[1]=> If the string is 0 , then dp[0]=0, because it is violating both the conditions.
4. dp[2]=> take one j pointer and start doing partition from j=i-1 till 1. and caluate the minimum answer among all dp states.
5. And at final dp[i] will store the minimum answer for all possible j for index i.
6. Do this in the for loop and return the dp[n] as the final answer, as that will store the best answer till index n.
*/
// TC=O(n2)
// SC=O(n)

class Solution {
public:
    bool check(string s, int st , int end){
          int num=0;
          int i=end;
          int cnt=0;
        //   cout<<"st:"<<st<<" end:"<<end<<endl;
          while(i>=st && i>=0){
            //   cout<<"i:"<<i<<" s[i]:"<<s[i]<<" cnt:"<<cnt<<" pow:"<<pow(2,cnt)<<endl;
              if(s[i]=='1') num=num+pow(2,cnt);
            //   cout<<"num:"<<num<<endl;
              
              cnt++;
            //   cout<<"cnt:"<<cnt<<endl;
              i--;
          }

        // cout<<"final num:"<<num<<endl;
          if(num!=0 && 15625 % num==0) return true;
          else return false;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();

        // Here if the dp[n] will conatian 100 , it means there is no valid partition exist in the dp, so we return -1 as the final answer.
        if(s.size()==1 && s[0]=='0') return -1; 
        vector<int>dp(n+1,100);
        dp[0]=0;
        if(s[0]=='0') dp[1]=0;
        else dp[1]=1;

        int i=1;
        while(i<n){
            int j=i;
            while(j>=0){
                int st2=j;
                int end2=i;
                
                if(s[st2]!='0' && check(s,st2,end2)==true && dp[j]!=100)
                {
                    
                    dp[i+1]=min(dp[i+1],1+dp[j+1-1]);
                }
                j--;
            }

            i++;
        }

        if(dp[n]!=100) return dp[n];
        else return -1;
    }
};


// 2^15= 32,768
// 5^6=  15,625  // this is the maximum number till which this 5^x will go.
// 5^7=78,125