/*
Q1. What is Mixt Dp=? 
1. Dp[i]=In general Dp, it tells the best answer till index [i] from index 1
2. But in Mixt DP, this is not the case and here dp[i][j]= It tells the best answer from index i to index j.

*/

/*
Que in 1 line => We are given one array , and we need to convert that single element . 
->We are allowed to take any 2 adjacent numbers and merge them, and its cost would be the sum of the both elements.
-> And we can do this operation as many times as we want , from all the possible , find the way which cost minimum and return that minimum cost.

*/

/*
INTUTION-> We need to find the best answer from index 1 to n.
-> For every new index, we can't again calaculte the all values from scratch, so we can reuse the previous for the current indexes, and that is possible in the 
case of DP.

*/

/*
Approach:
1. Compute the arr of 1 length cost , dp[1][1] , dp[2][2], dp[3][3]....till len.
2. Compute for arr of len=2, dp[1][2] , dp[2][3] , dp[3][4] , dp[4][5] .....till last ind.,
3. Try to use the for loop to compute the remaining dp state.
4. And finally return dp[1][n]-> That would be the best  min cost.
*/

// TC=O(N3)
// SC=O(N2)
#include<bits/stdc++.h>
using namespace std;
   int CountPalindromeSubseq(vector<int> arr , int n ) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    // We can create one prefix array  , which can tell in O(1) operation , the sum of elements in the array from index 1 to n.
    vector<int> prefix(n+1,0);

    prefix[1]=arr[1];
    int i=1;
    while(i<=n){
        prefix[i]=prefix[i-1]+arr[i];
        i++;
    }
    // Handle the case of len=1;
    i=1;
    while(i<=n){
        // Min cost of 1 element would always be 0,because is already converted in 1 element.
        dp[i][i]=0;
        i++;
    }

    i=1;
    while(i<=n-1){
        dp[i][i+1]=arr[i]+arr[i+1];
        i++;
    }


    int len=3;

    while(len<=n){
        i=1;
        while(i<=(n-len+1)){
            int j=i+len-1;
            // dp[i][j]---I need to calaculte
            int k=i;
            int minn=INT_MAX;
            while(k<j){
                int temp=dp[i][k]+dp[k+1][j]+(prefix[j]-prefix[i-1]);
                minn=min(minn,temp);
                k++;
            }
            dp[i][j]=minn;

            i++;
        }



        len++;
    }

    return dp[1][n];
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
    cout<<CountPalindromeSubseq(arr,n)<<endl;
	return 0;
}
	


/*
// input1 :
3
5 5 8


// output1:
28


// input 2 :
4
5 8 2 10


// output 2:
50


input3:



output3:


*/


