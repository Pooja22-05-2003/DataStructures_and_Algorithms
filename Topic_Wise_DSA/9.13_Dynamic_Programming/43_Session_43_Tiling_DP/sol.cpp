/*
1. See the gfg solution for the better clarifaction the solution for n=3.

2. for n=1, ans=1 (place vertically)
   for n=2, ans=2 (place both vertically and place both horizontally)
   for n=3, ans=3 (for n=1 and n=3 add the third till horizontally with all the possible ways for n=2,1)
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
    dp[2]=2;
    
    int i=3;
    while(i<=n){
        dp[i]=dp[i-1]+dp[i-2];
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
4

// output1:
5

Input2:

// output 2:



input3:


output:


input4:

output: 



*/