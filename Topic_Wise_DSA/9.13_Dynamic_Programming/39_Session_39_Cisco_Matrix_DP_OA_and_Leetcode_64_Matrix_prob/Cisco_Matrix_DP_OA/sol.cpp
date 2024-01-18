
// TC=O(N*M)
// SC=O(N*M)

#include<bits/stdc++.h>
using namespace std;

  int solve(int n , int m) {

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            if(i==1 && j==1) dp[1][1]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1];
            j++;
        }

        i++;
    }
    return dp[n][m];
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
    
    int m;
    cin>>m;
   
    int ans=solve(n,m);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
2 
2


// output1:
3



Input2:


// output 2:



input3:


output:


input4:

output: 



*/