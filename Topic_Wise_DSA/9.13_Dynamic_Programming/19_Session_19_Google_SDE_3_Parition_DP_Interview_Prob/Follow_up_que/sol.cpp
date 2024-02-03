/*
1.Now, the change in the question from the previous is that , now we cannot do random partitions , but
Now k value is fixed.
2. This will lead to new origin of the dp state.
dp[i][j]= denote the maximum number of partition till index i, when only j partitions of the array are allowed.

Obervation : dp[i][k]=> It denotes the best answer till index i , when k partition we need to do.
1. So, if i<k, then answer would always be 0, for ex arr of len-4, we can partion the array into 5 parts.
2. So , the start valid , when i>=k
*/

// TC= O(N*k*k)
// SC=O(n*k)
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> arr , int n ,int m , int k) {
   
        // We can also intialzie with , but intializing with INT_MIN, so that if user enter value of k less than n , then he get the ans as INT_MIN
        vector<vector<int>> dp(n+1,vector<int>(k,INT_MIN));
 
        // intiliaze i with k
        dp[0][0]=1;
        dp[1][1]=1;
        int i=2;
    
        while( i<=n){
             int partition=1;
             while(partition<=k){
                // lets say k value is more than i , then u need to calculate the dp state for less than k values also.
                int j=i;
                int sum=arr[i];
                int total=0;
                while(j>=1 && sum<=m){

                    int temp=dp[j-1][partition-1];
                    // cout<<"i:"<<i<<" j-1:"<<j-1<<" partition-1:"<<partition-1<<" temp:"<<temp<<endl;
                    if(temp>0){
                        total=total+temp;
                        //   cout<<"total:"<<total<<endl;
                    }
                    j--;
                    sum=sum+arr[j];
                }

                if(total>0) 
                {
                    dp[i][partition]=total;
                    cout<<"i:"<<i<<" partition:"<<partition<<" dp[i][partition]:"<<dp[i][partition]<<endl;
                  
                }
                partition++;
             }
            //  cout<<"dp[i][k]:"<<dp[i][k]<<endl;
             i++;
    }

    return dp[n][k];
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

    int m;
    cin>>m;

    // k number of partitions are allowed.
    int k;
    cin>>k;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n,m,k);

	return 0;
}
	


/*
// input1 :
5 5 
5
1 2 3 4 4 


// output1:
1

i:2 j-1:1 partition-1:0 temp:-2147483648
i:2 j-1:0 partition-1:0 temp:1
total:1
dp[i][partition]:1
i:2 j-1:1 partition-1:1 temp:1
total:1
i:2 j-1:0 partition-1:1 temp:-2147483648
dp[i][partition]:1
i:2 j-1:1 partition-1:2 temp:-2147483648
i:2 j-1:0 partition-1:2 temp:-2147483648
i:2 j-1:1 partition-1:3 temp:-2147483648
i:2 j-1:0 partition-1:3 temp:-2147483648
i:2 j-1:1 partition-1:4 temp:-2147483648
i:2 j-1:0 partition-1:4 temp:-2147483648
dp[i][k]:1162690894
i:3 j-1:2 partition-1:0 temp:-2147483648
i:3 j-1:1 partition-1:0 temp:-2147483648
i:3 j-1:2 partition-1:1 temp:1
total:1
i:3 j-1:1 partition-1:1 temp:1
total:2
dp[i][partition]:2
i:3 j-1:2 partition-1:2 temp:1
total:1
i:3 j-1:1 partition-1:2 temp:-2147483648
dp[i][partition]:1
i:3 j-1:2 partition-1:3 temp:-2147483648
i:3 j-1:1 partition-1:3 temp:-2147483648
i:3 j-1:2 partition-1:4 temp:-2147483648
i:3 j-1:1 partition-1:4 temp:-2147483648
dp[i][k]:7497059
i:4 j-1:3 partition-1:0 temp:-2147483648
i:4 j-1:3 partition-1:1 temp:-2147483648
i:4 j-1:3 partition-1:2 temp:2
total:2
dp[i][partition]:2
i:4 j-1:3 partition-1:3 temp:1
total:1
dp[i][partition]:1
i:4 j-1:3 partition-1:4 temp:-2147483648
dp[i][k]:1983728961
i:5 j-1:4 partition-1:0 temp:-2147483648
i:5 j-1:4 partition-1:1 temp:-2147483648
i:5 j-1:4 partition-1:2 temp:-2147483648
i:5 j-1:4 partition-1:3 temp:2
total:2
dp[i][partition]:2
i:5 j-1:4 partition-1:4 temp:1
total:1
dp[i][partition]:1
dp[i][k]:1
1


sir prining :
i:2 partition:1 dp[i][partition]:1
i:2 partition:2 dp[i][partition]:1
i:3 partition:2 dp[i][partition]:2
i:3 partition:3 dp[i][partition]:1
i:4 partition:3 dp[i][partition]:2
i:4 partition:4 dp[i][partition]:1
i:5 partition:4 dp[i][partition]:2
i:5 partition:5 dp[i][partition]:1
1

// input 2 :



// output 2:

*/