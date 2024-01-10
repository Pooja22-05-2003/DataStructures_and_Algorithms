


// TC= O(N2)
// SC=O(M)
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> arr , int n ,int m) {
   
        vector<int> dp(n+1,0);
        dp[0]=1; // this case will come when we included the whole element in 1 partion
        dp[1]=1; // it is given that arr[i]<=m, so need to check whether each index element is satisfying the condition or not.
        int i=2;
        while(i<=n){
            // for each index check fron i-1 to 1...till sum is valid.
            int j=i;
            int sum=arr[i];
            while(j>=1){
              
                if(sum<=m){
                dp[i]=dp[i]+dp[j-1];
                j--;
            //    cout<<"i: "<<i<<" dp[i]:"<<dp[i]<<endl;
                sum=sum+arr[j];
                }
                else break;
            }

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

    int m;
    cin>>m;
    vector<int>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n,m);

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
i: 2 dp[i]:1
i: 2 dp[i]:2
i: 3 dp[i]:2
i: 3 dp[i]:3
i: 4 dp[i]:3
i: 5 dp[i]:3
3



// input 2 :



// output 2:

*/