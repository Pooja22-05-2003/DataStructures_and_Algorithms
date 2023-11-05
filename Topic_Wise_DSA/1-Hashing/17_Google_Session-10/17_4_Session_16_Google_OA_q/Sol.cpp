// TC=O(N2)
// SC=O(2N)==O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A , int n){
   //  Optimaztion using hashing  
   int count=0;
   // Create prefix array for the first condition(A[i] >A[j])--> Why prefix and not suffic??? --- >
   // --> because at the jth index u need the answer of the previous pairs which satisfy this condition(A[i] >A[j])   --> So we need previous answers.
   vector<int> prefix(n+1,0);

   for(int i=1;i<=n;i++){
      int j=i-1;
      int cnt=0;
      while(j>=1){
         if(A[i] >A[j]) cnt++;
         j--;
      }

      prefix[i]=cnt;
   }


   // main condition:A[i] >A[j]< A[k] such that i < j < k ; 
   vector<int> suffix(n+1,0);

   for(int j=n;j>=1;j--){
      int k=j+1;
      int cnt=0;
      while(k<=n){
         if(A[j]<A[k]) cnt++;
         k++;
      }

      suffix[j]=cnt;
   }

   int ans=0;
   for(int j=1;j<=n;j++){
      ans+=prefix[j]*suffix[j];
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

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    

    cout<<solve(arr,n);

}






/*

input :
6
8 1 2 3 4 5


output :
10

*/



