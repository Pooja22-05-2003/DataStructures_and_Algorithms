// TC=O(3*N)==O(N)
// SC=O(2*N)==O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n) {
       
     //  prefix array will contain the sum from index 1 to n
     int sum=0;
     unordered_map<int,int> map;
     vector<int> prefix(n+1);
     for(int i=1;i<=n;i++){
        sum+=nums[i];
        prefix[i]=sum;
        map[sum]=i;
     }

    /*
    nums[i]=nums[j]=prefix[j]-prefix[i]  
    -- here u know 3 values, nums[j]✅ , nums[i]✅, prefix[j]✅,find prefix[i](and your jon will done)
    -- prefix[i]=prefix[j]-nums[j]
    -- if u will find prefix[i] in map then check one condition also that (nums[i]==nums[j])? if yes then count increment in the answer.

    g = pj - pi - cj  ( g is the focus_sum)
    pi=pj-g-cj
    pi=pj-cj-cj
    pi=pj-2*cj
    */
   int ans=0;
   for(int j=3;j<=n;j++){
    int findEl=prefix[j]-(2*nums[j]);
    if(map.find(findEl)!=map.end() && nums[j]==nums[map[findEl]])  ans++;
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
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n);
}






/*

input :
5
9 3 3 3 9

output :
2

input 2:
7
27 9 3 3 3 9 27

output :
3

*/



