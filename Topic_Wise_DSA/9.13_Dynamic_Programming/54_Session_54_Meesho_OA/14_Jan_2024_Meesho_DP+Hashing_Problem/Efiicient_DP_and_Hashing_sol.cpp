
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> arr){
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> ans(n+1,0);

    unordered_map<int,int> mp;

    dp[1][0]= INT_MAX; // it measn we are trying to find the el  which is similar to curr el and our search space is i-1 to 1.
    dp[1][1]=1;    // we are including the current element at index 'i'.
    mp[arr[1]]=ans[1-1];

    ans[1]=min(dp[1][1], dp[1][0]);
    int i=2;
   
    while(i<=n)
    {   
        dp[i][1]=1+ans[i-1];
        dp[i][0]=INT_MAX;
        // int j=i-1;
        // while(j>=1){
        //     if(arr[j]==arr[i]){
        //         dp[i][0]=min(dp[i][0],ans[j-1]);
        //     }
        //     j--;
        // }
        if(mp.find(arr[i])!=mp.end()) dp[i][0]=mp[arr[i]];
        ans[i]=min(dp[i][1],dp[i][0]);
        
        if(mp.find(arr[i])==mp.end()){
              mp[arr[i]]=ans[i-1];
        }
        else {
            mp[arr[i]]=min(mp[arr[i]],ans[i-1]);
        }
        i++;
    }

    int res=min(dp[n][0] , dp[n][1]);
    return res;
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

   vector<int> v1(n+1);
   for(int i=1;i<=n;i++){
    cin>>v1[i];
   }

   
    int ans=solve(n,v1);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
6
4 2 2 3 3 1

// output1:
2


Input2:
4
1 2 3 2

// output 2:
1

input3:


output:


input4:

output: 



*/