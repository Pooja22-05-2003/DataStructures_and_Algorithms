/*
Brute Force Approach :
1. Iterate through all the subarrays, and find the minimum of all the subarray and return the sum.


*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            int minn=arr[i];
            for(int j=i;j<arr.size();j++){
                // int minn=INT_MAX;
                // for(int k=i;k<=j;k++){
                //     minn=min(minn,arr[k]);
                // }
                minn=min(minn,arr[j]);
                sum=sum%(1000000007);
                sum+=minn;
            }
        }

        return sum;
    }
};