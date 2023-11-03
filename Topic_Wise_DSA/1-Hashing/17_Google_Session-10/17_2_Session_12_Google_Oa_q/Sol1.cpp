// TC=O(N)
// SC= O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&A , int n ){
    int count=0;
    unordered_map<int,int> Freq;
    for(int i=1;i<=n;i++){
       int LHS=A[A[A[i]]];
       count=count+Freq[LHS];

       int RHS=A[A[A[i]]];
       Freq[RHS]++;
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
   int N;
   cin>>N;
    int i=1;
   while(i<=N){
    int n ;
    cin>>n;
     vector<int>arr(n+1);
     for(int i=1;i<=n;i++){
     cin>>arr[i];
   }

      cout<<solve(arr,n);
    i++;
   }


}






/*
input :
1
4
4 2 1 2
 

output :
6

*/




