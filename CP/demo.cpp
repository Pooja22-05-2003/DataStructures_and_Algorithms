// TC=O(N2)
// SC=O(N2)

#include <bits/stdc++.h>

using namespace std;
int solve(int n,int sum,vector<int>arr)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    dp[1][1]=arr[1];
    int i=2;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            int l=1;
            while(l<=(i-1))
            {
            if(arr[l]<=arr[i])
            {
                dp[i][j]=max(dp[i][j],arr[i]+dp[l][j-1]);

            }
            l++;
            }

            j++;
        }
       

        i++;
    }
   
   int ans=INT_MAX;
   for(int i=1;i<=n;i++)

   {
    for(int j=1;j<=i;j++)
    {   
        // Here u need to find the min between j and ans and not dp[i][j],ans
        if(dp[i][j]>=sum) ans=min(j,ans);
    }
   }

   return ans;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    //

    //*********
   
    int n;
    cin>>n;

    int k;
    cin>>k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    
    int ans=solve(n,k,arr);
    cout<<ans<<endl;
    
    return 0 ; 
}
/*
// // input1 :
5 
7
1 2 3 5 4 


// // output1:
2

// // input1 :

// // output1:

// */