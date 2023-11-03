// TC=O(2N)==O(N)
// SC= O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr , int n , int k){
    int b[200009]={0};

    int i=1;
    while(i<=n){
        int lower_range=arr[i]-k;
        int upper_range=arr[i]+k;

        //  range updation technique applied here , it will be done in O(1) 
        // for each element range updation
        b[lower_range]=b[lower_range]+1;
        b[upper_range+1]=b[upper_range+1]-1;

        i++;
    }

    //  minimum 1 length of the subsequence can be the legnth of the (subsequence having same element)
    int ans=1;
    int j=1;
    while(j<=200002){
        b[j]=b[j-1]+b[j];
        ans=max(ans,b[j]);
        j++;
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
   int n,k;
   cin>>n>>k;
   vector<int>arr(n+1);
   for(int i=1;i<=n;i++){
    cin>>arr[i];
   }

    cout<<solve(arr,n,k);
}






/*
input :
5 
3 
4 5 8 10 15 

output :
4

*/




