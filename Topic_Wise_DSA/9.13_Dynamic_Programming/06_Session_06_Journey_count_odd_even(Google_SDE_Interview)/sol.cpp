// TC=O(N)
// SC=O(N)
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr , int n ){
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    // dp[i][odd]==dp[i][1]==Means Maximum  Number of journeys , such that their sum is odd(and the number starting from 1 and ending at i)
    // dp[i][even]==dp[i][2]==Means Maximum  Number of journeys , such that their sum is even(and the number starting from 1 and ending at i)

    if(arr[1]%2==0) dp[1][2]=1;
    else dp[1][1]=1;

    int i=2;
    while(i<=n){
        if(arr[i]%2==0){
            //  we can take 1 jump or 2 jump

            // even + odd= odd
            // even + even= even
            dp[i][1]=dp[i-1][1]+dp[i-2][1];
            dp[i][2]=dp[i-1][2]+dp[i-2][2];
        }
        else {
            // odd+even=odd
            dp[i][1]=dp[i-1][2]+dp[i-2][2];


            // odd+odd=even
            dp[i][2]=dp[i-1][1]+dp[i-2][1];
        }

        i++;
    }

    // If the number is odd
    // return dp[n][1];
    


    // If question is asking for returning even journeys
    // return dp[n][2];


    cout<<"dp[n][1]:"<<dp[n][1]<<" dp[n][2]:"<<dp[n][2]<<endl;
    return dp[n][1];
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

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);
	return 0;
}
	


/*
// input1 :
5
2 3 5 8 10 


// output1:
dp[n][1]:3 dp[n][2]:2
3




// input 2 :
4
5 4 2 6

// output 2:
dp[n][1]:3 dp[n][2]:0
3

input3:



output3:




*/

