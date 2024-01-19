/*
Problem in 1 Line:
1. Given an array, u are index 1 and u need to reach at index n , or want to cross n.
2. 2 options are there at each index
  -> From index take 2 jumps forwars.
  -> Or take 1 jump backward.
3. NOTE:- You can visit any index for only 1 times.
At whatever index u are reaching, add that to you total sum.


Approach:
1. At any index we don't know the best minimum cost will come from backward or from forward.
So, We need to explore all the possible paths.
2. Which DATA STRUCTURE???:-🤔🤔 DP: In dp we explore all the possible paths and store the best possible at each index.
3. dp[i]=> It denotes the best possible answer till index 'i'.
4. But there are 2 options , whether to move forward, or backward.
5. So whatever thing is creating problem , try to make state for that.
6. dp[i][forward]=> It means best possible answer till index 'i' , when we come at index 'i' through forward step.
   dp[i][backward]=> It means best possible answer till index 'i' , when we come at index 'i' through the previous step as backward.
*/

// TC=O(N)
// SC=O(N*3)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int>b) {
    vector<vector<int>>dp(n+1,vector<int>(2,INT_MAX));

    // dp[i][0]=> 0 is denoting the forward
    // dp[i][1]=> 1 is denoting the backward.

    dp[1][0]=b[1]; // we are standing at index , so that's why we are including the cost of b[i]
    dp[1][1]= 1000000;    /// at index 1 , we are assuming that arr size is 1, so there is no possiblity at index 1 that we can come from backward.
    dp[2][0]=1000000;
    dp[2][1]=dp[1][0]+b[3]+b[2];  // jump is from index1(forward)---> index3(backward)---->index2

    int i=3;
    while(i<=n-1){
        dp[i][0]=b[i]+min(dp[i-2][0],dp[i-2][1]);
        dp[i][1]=b[i]+b[i+1]+(dp[i-1][0]);
        //   cout<<"i:"<<i<<","<<dp[i][0]<<","<<dp[i][1]<<endl;
        
        i++;
    }
    dp[i][0]=b[i]+min(dp[i-2][0],dp[i-2][1]);
    // At last index, we can't come from backward at index i
    dp[i][1]=1000000;
  
    return min((dp[n][0]),min(dp[n-1][0],dp[n-1][1]));
    
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
    
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }


    int ans=solve(n,arr);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
3
2 
5
8


// output1:
10



Input2:
4
2 
5
8
7

// output 2:
10


input3:


output:


input4:

output: 



*/