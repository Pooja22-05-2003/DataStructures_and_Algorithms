
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;

    // general forumula : dp[i]=(4*dp[i-2])+dp[i-1]
    dp[3]=6;
    int i=4;
    while(i<=n){
        dp[i]=dp[i-1]+(4*dp[i-2]);
        i++;
    }
    return dp[n];
    
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
14


Input2:
5

// output 2:
38


input3:


output:


input4:

output: 



*/