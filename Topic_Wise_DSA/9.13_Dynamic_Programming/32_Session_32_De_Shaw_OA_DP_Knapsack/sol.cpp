/*
Observation :
1. We can get the multiple quantity of the same item.but there is a restriction of picking any 
quantity in the range of min quantity and max quantity.
2. So, we have 2 options to pick that element or not pick that element , just like knapsack problem.
3. And we also need to take care of the which we can't exceed beyond the budget.
4. WHY TO APPLY DP?? 🧠🤔: As we have multiple options and we need to pick the best.So, explore all the
possible possibles.
5. In gerneral dp[i]=> Denotes the maximum happiness we can achieve till index 'i'.But also there is 1 money factor which u need to consider.
6. dp[i][j]=> It denotes, the maximum happiness , we can achieve till index 'i', when we are forced to buy atleast 1 item of index 'i' and we have maximum 'j' amount of money.
 i will go from 1 to n and j will go from 0 to budget.

 dp[0][0] , dp[0][1]...=> INT_MIN, when i =0 , we don't have any item so answer will be INT_MIN.

base case . dp[1][0]=INT_MIN; it was compulsory to buy at least 1 time; you cant even do that so answer is INT_MIN. 

dp[1][j].....till j is less than cost of i item , it will be INT_MIN.


*/
/*
Approach :

*/
// TC=O(N3)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>happy, vector<int> cost, vector<int>minn, vector<int>maxx,int budget){
    vector<vector<int>> dp(n+1,vector<int>(budget+1,0));

    // intialize all the dp value with INT_MIN
    // int i=0;
    // while(i<=n){
    //     int j=0;
    //     while(j<=budget){
    //         dp[i][j]=INT_MIN;
    //         j++;
    //     }

    //     i++;
    // }

    int i=1;
    while(i<=n){
            int j=1;
            while(j<=budget){

                // minimum quantity of each item which we can take,
                
                int t=minn[i];
                while(t<=maxx[i]){
                    int costt=cost[i]*t;
                    // int notTake=0+dp[i-1][j];
                    if((j-costt)>=0) dp[i][j]=max(dp[i][j],((happy[i]*t)+dp[i-1][j-costt]));
                    t++;
                }
            //  cout<<i<<" "<<j<<" "<<dp[i][j];
                j++;
            }
      i++;
    }

    return dp[n][budget];
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

    vector<int> cost(n+1);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }

    vector<int> happy(n+1);
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }

    vector<int> minn(n+1);
    for(int i=1;i<=n;i++){
        cin>>minn[i];
    }

    vector<int> maxx(n+1);
    for(int i=1;i<=n;i++){
        cin>>maxx[i];
    }

    int budget;
    cin>>budget;

 
    int ans=solve(n,cost,happy,minn,maxx,budget);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
3
2 4 3 
2 1 3
2 1 1 
4 3 1 
30 


// output1:
23


Input2:




// output 2:


input3:


output:


input4:

output: 



*/