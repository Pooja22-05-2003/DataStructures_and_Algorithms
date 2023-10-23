/*
TC=O(N)
SC=O(N)

using count sort
-> As the constraints are too low [1 <= nums[i] <= 100], so we can take one array of that size 
-> Iterate through the array and add the freuquence of el   ans+= f[i-k]+f[i+k] and at each iteration , increment the frequency of that el
-> return ans


*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int ans=0;
        for(auto i : nums){
            ans+=freq[i-k]+freq[i+k];
            freq[i]++;
        }

        return ans;
    }
};


