❌❌ Not Passing all the test cases

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==1 && s[0]=='0') return 0;
       if(s.size()==1) return 1;
       else {
           int n=s.size();
           vector<int> dp(n+1,0);
           if(s[0]!='0' )dp[0]=1;
           else return 0;
           char temp=s[1];
           int t=temp-'0';
           char prev=s[0]-'0';
           string ss=string(1,s[0])+string(1,s[1]);
           int total=stoi(ss);

           if(total<=26 && temp!='0') dp[1]=dp[0]+1;
           else dp[1]=dp[0];
           if(s.size()==2) return dp[1];


           for(int i=2;i<n;i++){
           
           char temp=s[i];
           int t=temp-'0';
           char prev=s[i-1]-'0';
           
           string ss=string(1,s[i-1])+string(1,s[i]);
           int total=stoi(ss);
           if(s[i]=='0') dp[i]=0;
           else if(total<=26 && temp!='0') dp[i]=dp[i-1]+1;
           else dp[i]=dp[i-1];
           cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
           }
           cout<<"n-1:"<<n-1<<"dp[4]:"<<dp[n-1]<<endl;
            return dp[n-1];
       }


    }
};


