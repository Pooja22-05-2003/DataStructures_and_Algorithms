/*
Approach :-
1.first try to calaculte the answer of the dp for len=1 array, when len of dp[i][j] is 1.
2. Then try to find the dp answer for len2.
3. Then try to find the answer of the dp for len=3 and try to create the general formula for this.
4. Run a for loop till n and dp[1][n] is your answer.

Note:- In this question, there are only 3 options 
1. Select the first and the second el. Then for all the future moves , i need with this sum only. so,
 dp[i][j][sum1]==dp[i][j][1]=> It denotes the maximum number of moves which u can perform when sum is sum1 and len of the array is i to j.

2. Option is to select last 2 elements. dp[i][j][sum2], so sotre ans in dp[i][j][2]
3. Options is to select first and the last element , so here dp state will be dp[i][j][sum3], so store ans in dp[i][j][3]

for any length of dp[i][j], it will store the maximum of all three(dp[i][j][sum1], dp[i][j][sum2] , dp[i][j][sum3])
Do this from i range from 1 to n and return dp[1][n] as the final answer.

*/



// TC= 
// SC=
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> arr , int n ) {
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,(vector<int>(4,0))));

    // you consider any length of the array , u need to find answer for only 3 sums.
    int sum1=arr[1]+arr[2];
    int sum2=arr[n]+arr[n-1];
    int sum3=arr[1]+arr[n];


    // consider of length =1 answer is alwars be 0 for all sum
    // dp[i][i][1],dp[i][i][2],dp[i][i][3]....would always be 0.

    // consider for len=2;
    int i=1;
    while(i<=n-1){
        int sum=arr[i]+arr[i+1];
       
        if(sum==sum1){
            dp[i][i+1][1]=max(1,dp[i][i+1][1]);
        }
        if(sum==sum2){
            dp[i][i+1][2]=max(1,dp[i][i+1][2]);
        }
        if(sum==sum3){
            dp[i][i+1][3]=max(1,dp[i][i+1][3]);
        }

        cout<<"i:"<<i<<":"<<"j:"<<i+1<<":"<<dp[i][i+1][2]<<","<<dp[i][i+1][1]<<","<<dp[i][i+1][3]<<endl;
        i++;
        i++;
    }



    int len=3;
    while(len<=n){
        int i=1;
       

        while(i<=(n-len+1)){
             int j=i+len-1;
            int s1=arr[i]+arr[i+1];
            if(s1==sum1){
                // cout<<"s1:"<<s1<<" sum1:"<<sum1<<endl;
                dp[i][j][1]=max(dp[i][j][1],1+dp[i+2][j][1]);
            }
            if(s1==sum2){
                // cout<<"s1:"<<s1<<" sum2:"<<sum2<<endl;
                dp[i][j][2]=max(dp[i][j][2],1+dp[i+2][j][2]);
            }
            if(s1==sum3){
                // cout<<"s1:"<<s1<<" sum3:"<<sum3<<endl;
                dp[i][j][3]=max(dp[i][j][3],1+dp[i+2][j][3]);
            }


            int s2=arr[j]+arr[j-1];
            if(s2==sum1){
                dp[i][j][1]=max(dp[i][j][1],1+dp[i][j-2][1]);
            }
            if(s1==sum2){
                dp[i][j][2]=max(dp[i][j][2],1+dp[i][j-2][2]);
            }
            if(s1==sum3){
                dp[i][j][3]=max(dp[i][j][3],1+dp[i][j-2][3]);
            }


            int s3=arr[i]+arr[j];
            if(s3==sum1){
                dp[i][j][1]=max(dp[i][j][1],1+dp[i+1][j-1][1]);
            }
            if(s3==sum2){
                dp[i][j][2]=max(dp[i][j][2],1+dp[i+1][j-1][2]);
            }
            if(s3==sum3){
                dp[i][j][3]=max(dp[i][j][3],1+dp[i+1][j-1][3]);
            }

        // cout<<"i:"<<i<<":"<<"j:"<<j<<":"<<dp[i][j][2]<<","<<dp[i][j][1]<<","<<dp[i][j][3]<<endl;
        i++;
     
        }

        len++;
    }
  
//    cout<<dp[1][n][2]<<","<<dp[1][n][1]<<","<<dp[1][n][3]<<endl;
   return max(dp[1][n][1],max(dp[1][n][2],dp[1][n][3]));


       
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
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n);

	return 0;
}
	


/*
// input1 :
7
3 
1
5
3
3
4
2



// output1:
3



// input 2 :
8
4
1
4
3
3
2
5
2


// output 2:
4


input3:
10
1
9
1
1
1
1
1
1
8
1


output3:
1


input 4:
7
1
9
8
9
5
1
2

output4:
3

input 5:
10
1
1
2
3
1
2
2
1
1
2



output5:
4

i:1:j:2:0,1,0
i:3:j:4:0,0,0
i:5:j:6:1,0,1
i:7:j:8:1,0,1
i:9:j:10:1,0,1
s1:2 sum1:2
i:1:j:3:1,1,1
s1:3 sum2:3
s1:3 sum3:3
i:2:j:4:1,0,1
i:3:j:5:1,0,1
i:4:j:6:0,0,0
s1:3 sum2:3
s1:3 sum3:3
i:5:j:7:1,0,1
i:6:j:8:1,0,1
s1:3 sum2:3
s1:3 sum3:3
i:7:j:9:1,1,1
s1:2 sum1:2
i:8:j:10:1,1,1
s1:2 sum1:2
i:1:j:4:0,1,0
s1:3 sum2:3
s1:3 sum3:3
i:2:j:5:1,1,1
i:3:j:6:0,0,0
i:4:j:7:0,0,0
s1:3 sum2:3
s1:3 sum3:3
i:5:j:8:2,1,2
i:6:j:9:2,1,2
s1:3 sum2:3
s1:3 sum3:3
i:7:j:10:2,0,2
s1:2 sum1:2
i:1:j:5:0,1,0
s1:3 sum2:3
s1:3 sum3:3
i:2:j:6:2,0,2
i:3:j:7:0,0,0
i:4:j:8:0,0,0
s1:3 sum2:3
s1:3 sum3:3
i:5:j:9:2,1,2
i:6:j:10:0,0,0
s1:2 sum1:2
i:1:j:6:2,1,2
s1:3 sum2:3
s1:3 sum3:3
i:2:j:7:2,0,2
i:3:j:8:1,0,1
i:4:j:9:0,1,0
s1:3 sum2:3
s1:3 sum3:3
i:5:j:10:3,0,3
s1:2 sum1:2
i:1:j:7:3,1,3
s1:3 sum2:3
s1:3 sum3:3
i:2:j:8:3,1,3
i:3:j:9:1,1,1
i:4:j:10:0,0,0
s1:2 sum1:2
i:1:j:8:0,1,0
s1:3 sum2:3
s1:3 sum3:3
i:2:j:9:3,1,3
i:3:j:10:0,0,0
s1:2 sum1:2
i:1:j:9:0,2,0
s1:3 sum2:3
s1:3 sum3:3
i:2:j:10:4,0,4
s1:2 sum1:2
i:1:j:10:4,1,4
4,1,4
4
*/


