/*
Problem Explaination in short:
1. Given an array A of size N and an element K.
2. You need find the minimum  length of the valid subsequence.
3. Valid Susequence include:
  -> 1.Subsequence should be increasing.
  -> 2. Sum of all elements of the subsequence must be atleast k.
  -> 3. We need to find the minimum length of the good subsequence , else return -1.

Constraints:
1<=N<=500(5*10^2)
1<=K<=100000000(10^8)
*/

/*
Approach:
1. Which data structure to use??
=> As we need to find the valid subsequence and also of minimum length, So we need to explore all the possible paths.
=> while exploring we can reuse the previous to compute the current state.So definitely we can use DP here.

2. Let's try to define the right defintiion of DP[i](Right Defition of DP is very imp)
2. Dp[i]=> It denote the minimum length of valdid subsequence and it must include the last element in the subsequence.
valid include 2 parameters:
->Increasing (This can be tracked using 1D Dp)
->Sum must be grater than equal to k. [This Need 1 more DP state]
-> Minimum [This can also be tracked in the 1D Dp].


3. Dp[i][j]=> It will denote tha valid subsequence till index i, which include the last element in the subsequence and the sum of the subsequence must be 'j'.

*/

// TC=O(N*N*Sum) => 10^2*10^2*10^8 (This complexity will not be accepted in Google OA)-> So try to remove the K term in the complexity
// SC=O(N*sum)

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

