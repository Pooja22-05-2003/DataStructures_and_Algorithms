// TC=O()
// SC=O()

#include <bits/stdc++.h>

using namespace std;
int solve(int n,int sum,vector<int>arr)
{
    vector<vector<int>>dp(n+1,vector<int>(sum,INT_MAX));
    // fill the base case (for i=1)

    for(int j=0;j<=sum;j++)
    {
        if(arr[1]>=j) dp[1][j]=1;
    }

    int i=2;
    while(i<=n)
    {
        int j=0;
        
        while(j<=sum)
        {            
            if(arr[i]>=j)
            {   // that single element can be the valid subsequence
                dp[i][j]=1;
                
            }
            else 
            {
                int v=1;
                while(v<=(i-1))
                {
                    // increasing subsequence
                    if(arr[v]<=arr[i])
                    {
                        if(j-arr[i]>=0)
                        {
                            if(dp[v][j-arr[i]]!=INT_MAX)
                            {int temp=dp[v][j-arr[i]]+1;
                            dp[i][j]=min(dp[i][j],temp);}
                        }
                        
                    }
                    v++;
                }

            }
            j++;
        }
        i++;
    }

    // Final ans would be the min of dp[1][sum]......dp[n][sum]
    int ans=INT_MAX;
    i=1;
    while(i<=n)
    {
        ans=min(ans,dp[i][sum]);
        i++;
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