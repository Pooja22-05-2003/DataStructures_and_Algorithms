/*
Observation:
1. It is a dp problem.
2. Now calculate dp[1],dp[2]......and compute the general formula.
3.dp[1]=0;
4. dp[i]=It will tell the best answer to the question, till index i, when index i is considered in the subset.
5. At dp[i]= max(dp[i],and consider the max case from ind i-1 to 1)
6. Case means like for taking subset from i-1 and i (cost=arr[i]-arr[i-1]+dp[i-1])......similary do for i-2,i-3.....and so on till 1.
7. Calculate this using for loop ...till index n .


*/

// TC=O(n)-- 1 for loops
// SC=O(2*n) Dp array

#include <bits/stdc++.h>
using namespace std;

    int solve(int n , vector<int> nums){
        vector<int> dp(n+1,0);
        vector<int> max_arr(n+1,0);
        dp[1]=0;

        // max_arr[i] represent maximum answer from i-1 to 1 of nums[i]-nums[j]+dp[j];
        max_arr[1]=dp[1]-nums[1];
        
        for(int i=2;i<=n;i++){
            // for(int j=i-1;j>=1;j--){
            //     int temp=nums[i]-nums[j]+dp[j];
            //     dp[i]=max(dp[i],temp);
            // }
       //     int temp=nums[i]-nums[j]+dp[j]; // reshuffle this temp=nums[i]+(dp[j]-nums[j]) [ so j will go from j-1 to 1 ]
            int temp=nums[i]+max_arr[i-1];
            dp[i]=max(dp[i],temp);
            max_arr[i]=max(max_arr[i-1],dp[i]-nums[i]);

        }

        return dp[n];
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    cout<<solve(n,nums);
    return 0;
}


/*
//  input1 :
5
5 10 1 5 100


// output1:
99

input 2:


Output 2:





*/