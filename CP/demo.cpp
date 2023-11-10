// TC=O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n , int k) {

    int ans=INT_MIN;

    unordered_map<int,int> map; // this will store the el with its index
    vector<int> prefix(n+1);  // it will store the sum till i index
    prefix[1]=nums[1];
    map[nums[1]]=1;
    for(int i=2;i<=n;i++){
        //  here chech one condition , if there are more than one same el, then maintain the smallest index
        // ......corresponding to that el.

        if(map.find(nums[i])!=map.end()){
            map[nums[i]]=min(i,map[nums[i]]);
        }
        map[nums[i]]=i;
        prefix[i]=prefix[i-1]+nums[i];
    }


    for(int i=1;i<=n;i++){
        int el1=nums[i]-k;
        int el2=nums[i]+k;
        if(map.find(el1)!=map.end()){
            int subarraysum=prefix[i]-prefix[map[el1]-1];
            ans=max(ans,subarraysum);
            

        }
        if(map.find(el2)!=map.end()){
             int subarraysum=prefix[i]-prefix[map[el2]-1];
            ans=max(ans,subarraysum);
        }
        
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
    int k;
    cin>>k;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n,k);
}






/*

input :
8
5
1 5 -5 8 8 8 10 15


output :
34

input 2:


output :


*/



