//  TC=O(N+q)
//  SC=O(N)

#include <bits/stdc++.h>
using namespace std;


int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********
    // 1-- based indexing are used here

    int n;
    cin >> n ;
    // cout<<"Enter elements in sorted fashion"<<endl;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }


    // dp array 
    vector<int> dp(n+1,0);
    dp[1]=arr[1];


    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+arr[i];
    }



    int Q;
    cin>>Q;
    while(Q>0){
        int q;
        cin>>q;
        cout<<dp[q]<<endl;
        Q--;
    }
}

/*

input :
6
1 2 1 1 3 5
3
2
6
5


output :
3
13
8
*/