// TC=O(3*N)==O(N)
// SC=O(2*N)==O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n) {
       
    //     create prefix array . prefix[i]-it will tell the number of striclty incerasing subarray till index i

    vector<int> prefix(n);

    prefix[0]=1;
    for(int i=1;i<=n-1;i++){
        if(nums[i-1]<nums[i]) prefix[i]=prefix[i-1]+1;
        else prefix[i]=1;
    }


    //      create suffix array . suffix[i]-it will tell the number of striclty decreasing subarray till index i
    vector<int> suffix(n);
    suffix[n-1]=1;
    for(int j=n-2;j>=0;j--){
         if(nums[j+1]<nums[j]) suffix[j]=suffix[j+1]+1;
        else suffix[j]=1;
    }

    // for(auto it : prefix) cout<< it<<",";
    // for(auto it : suffix) cout<< it<<",";

    //  At any index i, if we want to calculate number of mountain subarrays. it's formula will be 
    // ans+=prefix[i-1]*suffix[i+1];
    int ans=0;
    for(int k=1;k<=n-2;k++){
        ans+=(prefix[k-1])*(suffix[k+1]);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n);
}






/*

input :
5
1 2 3 1 1


output :
8

input 2:


output :


*/



