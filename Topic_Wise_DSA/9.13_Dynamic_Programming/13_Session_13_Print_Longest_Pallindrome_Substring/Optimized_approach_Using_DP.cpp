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
void Print(string s , int st , int end){
    for(int i=st;i<=end;i++){
        cout<<s[i];
    }
    cout<<endl;
}

void solve(string s){
   int n=s.size();
   vector<vector<int>> dp(n,vector<int>(n,0));

    // string of len=1 are always pallindrom
    int i=0;
    int maxlen=0;
    int len=0;
    int finalst;
    int finalend;
    while(i<n-1){
        dp[i][i]=1;
        maxlen=1;
        finalst=i;
        finalend=i;
        i++;
    }

    // string of len=2 
    // check if s[i]==s[j], then yes it is a pallindrome
    i=0;
    while(i<n-1){
        int j=i+1;
        if(s[i]==s[j]) 
        {
            dp[i][j]=1;
            maxlen=2;
            finalst=i;
            finalend=j;
        }
        i++;
    }


    // hadnle for cases of len=3 or greater than 3
    i=0;
    len=3;
    while(len<=n){
        int i=0;
        while(i<=(n-len)){
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                // it is valid pallindromic subsequence
                if(len>maxlen){
                    maxlen=max(maxlen,len);
                     finalst=i;
                     finalend=j;
                }
                dp[i][j]=1;
            }

            i++;
        }
        len++;
    }
    cout<<"MaxLen:"<<maxlen<<" Pallindromic Subsequence is :";
    Print(s,finalst,finalend);

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
    solve(s);
	return 0;
}
	


/*
// input1 :
forgeeksskeegfor


// output1:
MaxLen:10 Pallindromic Subsequence is :geeksskeeg
1


// input 2 :
Geeks


// output 2:
MaxLen:2 Pallindromic Subsequence is :ee


input3:



output3:

*/


