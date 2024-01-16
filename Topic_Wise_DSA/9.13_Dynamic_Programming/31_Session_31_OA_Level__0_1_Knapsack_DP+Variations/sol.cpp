/*
Approach :

1. Why DP🤔🧠: It is because , At each index , we have multiple options , and at last we 
need to return the best possible answer.
2. So we need to explore all the possible cases. And we will use DP for that .
3. 1-D DP??? or 2-DP???--? Ans: 2-D Dp because we have 2 variables profit and weight and we need to both of them at each index.

4. At each index we have 2 options whether to pick the current element or to not pick the current element. (PICK/NOT PICK).
5. dp[i][j]=> It repersent the best answer till index i, when the capacity of the bag is j.


*/

/*
Approach :

1. Why DP🤔🧠: It is because , At each index , we have multiple options , and at last we 
need to return the best possible answer.
2. So we need to explore all the possible cases. And we will use DP for that .
3. 1-D DP??? or 2-DP???--? Ans: 2-D Dp because we have 2 variables profit and weight and we need to both of them at each index.

4. At each index we have 2 options whether to pick the current element or to not pick the current element. (PICK/NOT PICK).
5. dp[i][j]=> It repersent the best answer till index i, when the capacity of the bag is j.


*/
// TC=O(N*capacity)
// SC=O(N*capacity)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,int capacity, vector<int> weight , vector<int> profit){
   vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

   // we can directly start with the for loop, as the base case , index 0 is already initialized.
   int i=1;

   while(i<=n){

    // current weight is reprented by j and it will go  from 1 to Capacity
    int j=1;
    while(j<=capacity){
        // not take.
        int NotTake=dp[i-1][j];

        int Take=0;
        // take.
        // j is working as the maximum capacity at the current index j.
        if(j>=weight[i]) Take=profit[i]+dp[i-1][j-weight[i]];

        dp[i][j]=max(Take,NotTake);
 
        j++;
    }

    i++;
   }

   return dp[n][capacity];
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

    int capacity;
   cin>> capacity;
   vector<int> profit(n+1);
   for(int i=1;i<=n;i++){
    cin>>profit[i];
   }

   vector<int> weight(n+1);
   for(int i=1;i<=n;i++){
    cin>>weight[i];
   }

 
    int ans=solve(n,capacity,weight,profit);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
3
50
60 100 120
10 20 30


// output1:
220


Input2:
3
3
1 2 3
4 5 6



// output 2:
0

input3:


output:


input4:

output: 



*/