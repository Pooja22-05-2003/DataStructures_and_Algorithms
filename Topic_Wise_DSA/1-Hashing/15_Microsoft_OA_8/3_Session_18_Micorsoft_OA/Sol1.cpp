// TC=O(2N)==O(N)
// SC=O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A , int n , int x , int y){
   int ans=INT_MAX;

//    Optimization using prefix sum using (hashing)
   vector<int> prefix (n+1);

   // prefix[i]- it will tell u the sum from of arr[i]+arr[i-y]+arr[i-2y]-----arr[1];
   // prefix[i]=prefix[i-y]+arr[i]
   for(int i=1;i<=n;i++){
      if(i-y>=1) prefix[i]=prefix[i-y]+A[i];
      else prefix[i]=A[i];
   }

   //  now we want exactly x elements sum , but prefix[i]=contain sum from 1 to i
   
   // for(int i=1;i<=n;i++){
   //    int sum;

   // This way is wrong ---------
   //    if((i-((x)*2y))>=1) sum=prefix[i]-prefix[i-((x+1)*y)];
   //    else sum=prefix[i];

   //    ans=min(ans,sum);
      
   // }

      
    int  k = INT_MAX ; 
    for( int  i=1;i<=n;i++){
        
       int index = i - (x-1)*y;
        if(index>=1){
            int g = prefix[i] ; 
            if(index-y>=1){
                g = g - prefix[index-y] ; 
            }
            k = min(g,k);
          
        }
    }

   return k;
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



