/*
Approach :
1. As now we have 2 bags , so 1 dp state will increase.
*/
// TC=O()
// SC=O()

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,int capacity1,int capacity2, vector<int> weight , vector<int> profit){
   vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(capacity1+1,vector<int>(capacity2+1,0)));

   // we can directly start with the for loop, as the base case , index 0 is already initialized.
   int i=1;

   while(i<=n){

    // current weight is reprented by j and it will go  from 1 to Capacity
    int j=1;
    while(j<=capacity1){
        int k=1;
        while(k<=capacity2){
        // not take.
        int NotTake=dp[i-1][j][k];

        int Take=0;
        // take.
        // j is working as the maximum capacity at the current index j.
        if(j>=weight[i]) Take=profit[i]+dp[i-1][j-weight[i]][k];
        if(k>=weight[i]) Take=max(Take,profit[i]+dp[i-1][j][k-weight[i]] );
        dp[i][j][k]=max(Take,NotTake);

        k++;
        }
 
        j++;
    }

    i++;
   }

   return dp[n][capacity1][capacity2];
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

   int capacity1;
   cin>> capacity1;

   int capacity2;
   cin>>capacity2;
   vector<int> profit(n+1);
   for(int i=1;i<=n;i++){
    cin>>profit[i];
   }

   vector<int> weight(n+1);
   for(int i=1;i<=n;i++){
    cin>>weight[i];
   }

 
    int ans=solve(n,capacity1,capacity2,weight,profit);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :



// output1:



Input2:
3
3
3
1 2 3
4 5 6




// output 2:
0

input3:
3
50
50
60 100 120
10 20 30

output:
280

input4:

output: 



*/