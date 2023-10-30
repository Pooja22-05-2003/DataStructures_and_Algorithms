// TC=O(N)
// SC=O(N)
class Solution {
public:

    int solve(vector<int>&Arr, int N, int k)
    {
        // code here
        int ans=0;
        unordered_map<int,int> PrefixSum;
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=Arr[i];

            if(sum==k) ans++;
            ans+=PrefixSum[sum-k];
            PrefixSum[sum]++;
          
        }
        
        
        
        
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> arr;
        for(auto it : nums){
            if(it%2==0) arr.push_back(0);
            else arr.push_back(1);
        }

        return solve(arr,arr.size(),k);
    }
};