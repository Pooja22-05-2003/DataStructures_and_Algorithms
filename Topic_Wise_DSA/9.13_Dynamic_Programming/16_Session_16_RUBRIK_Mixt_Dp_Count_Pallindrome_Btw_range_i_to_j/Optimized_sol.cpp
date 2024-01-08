/*
For Optimization , Think of is it possible to Extract the answer for each query in O(1) operation.

*/

// TC=O(N*N) => 
// SC=O(N*N)
#include<bits/stdc++.h>
using namespace std;
   
    void  solve(string s, vector<vector<int>> &dp1) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        // d[i][j]==1 if s[i] to s[j].....is Pallindrome.
        // So for all the strings of length=1 , dp[i][j]=1, As 1 char length is always a pallindrome.

        int cnt=0;
        // For substring of len=1
        int i=0;
        while(i<n){
            dp[i][i]=1;
            dp1[i][i]=1;
            cnt++;
            i++;
        }


        // For substring of len=2;
        i=0;
        while(i<n-1){
            if(s[i]==s[i+1]) {
                dp[i][i+1]=1;
                cnt++;
                }
            else dp[i][i+1]=0;

            dp1[i][i+1]=dp1[i][i+1-1]+dp1[i+1][i+1]+dp[i][i+1];
            i++;
        }


        // For substring of len=3 and more.
        int len=3;
        while(len<=n){
        i=0;
        while(i<n-len+1){
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1) {
                dp[i][j]=1;
                cnt++;
                }
            else dp[i][j]=0;

            // This formula is created as number of substring between i to j-1 and + i+1 to j and we counted i+1 to j-1 2 times , so we will subtract 1 time
            //  and also at last , we will check if the dp[i][j] is a valid substring, so it contribute 1 in the main ans
            dp1[i][j]=dp1[i][j-1]+dp1[i+1][j]-dp1[i+1][j-1]+dp[i][j];

            i++;
        }
        len++;



        }
       
        // int cntt=0;
        // for(int m=l;m<=r;m++){
        //     for(int n=m;n<=r;n++){
        //         if(dp[m][n]==1) cntt++;
        //     }
        // }

        // return cntt;

       
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

	string s;
    cin>>s;

    int q;
    cin>>q;
    int i=1;


    int n=s.size();
    // 2D vector DP1, and in this 
    // DP1[i][j]= It will store the number of pallindromic subtrings which are valid the the range of i to j.
    vector<vector<int>> dp1(n+1,vector<int>(n+1,0));
    solve(s,dp1);
    while(i<=q){
        int l,r;
        cin>>l;
        cin>>r;
        cout<<dp1[l][r]<<endl;
        
        i++;
    }

	return 0;
}
	


/*
// input1 :
bbcb 
3
0 3 
0 2
0 1


// output1:
6
4
3



// input 2 :



// output 2:



input3:



output3:

*/


