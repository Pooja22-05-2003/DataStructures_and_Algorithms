/*
Approach:
dp[i] = min cost to get valid subset in array A till index “i” 

-> dp[i][j] = min cost to get valid subset in array A till index “i” but the last element of that subset should be forcefully j 


*/


// TC=O(N*50*50)
// SC=O(N*50)

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>a,vector<int>b) {
    // AS the element of the arr lie between 1<=a[i]<=50
    vector<vector<int>>dp(n+1,vector<int>(51,100000));

    dp[1][a[1]] = 0 ; // considering only 1 element is present , so it is valid in itself,and 2 adjacent element have diff=1;
    
    for(int i=2;i<=n;i++){
        for(int k=1;k<=50;k++){

            if(a[i]==k){

                // this inner loop of v, we can optimize using the prefix and the suffix arr
                for(int v=1;v<=50;v++){
                    if(abs(a[i]-v)!=1){
                        dp[i][k]=min(dp[i][k],dp[i-1][v]);
                    }
                }


            }
            else {
                dp[i][k]=min(dp[i][k],b[i]+dp[i-1][k]);
            }

            cout<<"i:"<<i<<" k:"<<k<<" dp[i][k]:"<<dp[i][k]<<endl;
        }
        
    }

    int ans=INT_MAX;
    for(int i=1;i<=50;i++){
        ans=min(ans,dp[n][i]);
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
5
1 5 2 3 5
1 2 3 4 5

// output1:
3


Input2:
3
1 2 3
5 5 5

// output 2:
5


input3:
5
1 1 5 1 1
1 2 3 4 1

output:
0




*/