/*
Approach :

*/
// TC=O(N2)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>arr){
    vector<int> dp(n+1,1);
    int i=2;
    while(i<=n){
        int j=i-1;
        while(j>=1){
            if((arr[j]*3)==arr[i]){
                // at each iteration we are taking max because there can be more than 1 occurence of the element.
                dp[i]=max(dp[i],1+dp[j]);
            }
            j--;
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