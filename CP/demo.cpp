/*
Brute Force Approach.
1.Generate all the substring using 2 for loops and check whther substring is pallindrome or not.
2. If it is pallindrome, then calculate its len, If its len is more than maxLen, then update the maxlen and finalSt ,FinalEnd.
3. After iterating through all the substrigs, print the maximum length substring and its len.

*/


// O(n2*n) 
// SC=O(n2)
#include<bits/stdc++.h>
using namespace std;
   int CountPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        // check for string of length =1;
        // 1 length subsequence is always pallindrome
        int i=0;
        while(i<n){
            dp[i][i]=1;
            i++;
        }


        // For string of length =2
        i=0;
   
        while(i<n-1){
            int j=i+1;
            if(s[i]!=s[j])
            {
            dp[i][j]=2;          
            }

            else {
               dp[i][j]=3;           
             }

            i++;
         }
           


           int len=3;

           while(len<=n){
               i=0;
               while(i<=(n-len))
               {
                   int j =i+len-1;
                   if(s[i]!=s[j]){
                       dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                   }
                   else {
                    //    dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+dp[i+1][j-1]+1 (as s[i][j] is also pallindrome);

                    dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                   }

                   i++;
               }


               len++;
           }

           return dp[0][n-1];
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
    cout<<CountPalindromeSubseq(s)<<endl;
	return 0;
}
	


/*
// input1 :
bbbbbbbbb


// output1:
511


// input 2 :
abcd


// output 2:
4


input3:
aaaa


output3:
15
*/


