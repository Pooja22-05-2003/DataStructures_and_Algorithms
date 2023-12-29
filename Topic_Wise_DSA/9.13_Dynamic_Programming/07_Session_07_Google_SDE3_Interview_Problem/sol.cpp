// TC=O(N)
// SC=O(N)
#include<bits/stdc++.h>
using namespace std;

int solve(int n , int y, int x, int z , int b){
    vector<int> dp(n+1,0);
    // reduce by 1 cost=y
    // reduce by /7 cost=x
    // reduce by /3 cost=z
    // reduce  by  /5 cost=b

    dp[1]=0;
    dp[2]=y;

    int i=3;
    while(i<=n){
        int c1=INT_MAX;
        int c2=INT_MAX;
        int c3=INT_MAX;
        int c4=INT_MAX;
        c1=dp[i-1]+y;

        if(i%7==0){
            int div=i/7;
            c2=x+dp[div];
        }
        if(i%3==0){
            int div=i/3;
            c3=z+dp[div];
        }
        if(i%5==0){
            int div=i/5;
            c4=b+dp[div];
        }
        dp[i]=min(c1,min(c2,min(c4,c3)));

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

    // reduce by 1 cost=y
    int y;
    cin>>y;

    // reduce by /7 cost=x
    int x;
    cin>>x;

    // reduce by /3 cost=z
    int z;
    cin>>z;


    // reduce  by  /5 cost=b
    int b;
    cin>>b;


    cout<<solve(n,y,x,z,b);
	return 0;
}
	


/*
// input1 :
15
100
1
500
10000000

// output1:
201


// input 2 :

// output 2:

*/

