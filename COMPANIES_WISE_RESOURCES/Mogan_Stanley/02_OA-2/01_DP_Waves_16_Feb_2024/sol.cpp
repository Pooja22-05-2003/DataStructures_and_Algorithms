/*
Approach:
1. Question is asking for total number of ways to replace the all -1.
2. There are two types of waves can be formed.
3. First is  [up -> down -> up] // even dp[i-1][1]+dp[i-1][2].....dp[i-1][j-1].
   Second is [Down -> Up -> Down] // odd dp[i-1][j+1] + dp[i-1][j+2].....dp[i-1][m].
4. How can we do this with dynamic programming :- 

dp[............................................................................N]. 

dp[i] = best answer(total number of ways) to create type1-wave; till index “i”(1 to i) 

Final answer -> dp[n].

Last step to solve dp problem :- Make a formula. 

dp[i][j] = number of ways to create a type1 and type2 wave till index “i” such that the number at 
index “i” is assumed to be j. If b[i] = -1; or else you have to take the fixed number .


*/

/*

*/

// Not wholy correct , need to do update
// TC=O(n)
// SC=O(n)
#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int  solve(int n, int m,vector<int>arr){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    // if arr size is 1
    if(arr[1]==-1)
    {
        for(int k=1;k<=n;k++)
        {
            dp[1][k]=1;
        }
    }
    else 
    {
        dp[1][arr[1]]=1;
    }

    // for arr of size =2 to n
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==-1)
        {
            // if the current element is -1, then it have the el as from up wave also and down wave.
            // if we are considering ans for dp[i][j] come from down wave , then dp[i-1][1]+dp[i-1][2]+.....dp[i-1][j-1]

            // j can be any value from 1 to m
            for(int j=1;j<=m;j++)
            {

                // Up wave=> previous numbers are smaller than j
                for(int k=1;k<=j-1;k++)
                {
                    dp[i][j]=dp[i][j]+dp[i-1][k];
                }

                // for down wave => down up down
                for(int k=j+1;k<=m;k++)
                {
                    dp[i][j]=dp[i][j]+dp[i-1][k];
                }
            }
        }
        else 
        {
            // store for all the previous j values from 1 to arr[i]-1....to.....arr[i]+1 to m
            for(int k=1;k<=m;k++)
            {
                if(k!=arr[i])
                {
                    dp[i][arr[i]]+=dp[i-1][k];
                    dp[i][arr[i]]=dp[i][arr[i]]%MOD; //// Applying modulo to avoid overflow
                }
            }
        }
    }

    int ans=0;

    if(arr[n]==-1)
    {

    }
    else 
  
  
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********


    int n,m;
    cin>>n>>m;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(n,m,arr)<<endl;

	return 0;
}
	

/*
input1 :
bbacdbdd


Output 1:
acbd



input2 :
aabcb




Output2:

abc 


*/


