// TC=O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n , int k) {

    unordered_map<int,int>mp;
    unordered_map<int,int>vis;
    // for(auto it :nums){
    //     vis[it]=0;
    // }
    int ans=0;
    for(int i=1;i<=n;i++){
        // a+k=b
        // b is the current el
        // so u need to find (b-k) in the map, and make the pair(if one of them or both of them are not visited)
        int findEl=nums[i]-k;
        if(mp.find(findEl)!=mp.end()){
            //  check the visited condition
            int firstEl=nums[i];
            int secondEl=findEl;

            if(vis[firstEl]==0 || vis[secondEl]==0){
 
               
                ans++;
                vis[firstEl]=1;
                vis[secondEl]=1;

            }

            //  here also u need to mark the el in the map
             mp[nums[i]]++;
        }

        else {
            mp[nums[i]]++;
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
    int x;
    cin>>x;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n,x);
}






/*

input :
4
1
1 1 1 2


output :
1 ({2,1})

input 2:
6
1
1 1 1 2 2 3

output :
2
pairs {(1,2), (2,3)}

*/



