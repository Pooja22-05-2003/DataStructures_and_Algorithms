
/*
Approach :

*/
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

  int helper(int k,vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<int> dp(n+1,1);
        mp[arr[1-1]]=1;
        int i=2;
        while(i<=n){

            // int j=i-1;
            // while(j>=1){
            //     if(arr[i-1]-arr[j-1]==k) dp[i]=max(dp[i],1+dp[j]);
            //     j--;
            // }
            dp[i]=max(dp[i],(1+mp[arr[i-1]-k]));
            // cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
            mp[arr[i-1]]=max(mp[arr[i-1]],dp[i]);
            i++;
        }
        
        // rerturn max of all dp[i]
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
}

int solve(vector<int>arr){
    sort(arr.begin(),arr.end());
    int min_diff=0;
    int n=arr.size();
    if(n==1) return 1;
    int ans=1;
    int max_diff=arr[n-1]-arr[0];
    for(int k=min_diff;k<=max_diff;k++){
        ans=max(ans,helper(k,arr));
    }
    return ans;
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

   

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(arr);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
5
4 7 1 5 3


// output1:
4



Input2:
5
12 12 12 15 10

// output 2:
3


input3:
7
18 26 18 24 20 22

output:
5

input4:

output: 



*/