
/*
Approach :

hasmap(bst) will store the best ans for element i
*/
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

  int solve(int k,vector<int>& arr) {
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
            cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
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

    int k;
    cin>>k;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(k,arr);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
7
100
100 4 5 6 7 200 8 


// output1:
2

i:2 dp[i]:1
i:3 dp[i]:1
i:4 dp[i]:1
i:5 dp[i]:1
i:6 dp[i]:2
i:7 dp[i]:1
2

Input2:
7
1
100 4 5 6 7 200 8 

// output 2:
i:2 dp[i]:1
i:3 dp[i]:2
i:4 dp[i]:3
i:5 dp[i]:4
i:6 dp[i]:1
i:7 dp[i]:5
5


input3:


output:


input4:

output: 



*/