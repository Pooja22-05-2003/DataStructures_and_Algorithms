string findLCS(int n, int m,string &text1, string &text2){
	// Write your code here.
	    int n1=n;
        int n2=m;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        
        // right shift by 1 index
        for(int i=0;i<=n1;i++) dp[i][0]=0;
        for(int i=0;i<=n2;i++) dp[0][i]=0;
        
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                 int take=0;
                 if(text1[ind1-1]==text2[ind2-1])  // index-1 we are doing , becuase we considered the right shift
                 {
                     take=1+dp[ind1-1][ind2-1];
                 }
        
                 // not take 
                 int  nottake=max(dp[ind1-1][ind2],dp[ind1][ ind2-1] );
        
                 dp[ind1][ind2]=max(nottake, take);
            }
        }	


		// backtract the dp array and get the string
		string ans="";
		int len=max(n,m);

		for(int i=0;i<=len;i++) ans+='$';
	// cout<<"ans:"<<ans<<endl;
		int i=n1;
		int j=n2;
		int ind=len-1;
		while(i>0 && j>0)
		{
			if(text1[i-1]==text2[j-1])
			{
				ans[ind]=text1[i-1];
				ind--;
				i--;
				j--;
			}
			// we are not considerign mutliple ans possible cases, for that u need to go through the brute force approach
			else if(dp[i][j-1]>dp[i-1][j])
			{
				j--;
			}
			else{
				i--;
			}
		}

		string res="";
		for(int i=0;i<ans.size();i++)
		{
			
			if(ans[i]!='$') res+=ans[i];
		}

		return res;
}