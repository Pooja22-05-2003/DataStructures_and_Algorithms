// TC=O(N2) -- in the worst case y can be 1 and x can be as large as n , so it will go to n2 complexity.
// SC=O(1)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A , int n , int x , int y){
   int ans=INT_MAX;

   int i=1;

   while(i<=n){
      //  for each index calculate x point at distance y rehabilitation cost
      //  maintain the minimum cost, return that minimum cost as final ans
      int j=i;
      int cnt=0;
      int sum=0;
      while(j<=n && cnt<=x){
         sum+=A[j];
         cnt++;
         j=j+y;
      }

      if(cnt==x){
         ans=min(ans,sum);
      }


      i++;
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
    int x,y;
    cin>>x;
    cin>>y;


    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    

    cout<<solve(arr,n,x,y);

}






/*

input :
7
2
2
1 5 8 1 4 5 8


output :
6

input 2:
7
2
2
9 5 8 9 4 5 8

output :
12

*/



