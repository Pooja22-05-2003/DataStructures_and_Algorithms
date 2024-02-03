
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> arr , int k,int n ,int m) {
        vector<vector<int>>dp(n+1,vector<int>(k,0));
        dp[0][0]=1;
        dp[1][1]=1;

     
        int i=2;
        while(i<=n)
        {
          int partition=1;
          while(partition<=k)
          {
            int j=i;
            int sum=arr[j];
            int total=0;
            while(j>=1 && (sum<=m))
            {
                int temp=dp[j-1][partition-1];
                if(temp>0)
                {
                   total=total+temp; 
                }
                j--;
            }

            if(total>0)
            {
                dp[i][partition]=total;
                cout<<"i:"<<i<<" partition:"<<partition<<" dp[i][partition]:"<<dp[i][partition]<<endl;
            }


            partition++;
          }
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
    int k;
    cin>>k;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,k,n,m);

	return 0;
}
	


/*
// input1 :
5
5
1
2
3
4
4



// output1:

3



// input 2 :



// output 2:

*/