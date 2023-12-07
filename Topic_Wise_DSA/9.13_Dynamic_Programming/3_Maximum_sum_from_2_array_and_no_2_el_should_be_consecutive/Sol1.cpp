

// TC=O(N)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr1 ,vector<int> &arr2, int n ){
 
  
    int dp[n+1];
      memset(dp,0,n+1);
    
   
    dp[1]=max(0,max(arr1[1],arr2[1]));
 
    dp[2]=max(dp[1], max(arr1[2],arr2[2]));
   

    for(int i=3;i<=n;i++){
       int opt1=dp[i-2]+max(arr1[i],arr2[i]);
       int opt2=dp[i-1];
       dp[i]=max(opt1,opt2);
    }
 
    return dp[n];

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********
    // 1-- based indexing are used here

    int n;
    cin >> n ;
    
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
   
        cin>>arr1[i];
    }

   
    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }

  
    cout<<solve(arr1,arr2,n)<<endl;
}






/*
input :
4
1 5 3 21234
-4509 200 3 40

output :
21434
*/
