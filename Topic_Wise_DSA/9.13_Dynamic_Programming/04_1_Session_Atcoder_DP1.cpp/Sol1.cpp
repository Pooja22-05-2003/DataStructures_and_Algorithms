
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n  ){
    int dp[n+1];
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1])+dp[1];
    // dp[3]=min((dp[1]+abs(arr[3]-arr[1])), (dp[2]+abs(arr[3]-arr[2])));

    int i=3;
    while(i<=n){
        dp[i]=min((dp[i-2]+abs(arr[i]-arr[i-2])), (dp[i-1]+abs(arr[i]-arr[i-1])));
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
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
   
        cin>>arr[i];
    }

  
    cout<<solve(arr,n)<<endl;
}






/*
input :
4
10 30 40 20

output :
30

test case 2:

input :
2
10 10

output :
0


Test case 3:
Input :
6
30 10 60 10 60 50

Output :
40



*/




