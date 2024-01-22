
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    
    // dp[i][0]--> denote all vertical and horizontal combo(Full) dp[i][full]
    // dp[i][1]--> denote one right part is bulge out. dp[i][right].
    // dp[i][2]--> denote one left part is bulge out. dp[i][left].

    dp[1][0]=0;  // As there are 3 col and only 1 row. (we can't place 1*2 tile by filiing the whole matrix).
    dp[1][1]=0;
    dp[1][2]=0;
    dp[2][0]=3;
    dp[2][1]=1;
    dp[2][2]=1;

    int i=3;
    while(i<=n){
        dp[i][0]=(3*dp[i-2][0])+dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-2][1]+dp[i-2][0];
        dp[i][2]=dp[i-2][2]+dp[i-2][0];

        i++;
    }
    return dp[n][0];
    
 }


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int n;
    cin>>n;

    int ans=solve(n);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
4

// output1:
9


Input2:
5

// output 2:
14


input3:
6

output:
31

input4:

output: 



*/