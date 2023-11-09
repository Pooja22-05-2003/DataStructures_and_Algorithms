/*
Approach:
1. Check all the subarrays pair using i and j pointer and the subarray which satisfy this condition
the sum of that subarray(excluding the first and last number)=first number = last number [ do count++]

2. Return count as our final ans.
*/

// TC=O(3*N)==O(N)
// SC=O(2*N)==O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n) {
       

    int count=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum+=nums[j];
            //  foucs sum = sum-(nums[i]+nums[j]) , as in the condition it was given that subbarray of range 
            // [l to r] sum must be from [l+1 to r-1]

            int focus_sum=sum-(nums[i]+nums[j]);
            if(nums[i]==nums[j]  && focus_sum==nums[i]){
                // cout<<"i:"<<i<<" j:"<<j<<endl;
                // cout<<"sum:"<<sum<<"focus_sum:"<<focus_sum<<endl;
                count++;
            }
        }
    }
    return count;

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
i:1 j:5
sum:27focus_sum:9
i:2 j:4
sum:9focus_sum:3
2

input 2:


output :


*/



