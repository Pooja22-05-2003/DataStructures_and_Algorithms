// TC=O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n , int x) {
    int maxSum=0;
    //  unordered_map will store the count correspsding to nums[i]%k

    // (nums[i]%k) + (nums[j]%k)=divisible by k

    // (nums[i]% x(known))+(nums[j](known)%x(known))=divisible by k
    //  so for the sum to be divisible by k , we need (k-(nums[i]%x)) to be divisible by k

    //  so both lhs and rhs will be equal means both are divisble by k




    unordered_map<int,int>map;
    int ans=0;
   for(int j=1;j<=n;j++){
    int findEl=x-(nums[j]%x);

    // x-0=0 , so for safety do mod one more time
    findEl=findEl%x;
    ans=ans+map[findEl];
    map[nums[j]%x]++;

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
    cin>>n;
    int x;
    cin>>x;
        vector<int> arr(n);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n,x);
}






/*

input :
5
60
31 25 85 29 35
output :
3

input 2:

output :


*/



