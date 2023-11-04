// TC=O(N)
// SC=O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A ,vector<int> &B,int n , int target){
   //  Brute force 
   int ans=INT_MIN;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         int sum=A[i]+B[j];
         if(sum<=target){
            ans=max(ans,sum);
         }
      }
   }

   return ans;

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
    vector<int> arr2(n+1);

    for(int i=1;i<=n;i++){
   
        cin>>arr1[i];

    }

    
    for(int i=1;i<=n;i++){
        cin>>arr2[i];

    }
    int target;
    cin>>target;
  
    cout<<solve(arr1,arr2,n,target)<<endl;
}






/*
input :
4
1 4 5 7 
10 20 30 40 
36

output :
35

*/



