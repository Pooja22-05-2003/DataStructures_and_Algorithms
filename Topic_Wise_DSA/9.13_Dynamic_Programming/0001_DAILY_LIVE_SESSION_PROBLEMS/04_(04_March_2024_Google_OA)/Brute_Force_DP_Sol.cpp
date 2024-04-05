

// TC :- O(N*b[i]*b[i]) = O(N*U*U) U = max(b[i]) 

// SC=O(1)

#include <bits/stdc++.h>
using namespace std;

int solve( int n, vector<int>b)
{
    vector<vector<int>>dp(n+1,vector<int>(100000,0));
    vector<vector<int>>special();
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=b[i];j++)
        {
            for(int second_last_val=1;second_last_val<=(b[i-1]);second_last_val++)
            {
                int  G = abs(second_last_val-j) + dp[i-1][second_last_val];
               dp[i][j] = max(dp[i][j],G)  ;

            }

            int r=0;
            for(int second_last_val=b[i];second_last_val<=100000;second_last_val++)
            {
               r=max(dp[i][j], special[i][j]) ;

            }

            dp[i][j]=max(dp[i][j],r-j);
            special[i][j]=dp[i][j]+j;
        }
    }

    int ans=INT_MIN;
    for(int i=1;i<=100000;i++)
    {
        ans=max(ans,dp[n][i]);
    }

    return ans;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin >> n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int ans=solve(n,arr);
    cout<<"ans:"<<ans<<endl;
    return 0;
}

/*
input1 :


Output 1:



input1 :


Output 1:






*/
