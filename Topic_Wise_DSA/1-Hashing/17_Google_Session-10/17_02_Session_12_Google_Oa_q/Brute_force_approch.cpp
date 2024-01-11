// TC=O(N^2)
// SC= O(1)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&A , int n ){
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(A[A[A[i]]]=A[A[A[j]]]) count++;
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




