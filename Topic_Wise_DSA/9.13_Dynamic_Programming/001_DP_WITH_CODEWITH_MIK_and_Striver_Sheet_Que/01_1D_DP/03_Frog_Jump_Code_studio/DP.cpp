//TC=O(n)
//SC=O(n)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &v)
{
    // Write your code here.
    
    if(n<=1) return 0;

    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0] );  // energy lost during jump from index 1 to index 0.
    dp[2]=min((abs(v[2]-v[1])+dp[1]), (dp[0]+abs(v[2]-v[0])));

    for(int i=3;i<n;i++)
    {
        // at every step , i have 2 options and I will store the best answer in my dp[i]
        dp[i]= min((abs(v[i]-v[i-1])+dp[i-1]),(abs(v[i]-v[i-2])+dp[i-2]));
   
    }
    return dp[n-1];

}

/*
7 4 4 2 6 6 3 4 
0 1 2 3 4 5 6 7

dp[1]=3
dp[2]=3
dp[3]=5
dp[4]=min(9,5)=5
dp[5]=min(5,9)=5
dp[6]=min(8,8)=8
dp[7]=min(9,7)=7

*/