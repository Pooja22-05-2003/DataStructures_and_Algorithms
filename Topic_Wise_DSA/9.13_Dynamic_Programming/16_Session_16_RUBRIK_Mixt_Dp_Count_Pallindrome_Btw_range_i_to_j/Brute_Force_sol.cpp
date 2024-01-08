/*
Brute Force approach is , use the dp array u created in the counting of number of 
Pallindromic substring in string , and and run one for loop for q queries and under that 
run 2 for loop[which will go in range of l to r] ,just like you do in subarray and if (dp[i][j]==1) 
it means that substring from index i to j is pallindrome, so increase the counter and return the count for each range.

*/

// TC=O(Q*N*N) => q range is 10^6*10^5*10^5=> 10^16==> OPTIMIZE IT 
// SC=O(N*N)
#include<bits/stdc++.h>
using namespace std;
   
    int solve(string s,int l , int r) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        // d[i][j]==1 if s[i] to s[j].....is Pallindrome.
        // So for all the strings of length=1 , dp[i][j]=1, As 1 char length is always a pallindrome.

        int cnt=0;
        // For substring of len=1
        int i=0;
        while(i<n){
            dp[i][i]=1;
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

            i++;
        }
        len++;
        }
       
        int cntt=0;
        for(int m=l;m<=r;m++){
            for(int n=m;n<=r;n++){
                if(dp[m][n]==1) cntt++;
            }
        }

        return cntt;
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
    while(i<=q){
        int l,r;
        cin>>l;
        cin>>r;
        cout<<solve(s,l,r)<<endl;
        
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


