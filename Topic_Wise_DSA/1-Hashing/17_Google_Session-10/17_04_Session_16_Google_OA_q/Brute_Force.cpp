// TC=O(N3)
// SC=O(1)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A , int n){
   //  Brute force 
   int count=0;
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         for(int k=j+1;k<=n;k++){
            if(A[i] >A[j]  && A[j]< A[k] )  count++;
         }
      }
   }

   return count;


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



