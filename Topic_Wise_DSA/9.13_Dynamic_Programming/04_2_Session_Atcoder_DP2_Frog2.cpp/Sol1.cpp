
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n , int k ){
    int dp[n+1];
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1])+dp[1];
    // dp[3]=min((dp[1]+abs(arr[3]-arr[1])), (dp[2]+abs(arr[3]-arr[2])));

    int i=3;
    while(i<=n){
        int minn=INT_MAX;
        for(int m=1;m<=k;m++){
        minn=min(minn,dp[i-m]+abs(arr[i]-arr[i-m]));
        }
        dp[i]=minn;
        // dp[i]=min((dp[i-2]+abs(arr[i]-arr[i-2])), (dp[i-1]+abs(arr[i]-arr[i-1])));
        i++;
    }
    return dp[n];

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********
    // 1-- based indexing are used here

    int n;
    cin >> n ;
    int k;
    cin>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
   
        cin>>arr[i];
    }

  
    cout<<solve(arr,n,k)<<endl;
}






/*
input :
10
4
40 10 20 70 80 10 20 70 80 60

output :
40

*/




