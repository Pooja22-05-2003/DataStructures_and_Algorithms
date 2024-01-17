/*
Approach :

*/
// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>arr){
    vector<int> dp(n+1,1);

    // hash the element and if there are more than 2 occurence then store the last of that el,
    unordered_map<int,int>mp;
    mp[arr[1]]=1;
    int i=2;
    while(i<=n){
        // int j=i-1;
        // while(j>=1){
        //     if((arr[j]*3)==arr[i]){
        //         // at each iteration we are taking max because there can be more than 1 occurence of the element.
        //         dp[i]=max(dp[i],1+dp[j]);
        //     }
        //     j--;
        // }

        if(arr[i]%3==0){
            int search_el=arr[i]/3;
            if(mp.find(search_el)!=mp.end()){
                int ind=mp[search_el];
                dp[i]=max(dp[i],1+dp[ind]);
            }
            mp[arr[i]]=max(mp[arr[i]],i);
        }
        i++;
    }

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

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
 
    int ans=solve(n,arr);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
5
1 5 15 3 9


// output1:
3


Input2:
7
1 5 15 3 9 27 81

// output 2:
5

input3:


output:


input4:

output: 



*/