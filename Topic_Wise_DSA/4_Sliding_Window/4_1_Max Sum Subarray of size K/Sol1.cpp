// TC=O(N)
// SC=O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A ,int n , int k ){
    int maxSum=INT_MIN;
    int sum=0;
    int i=1;
    int j=1;
    while(j<=n){
        if(j-i+1==k){
            sum+=A[j];
            maxSum=max(maxSum ,sum );
            sum-=A[i];
            i++;
            j++;
        }
        else if (j-i+1<k){
            sum+=A[j];
            j++;
        }
        // else i--;

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
    // 1-- based indexing are used here

    int n;
    cin >> n ;
    
    int k;
    cin>>k;
    vector<int> arr1(n+1);


    for(int i=1;i<=n;i++){
   
        cin>>arr1[i];

    }


    int target;
    cin>>target;
  
    cout<<solve(arr1,n , k)<<endl;
}






/*
input :
4
2
100 200 300 400

output :
700


*/




