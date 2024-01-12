/*
Optimized approach:
1. If the constraint is 10^5 , then O(n2)=10^10 and this much value will not get accepted, so try to optimize it.
2. If we observe, then any dp[i] , there are two possible , that the last element we are including is a[i] or the last element is from b, so we can create 2D  , as it is the nees to create new states.
dp[i][a]=It denotes the best answer till index i, when the last element included is a[i].
dp[i][b2]= It denotes that we need at least take 2 element from b array.

dp[i][b2]=dp[i-1][a],dp[i-1][b]



Actual General formula.

dp[i][a]=a[i]+min(dp[i-1][a],dp[i-1][b])
dp[i][b]=b[i]+b[i-1]+min(dp[i-2][a],dp[i-2][b1]);

dp[i][b1]=b[i]+ min(dp[i-1][a],dp[i-1][b1]);


3. Do iterate till n and return min(dp[n][a],dp[n][b2])
*/

// TC= O(N2)
// SC= O(N)
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> a , vector<int>&b, int n ) 
{
   vector<vector<int>>dp(n+1,vector<int>(3,0));
   dp[1][0]=a[1]; // dp[i][0] means considering a
   dp[1][1]=b[1];
   dp[1][2]=INT_MAX; // till index 1 we can't cosider 2 elements.

   int i=2;
   while(i<=n){
    int t1=a[i]+min(dp[i-1][2],dp[i-1][0]);
    int t2=b[i]+b[i-1]+min(dp[i-2][1],dp[i-2][0]);
    int t3=b[i]+min(dp[i-1][1],dp[i-1][0]);

    dp[i][0]=t1;
    dp[i][1]=t3;
    dp[i][2]=t2;

    i++;
   }
   return min(dp[n][0], dp[n][2]); 
   
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

    vector<int>arr1(n+1);
    vector<int> arr2(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }

    cout<<solve(arr1,arr2,n);

	return 0;
}
	


/*
// input1 :
5
3
5 
2 
1 
9 
1 
1 
10 
5 
3 


// output1:
12


// input 2 :
12
16
20
12
12
8
2
3
8
17
3
14
8
16
17
1
2
20
17
1
3
9
8
10
16


// output 2:
84


154 but output is 84
*/