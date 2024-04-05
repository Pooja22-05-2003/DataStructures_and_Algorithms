// TC=O(Nlogn)
// SC=O(N)


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr , int n ){
	sort(arr.begin(),arr.end());

    // dp[i][1]=> maximum length of the subset when  we are taking the last element in the subset and the subset (adjacent el diff)sum is odd.
    // dp[i]2]=> maximum length of the subset when  we are taking the last element in the subset and the subset (adjacent el diff)sum is even.
    vector<vector<int>> dp(n,vector<int>(3,0));
	int ans=0;
    if((arr[1]-arr[0])%2==0) dp[1][2]=2;
    else dp[1][1]=2;

// cout<<"dp[n][1]:"<<dp[1][1]<<" dp[n][2]:"<<dp[1][2]<<endl;
    int i=2;
	ans=max(ans,max(dp[0][2],dp[1][2]));
    while(i<n){
        if((arr[i]-arr[i-1])%2==0){
           

            // even + odd= odd
            // even + even= even
            dp[i][1]=max(dp[i-2][1],dp[i-1][1]+1);
            dp[i][2]=max(dp[i-2][2],dp[i-1][2]+1);
        }
        else {
            // odd+even=odd
            dp[i][1]=max(dp[i-2][1],dp[i-1][2]+1);


            // odd+odd=even
           
            dp[i][2]= max(dp[i-2][2],(dp[i-1][1]+1));
        }
		ans=max(ans,dp[i][2]);
		cout<<"i:"<<i<<" dp[i][1]:"<<dp[i][1]<<","<<" dp[i][2]:"<<dp[i][2]<<endl;
        i++;
    }



 
    return ans;
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

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);
	return 0;
}
	


/*
// input1 :
4 
1 3 5 7


// output1:
dp[n][1]:0 dp[n][2]:2
i:2 dp[i][1]:1, dp[i][2]:3
i:3 dp[i][1]:2, dp[i][2]:4
4




// input 2 :
6
5 6 2 3 2 4

// output 2:
dp[n][1]:0 dp[n][2]:2
i:2 dp[i][1]:3, dp[i][2]:1
i:3 dp[i][1]:2, dp[i][2]:4
i:4 dp[i][1]:5, dp[i][2]:3
i:5 dp[i][1]:4, dp[i][2]:6
6

input3:

7
2 2 3 4 5 6 7

output3:
dp[n][1]:0 dp[n][2]:2
i:2 dp[i][1]:3, dp[i][2]:1
i:3 dp[i][1]:2, dp[i][2]:4
i:4 dp[i][1]:5, dp[i][2]:3
i:5 dp[i][1]:4, dp[i][2]:6
i:6 dp[i][1]:7, dp[i][2]:5
6



*/

