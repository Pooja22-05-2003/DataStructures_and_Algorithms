
/*
Approach :
Now u need to count the total numbers of subset having sum equal to target.
*/
// TC=O(N*target)
// SC=O(N*Target)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,int target,vector<int>arr){
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));

    dp[0][0]=1;
    int i=1;
    while(i<=n){
        int j=0;
        while(j<=target){

            // not take
            

            // Take 
            if ((j-arr[i])>=0) {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
            }
            else {
                dp[i][j]=dp[i-1][j];
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
 
    int ans=solve(n,target,arr);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
4
6
1 2 3 3


// output1:
3


Input2:
4
1
1 1 1 1

// output 2:
4

input3:


output:


input4:

output: 



*/