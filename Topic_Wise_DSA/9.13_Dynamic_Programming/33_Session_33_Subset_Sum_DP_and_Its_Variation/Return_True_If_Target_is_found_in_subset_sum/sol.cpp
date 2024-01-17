/*
1. WHY DP?? 🤔🧠 As we need to explore all the possible paths , so we use and explore all the subset.
2. Similar to knapsack at each index, we have 2 options , first is whether to pick the current index element or
 to not pick the current index element.
3. dp[i][j]=> It will store TRUE, if till index 'i' we were able to find the subset with sum 'j'.
4. dp[0][0]- store ture as till index 0, we have the subset sum 0.

*/

/*
Approach :

*/
// TC=O(N*target)
// SC=O(N*Target)

#include<bits/stdc++.h>
using namespace std;

bool solve(int n ,int target,vector<int>arr){
    vector<vector<int>>dp(n+1,vector<int>(target+1,false));

    dp[0][0]=true;
    int i=1;
    while(i<=n){
        int j=0;
        while(j<=target){

            // not take
            if(dp[i-1][j]==true) dp[i][j]=dp[i-1][j];

            // Take 
            else if ((j-arr[i])>=0) {
                if(dp[i-1][j-arr[i]]==true) dp[i][j]=true;
            }
            else {
                dp[i][j]=false;
            }
            
            j++;
        }

        i++;
    }

    return dp[n][target];
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

    int target;
    cin>>target;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
 
    bool ans=solve(n,target,arr);
    // cout<<ans<<endl;
    if(ans==true) cout<<"True"<<endl;
    else cout<<"False"<<endl;

	return 0;
}
	


/*
// input1 :
6
9
3 34 4 12 5 2


// output1:
True


Input2:
6
30
3 34 4 12 5 2

// output 2:
False

input3:


output:


input4:

output: 



*/