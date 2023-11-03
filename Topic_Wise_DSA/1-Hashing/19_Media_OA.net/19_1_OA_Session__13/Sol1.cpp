// TC=O(N)
// SC= O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&A , int n , int k ){
   vector<int> prefix(n+1,0);
   vector<int> suffix(n+2,0);
   
   for(int i=1;i<=n;i++){
      prefix[i]=prefix[i-1]+A[i];
   }
   for(int i=n;i>=1;i--){
      suffix[i]=suffix[i+1]+A[i];
   }


   int maxSum=0;

   int i=0;
   while(i<=k){
      int j=(n-k)+(i+1);
      int sum=prefix[i]+suffix[j];
      maxSum=max(maxSum,sum);

      i++;
   }

   return maxSum;



}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********
   int N;
   cin>>N;
    int i=1;
   while(i<=N){
    int n ;
    cin>>n;
    int k;
    cin>>k;
     vector<int>arr(n+1);
     for(int i=1;i<=n;i++){
     cin>>arr[i];
   }

      cout<<solve(arr,n,k);
    i++;
   }


}






/*
input :
1
5
3
5 -2 3 1 2

 

output :
8

*/




