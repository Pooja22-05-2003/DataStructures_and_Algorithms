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