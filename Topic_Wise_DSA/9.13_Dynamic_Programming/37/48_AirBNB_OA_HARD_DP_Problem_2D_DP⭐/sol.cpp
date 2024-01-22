// ⭐⭐⭐⭐⭐⭐⭐
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>a,vector<int>b) {
    vector<vector<int>>dp(n+1,vector<int>(3,0));
        /* dp[i][1] --> Min cost it means min cost to solve the problem 
     such that ith index is the last index of array and first you pick 
     the ith index only then u r allowed to pick i-1 index  */
     
    /* dp[i][2] --> Min cost it means min cost to solve the problem 
     such that ith index is the last index of array and first you pick 
     the (i-1)th index only then u r allowed to pick iTH index  */

     dp[1][1]=0; // As there is only 1 element and removal of 1 element cost =0;
     dp[1][2]=0; // As there is only 1 element and removal of 1 element cost =0;
     
     dp[2][1] = a[2]; // For 2ndIndex, Last, you are first removing (2)nd and the 1st
     dp[2][2] = a[1];// For 2ndIndex,2ndLast, you arr first removing 1 and then 2nd.

      for(int i=3;i<=n;i++){
         
         dp[i][1]=a[i]+min(dp[i-1][1],dp[i-1][2]);
         
         // for dp[i][2] 
         int opt1 = b[i-1]+0+min(dp[i-2][1],dp[i-2][2]); // removed i-1 at last 

         int opt2 = dp[i-1][2]+a[i-1]; // removed the i-1 at 2ndLast, buttt a[i] is present 
         
         dp[i][2]=min(opt1,opt2);
     }

     return min(dp[n][1],dp[n][2]);
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
    vector<int>a(n+1);
    vector<int>b(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int ans=solve(n,a,b);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
6
0 5 2 10 7 9
0 3 1 4 5 6

// output1:
6


Input2:


// output 2:



input3:


output:




*/