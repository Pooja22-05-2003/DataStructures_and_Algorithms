/*
Problem in 1 Line : 
Given 2 arrays, and you need to select 1 element at each index, but u can't select more than 2 elements from the same array.
Return the maximum possible sum , which u can achieve.
*/

/*
Approach :
1. As at any state the element which we are picking is not going to be the best answer. for last index or we can say maximum sum.
2. So , we need to explore all the possible paths and need to obtain maximum answer from , and that we can achieve through DP.
3. So , In DP, we can't obtain the best answer through single DP. We need to keep track that we had selected the prev consective
 2 element and we can't select the 3rd element from the same array.
4. Here we need 4 dp arrays.
dp[i][1][1]--- It indicates that for the current index i , both the element is selected from the b array.
dp[i][1][2]---> It indecates that for current index i , last  element is selected from array b and other element is selected from array c.
dp[i][2][2]--> It indicates that for current index i, both the elements is selected from array c.
dp[i][2][1]---> It indicated that for current index i, last element is selected from array c and second last element is selected from arr b

At last after n iteration return the best answer for index n by calculating the best among all the 4 states.

*/

// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> b,vector<int> c){
    
    // 4 dp 
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,0)));

    dp[1][1][1]=b[1];
    dp[1][1][2]=b[1];
    dp[1][2][2]=c[1];
    dp[1][2][1]=c[1];

    int i=2;
    while(i<=n){
        dp[i][1][1]=b[i]+b[i-1]+max(dp[i-2][2][2],dp[i-2][2][1]);

        // U can take both the el from b as there is one gap, we included the c ele at i-1 index, but u can't take 2 consecuite from arr c beccuase at i-1 index u considered arr c element 
        dp[i][1][2]=b[i]+c[i-1]+max(dp[i-2][1][1],max(dp[i-2][2][1],dp[i-2][1][2]));


        dp[i][2][2]=c[i]+c[i-1]+max(dp[i-2][1][1],dp[i-2][1][2]);
        dp[i][2][1]=c[i]+b[i-1]+max(dp[i-2][2][2],max(dp[i-2][2][1],dp[i-2][1][2]));

        i++;
    }


    return max(dp[n][1][1], max(dp[n][1][2],max(dp[n][2][2],dp[n][2][1])));

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

   vector<int> v1(n+1);
   for(int i=1;i<=n;i++){
    cin>>v1[i];
   }

   vector<int> v2 (n+1);
   for(int i=1;i<=n;i++){
    cin>>v2[i];
   }
    int ans=solve(n,v1,v2);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
3
5 3 4
10 10 10

// output1:
25


Input2:


// output 2:


input3:


output:


input4:

output: 



*/