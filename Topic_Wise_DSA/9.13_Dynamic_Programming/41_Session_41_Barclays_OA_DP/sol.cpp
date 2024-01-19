
// TC=O(N)
// SC=O(N*3)

#include<bits/stdc++.h>
using namespace std;

  int solve(int n , vector<int>easy,vector<int>hard) {
    // At any day , we have 3 options , so we will make dp state for each of the three.
    vector<vector<int>>dp(n+1,vector<int>(3,0));

    dp[1][0]=easy[1];
    dp[1][1]=hard[1];
    dp[1][2]=0;

    int i=2;
    while(i<=n){
        // picking the easy task at the ith day.
        dp[i][0]=easy[i]+max(dp[i-1][0],max(dp[i-1][1],dp[i-1][1]));

        // picking hard taks at the ith day
        dp[i][1]=hard[i]+max(dp[i-2][0],max(dp[i-2][1],dp[i-2][1]));
        // not picking any task
        dp[i][2]=0+max(dp[i-1][0],max(dp[i-1][1],dp[i-1][1]));
        i++;
    }

    return max(dp[n][0],max(dp[n][1],dp[n][1]));
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
    
    vector<int>easy(n+1);
    for(int i=1;i<=n;i++){
        cin>>easy[i];
    }

    vector<int>hard(n+1);
    for(int i=1;i<=n;i++){
        cin>>hard[i];
    }



    int ans=solve(n,easy, hard);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
4
1
4
20
2
2
10
21
23


// output1:
33



Input2:


// output 2:



input3:


output:


input4:

output: 



*/