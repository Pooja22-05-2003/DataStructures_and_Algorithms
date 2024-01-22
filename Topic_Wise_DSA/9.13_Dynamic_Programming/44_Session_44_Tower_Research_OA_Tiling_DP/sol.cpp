/*
1. See the gfg solution for the better clarifaction the solution for n=3.

2. for n=1, ans=1 
   for n=2, ans=1 
   for n=3, ans=1 
   for n=4, ans=2
3. So the general formula is (dp[i]=dp[i-1]+dp[i-2])
4. return dp[n] as the final ans.
*/

// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;

    
    int i=5;
    while(i<=n){
        dp[i]=dp[i-1]+dp[i-4];
        i++;
    }
    return dp[n];
    
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

    int ans=solve(n);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
5

// output1:
5

Input2:

// output 2:



input3:


output:


input4:

output: 



*/