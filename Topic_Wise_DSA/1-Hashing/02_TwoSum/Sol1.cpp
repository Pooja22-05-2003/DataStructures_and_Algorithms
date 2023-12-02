#include <bits/stdc++.h>
using namespace std;
// TC=O(N)
// SC=O(N)

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>Map;

        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int findEl=target-curr;
            if(Map.find(findEl)!=Map.end()){
                return {i,Map[findEl]};
            }
            Map[curr]=i;
        }

        return {-1,-1};

    }

int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********

    int n;
    cin >> n ;
    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin>>target;

    vector<int>ans=twoSum(arr, target);
    cout<<ans[0]<<" "<< ans[1];
}