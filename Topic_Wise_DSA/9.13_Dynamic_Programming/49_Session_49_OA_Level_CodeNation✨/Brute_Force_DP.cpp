/*
Approach:
At each index, try to find the best possible ans.
dp[i][j]=> Maximum bitwise OR till index i, when u are partitioning the arr
till index i in j parts.

let's say arr= 1 4 2 56 3
dp[4][2]=> Now at index 4.
1. First option is take the last el in 1 subarray and divide i-1 in j-1 subarray.
2nd otption take i,i-1 in 1 subarray and divide the remaining i-2 in j-1 subarray.
.
.
Repeat this till u are able to divide it.

*/

// TC=O(N3) [N=1000, n3=10^9---> It will give TLE].
// SC=O(N2)

#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int>arr)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    dp[1][1]=arr[1];

   
    int i=2;
    while(i<=n){

        for(int j=k;j>=1;j--){
            int last_part=i;
            int currOR=arr[i];
            while(last_part>=j){
                // cout<<"lastPart:"<<last_part<<" currOR:"<<currOR<<" dp[last_part-1][j-1]+currOR:"<<dp[last_part-1][j-1]+currOR<<endl;
                dp[i][j]=max(dp[i][j],dp[last_part-1][j-1]+currOR);
               
                last_part--;
                 currOR=currOR |arr[last_part];
            }
        cout<<"i:"<<i<<" j:"<<j<<" dp[i][j]:"<<dp[i][j]<<endl;
        }
        i++;
    }

    return dp[n][k];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    //

    //*********

    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,k,arr);

    return 0;
}

/*
// input1 :
4
2
1 2 3 4 



// output1:
10

lastPart:2 currOR:2 dp[last_part-1][j-1]+currOR:3
i:2 j:2 dp[i][j]:3
lastPart:2 currOR:2 dp[last_part-1][j-1]+currOR:2
lastPart:1 currOR:3 dp[last_part-1][j-1]+currOR:3
i:2 j:1 dp[i][j]:3
lastPart:3 currOR:3 dp[last_part-1][j-1]+currOR:6
lastPart:2 currOR:3 dp[last_part-1][j-1]+currOR:4
i:3 j:2 dp[i][j]:6
lastPart:3 currOR:3 dp[last_part-1][j-1]+currOR:3
lastPart:2 currOR:3 dp[last_part-1][j-1]+currOR:3
lastPart:1 currOR:3 dp[last_part-1][j-1]+currOR:3
i:3 j:1 dp[i][j]:3
lastPart:4 currOR:4 dp[last_part-1][j-1]+currOR:7
lastPart:3 currOR:7 dp[last_part-1][j-1]+currOR:10
lastPart:2 currOR:7 dp[last_part-1][j-1]+currOR:8
i:4 j:2 dp[i][j]:10
lastPart:4 currOR:4 dp[last_part-1][j-1]+currOR:4
lastPart:3 currOR:7 dp[last_part-1][j-1]+currOR:7
lastPart:2 currOR:7 dp[last_part-1][j-1]+currOR:7
lastPart:1 currOR:7 dp[last_part-1][j-1]+currOR:7
i:4 j:1 dp[i][j]:7
10


Input2:


// output 2:



input3:


output:





*/