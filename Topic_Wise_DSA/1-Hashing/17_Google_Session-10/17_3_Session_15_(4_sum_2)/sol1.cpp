// TC=O(N2)
// SC=O(N)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        /*
        Most Optimized Problem
        1. hash the first two array sum (converting the problem to 2 sum problem)
        2. Then using two pointer (2 for loops) compute the sum , whether u are able to 
        find the sum 0. If yes, then increase the count.
        3. After all possible iteration return the final count as answer.
        */

        unordered_map<int,int> Map;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int sum=nums1[i];
            for(int j=0;j<n;j++){
            sum+=nums2[j];
            Map[sum]++;
            sum-=nums2[j];
            }
        }
        //  now iterate through the remaining 2 arrays
        int ans=0;
        for(int i=0;i<n;i++){
           int sum=nums3[i];
            for(int j=0;j<n;j++){
            sum+=nums4[j];
            if(Map.find(-(sum))!=Map.end()) ans+=Map[-sum];
            sum-=nums4[j];
            }
        }

        return ans;
    }
};