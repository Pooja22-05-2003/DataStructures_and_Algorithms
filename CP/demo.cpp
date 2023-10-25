// TC=O(N)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr  ){
    int n=arr.size();
    int dp[n+1];
    memset(dp,0,n+1);
    int ans=0;
    //  here dp[1]!=arr[1] beacuse negative value are also allowed
    // So taking 0 is better then taking negative value.
    dp[1]=max(arr[1],ans);
    dp[2]=max(arr[2],dp[1]);
    // dp[3]=max(arr[3]+dp[1],dp[2]);

    //  general formula 
    // dp[i]=max(arr[i]+dp[i-2],dp[i-1]);

    for(int i=3;i<=n;i++){
        dp[i]=max((arr[i]+dp[i-2]),dp[i-1]);
    }

    return dp[n];


}
int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********
    // 1-- based indexing are used here

    int n;
    cin >> n ;
    
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr)<<endl;
}

/*

6
1 2 -1 -2 3 


output :

*/
